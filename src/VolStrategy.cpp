/*
 * VolStrategy.cpp
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#include "VolStrategy.h"
#include <odb/database.hxx>
#include <odb/transaction.hxx>

using namespace odb::core;
namespace data{
template<typename T>
odb::result<T>getData(const odb::database& db,const odb::query<T>& statement){
	try{
		transaction t(db->begin());
		odb::result<T> r(db->query<T>(statement));
		return r;
	}catch(std::exception& e){
		std::cout<<e.what();
	}
}

}
VolStrategy::VolStrategy(const string& path){
	con=std::shared_ptr<Connection>(new Connection(path));
	esteeId=con->config->esteeID;
	startdate=con->config->startdate;
	enddate=con->config->enddate;
}
void VolStrategy::getUnderlyingData(){
	typedef odb::query<person> query;
	typedef odb::result<person> result;

	query q(query::_ref(Estee_ID)==esteeId &&
			query::_ref(Date)>=startdate &&
			query::_ref(Date) <= enddate);
	result r=data::getData<closingPrice>(con->getConnection(),q);
}
void VolStrategy::getFutureData(){
	typedef odb::query<EsteeMasterArchive> query;
	typedef odb::result<EsteeMasterArchive> result;
	query q(query::UnderlyingEstee_Id==esteeId &&
			query::Expiry_Date >=startdate &&
			query::Expiry_Date <=enddate &&
			query::Security_Type=="5");
	result res=data::getData<closingPrice>(con->getConnection(),q);
	for (auto &r:res){
		std::cout<<r->getEsteeID()<<r->Expiry_Date<<std::endl;
	}

}
void VolStrategy::getOptionData(){
	typedef odb::query<person> query;
	typedef odb::result<person> result;
}


