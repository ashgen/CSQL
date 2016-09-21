/*
 * VolStrategy.cpp
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#include "VolStrategy.h"
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
	//t.tracer (stderr_tracer);
	masterresult res;
	masterquery q(masterquery::UnderlyingEstee_Id==esteeId &&
			masterquery::Expiry_Date >=startdate &&
			masterquery::Expiry_Date <=enddate &&
			masterquery::Security_Type.in(4,5,6,7));
	data::getData<EsteeMaster_Archive>(con->getConnection(),q,res);

	for(EsteeMaster_Archive &a:res){
		pricequery querydata(pricequery::id.Estee_ID==a.getEsteeID() &&
				pricequery::id.Date >=startdate &&
				pricequery::id.Date <=enddate);
		priceresult priceres;
		data::getData<closingPrice>(con->getConnection(),querydata,priceres);
		for (closingPrice &r:priceres){
			logger->info("{}",r);
			switch(a.Security_Type){
			case 4:
				listOfClosingPriceUnderlying.push_back(std::shared_ptr<closingPrice>(new closingPrice(r)));
				break;
			case 5:
				listOfClosingPriceFuture.push_back(std::shared_ptr<closingPrice>(new closingPrice(r)));
				break;
			case 6:
				listOfClosingPriceCall.push_back(std::shared_ptr<closingPrice>(new closingPrice(r)));
				break;
			case 7:
				listOfClosingPricePut.push_back(std::shared_ptr<closingPrice>(new closingPrice(r)));
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


