/*
 * config.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_
#include <json/json.h>
#include <spdlog/spdlog.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <fstream>
#include <iostream>
#include <string>
#define ASYNC_SIZE 1048576

namespace btime = boost::posix_time;
class config {
 public:
  config() {}
  config(const config& c) {}
  config(const std::string& path);
  void ReadConfigXML(const std::string& config);
  std::string user() const;
  std::string host() const;
  std::string password() const;
  std::string database() const;
  std::string esteeID() const;
  btime::ptime startdate() const;
  btime::ptime enddate() const;
  std::shared_ptr<spdlog::logger> log();
  std::shared_ptr<spdlog::logger> archivelog();
  std::shared_ptr<spdlog::logger> vollog();

 private:
  std::string _host;
  std::string _user;
  std::string _password;
  std::string _database;
  std::string _logfile;
  std::string _archivelogfile;
  std::string _vollogfile;
  std::shared_ptr<spdlog::logger> logger;
  std::shared_ptr<spdlog::logger> archivelogger;
  std::shared_ptr<spdlog::logger> vollogger;
  std::string _esteeID;
  btime::ptime _startdate;
  btime::ptime _enddate;
};

#endif /* INCLUDE_CONFIG_H_ */
