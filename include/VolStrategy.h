/*
 * VolStrategy.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef VOLSTRATEGY_H_
#define VOLSTRATEGY_H_
#pragma once
#include <boost/date_time/posix_time/ptime.hpp>
#include <string>
#include <vector>
#include "ClosingPrice-odb.hxx"
#include "ClosingPrice.h"
#include "Connection.h"
#include "EsteeMaster-odb.hxx"
#include "EsteeMaster.h"
#include "EsteeMasterArchive-odb.hxx"
#include "EsteeMasterArchive.h"
#include "FOUnit.h"
class VolStrategy {
 public:
  VolStrategy(){};
  VolStrategy(const std::string& config = "config/config.json");
  void getUnderlyingData();
  void getAllData();
  void calculate();
  odb::result<closingPrice> getData(std::string esteeID, btime::ptime startdate, btime::ptime enddate);
  void Initialise();
  void initialiseLogger();
  std::shared_ptr<Connection> con;
  std::shared_ptr<spdlog::logger> logger;
  std::shared_ptr<spdlog::logger> archivelogger;
  std::shared_ptr<spdlog::logger> vollogger;

 private:
  std::vector<btime::ptime> listOfExpiries;
  std::map<btime::ptime, std::shared_ptr<FOUnit>> mDateFOUnit;
  std::string esteeId;
  btime::ptime startdate;
  btime::ptime enddate;
};

#endif /* VOLSTRATEGY_H_ */
