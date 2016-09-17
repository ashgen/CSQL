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
#include "EsteeMasterArchive-odb.hxx"
#include "EsteeMasterArchive.h"
#include "Connection.h"

class VolStrategy{
public:
	VolStrategy(){};
	VolStrategy(const std::string& config='config/config.json');
	 void getUnderlyingData();
	 void getFutureData();
	 void getOptionData();
	 std::shared_ptr<Connection> con;
private:
	std::vector<closingPrice*> listOfClosingPriceUnderlying;
	std::vector<closingPrice*> listOfClosingPriceFuture;
	std::vector<closingPrice*> listOfClosingPriceOption;
	std::string esteeId;
	btime::ptime startdate;
	btime::ptime enddate;

};



#endif /* VOLSTRATEGY_H_ */
