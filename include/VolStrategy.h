/*
 * VolStrategy.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef VOLSTRATEGY_H_
#define VOLSTRATEGY_H_
#pragma once
#include <string>
#include <boost/date_time/posix_time/ptime.hpp>
#include <vector>
#include "EsteeMaster-odb.hxx"
#include "EsteeMaster.h"
#include "EsteeMasterArchive-odb.hxx"
#include "EsteeMasterArchive.h"
#include "Connection.h"
#include "ClosingPrice-odb.hxx"
#include "ClosingPrice.h"
class VolStrategy{
public:
	VolStrategy(){};
	VolStrategy(const std::string& config="config/config.json");
	 void getUnderlyingData();
	 void getOptionData();
	 void getAllData();
	 odb::result<closingPrice> getData(std::string esteeID,btime::ptime startdate,btime::ptime enddate);
	 std::shared_ptr<Connection> con;
	 std::shared_ptr<spdlog::logger> logger;
private:
	std::vector<btime::ptime> listOfExpiries;
	std::vector<std::shared_ptr<closingPrice>> listOfClosingPriceUnderlying;
	std::vector<std::shared_ptr<closingPrice>> listOfClosingPriceFuture;
	std::vector<std::shared_ptr<closingPrice>> listOfClosingPriceCall;
	std::vector<std::shared_ptr<closingPrice>> listOfClosingPricePut;
	std::string esteeId;
	btime::ptime startdate;
	btime::ptime enddate;

};



#endif /* VOLSTRATEGY_H_ */
