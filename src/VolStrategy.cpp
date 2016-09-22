/*
 * VolStrategy.cpp
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#include "VolStrategy.h"
#include "eaCommon.h"
#include "eaPercentile.h"
#include "eaBlackScholes.h"
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <spdlog/fmt/ostr.h>
namespace ms=odb::mssql;
using namespace odb::core;
using odb::database;
using odb::transaction;
namespace data{
template<typename T>
void getData(const std::shared_ptr<ms::database> db,const odb::query<T>& statement,odb::result<T> &res){
	try{
		res=db->query<T>(statement);
	}catch(std::exception& e){
		std::cout<<e.what();
	}
}

}
VolStrategy::VolStrategy(const std::string& path){
	con=std::shared_ptr<Connection>(new Connection(path));
	esteeId=con->getConfig()->esteeID();
	startdate=con->getConfig()->startdate();
	enddate=con->getConfig()->enddate();
	logger=con->getConfig()->log();
	archivelogger=con->getConfig()->archivelog();
}
odb::result<closingPrice> VolStrategy::getData(std::string esteeID,btime::ptime startdate,btime::ptime enddate){
	typedef odb::query<closingPrice> query;
	typedef odb::result<closingPrice> result;
	result res,data;
	query q(query::id.Estee_ID==esteeID &&
			query::id.Date>=startdate &&
			query::id.Date <= enddate);
	data::getData<closingPrice>(con->getConnection(),q,res);
	data=std::move(res);
	for(auto r=res.begin();r !=res.end();++r){
		std::cout<<r->_id.Estee_ID<<":"<<r->_id.Date<<std::endl;
	}
	return data;
}

void VolStrategy::getUnderlyingData(){
	typedef odb::query<closingPrice> query;
	typedef odb::result<closingPrice> result;
	result res;
	transaction t(con->getConnection()->begin());
	//t.tracer (stderr_tracer);
	query q(query::id.Estee_ID==esteeId &&
			query::id.Date>=startdate &&
			query::id.Date <= enddate);
	data::getData<closingPrice>(con->getConnection(),q,res);
	for(auto r=res.begin();r !=res.end();++r){
		std::cout<<r->_id.Estee_ID<<":"<<r->_id.Date<<std::endl;
	}
	t.commit();
}

void VolStrategy::getAllData(){
	typedef odb::query<EsteeMaster_Archive> masterquery;
	typedef odb::result<EsteeMaster_Archive> masterresult;
	typedef odb::query<closingPrice> pricequery;
	typedef odb::result<closingPrice> priceresult;
	transaction t(con->getConnection()->begin());
	t.tracer (stderr_tracer);
	masterresult res;
	masterquery q(masterquery::UnderlyingEstee_Id==esteeId &&
			masterquery::Expiry_Date >=startdate &&
			masterquery::Expiry_Date <=enddate &&
			masterquery::Security_Type.in(eaSecurityType::INDEXSPOT,
					eaSecurityType::INDEXFUTURES,
					eaSecurityType::INDEXCALL,
					eaSecurityType::INDEXPUT)+"ORDER BY"+masterquery::Security_Type);
	data::getData<EsteeMaster_Archive>(con->getConnection(),q,res);
	for(EsteeMaster_Archive &a:res){
		if(((std::find(listOfExpiries.begin(),listOfExpiries.end(),a.Expiry_Date)==listOfExpiries.end()) &&
				!a.Expiry_Date.is_not_a_date_time()))
			listOfExpiries.push_back(a.Expiry_Date);
	}
	std::sort(listOfExpiries.begin(),listOfExpiries.end());
	for(EsteeMaster_Archive &a:res){
		archivelogger->info("{}",a);
		pricequery querydata(pricequery::id.Estee_ID==a.getEsteeID() &&
				pricequery::id.Date >=startdate &&
				pricequery::id.Date <=enddate &&
				pricequery::Open_Interest > 0 &&
				pricequery::Volume > 0 );
		priceresult priceres;
		int index=0;

		std::shared_ptr<FOUnit> unit;
		data::getData<closingPrice>(con->getConnection(),querydata,priceres);
		for (closingPrice &r:priceres){
			logger->info("{}",r);
			if(a.Security_Type!=eaSecurityType::INDEXSPOT){
				//Calculate the index
				index=[&listOfExpiries,r]{auto i=std::lower_bound(listOfExpiries.begin(),listOfExpiries.end(),
						r._id.Date);
				auto b=std::find(listOfExpiries.begin(),listOfExpiries.end(),a.Expiry_Date);

					return std::distance(i,b);
				};

			}
			if(mDateFOUnit.find(r._id.Date)==mDateFOUnit.end()){
				unit=std::make_shared<FOUnit>(new FOUnit());
				mDateFOUnit.insert(std::make_pair(r._id.Date,unit));
			}else{
				unit=mDateFOUnit[r._id.Date];
			}

			switch(a.Security_Type){
			case 4:
				unit->spot=std::unique_ptr<Spot>(new Spot(r,a));
				break;
			case 5:
				unit->future=std::unique_ptr<Spot>(new Future(index,r,a));
				break;
			case 6:
				unit->call=std::unique_ptr<Spot>(new Option(index,r,a));
				break;
			case 7:
				unit->put=std::unique_ptr<Spot>(new Option(index,r,a));
				break;
			default:
				break;
			}

		}

	}
	t.commit();

}
void VolStrategy::getOptionData(){
	/*
	typedef odb::query<closingPrice> query;
	typedef odb::result<closingPrice> result;*/
}


