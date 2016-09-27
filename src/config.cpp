/*
 * config.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */
#include "config.h"

config::config(const std::string& path) { ReadConfigXML(path); }
void config::ReadConfigXML(const std::string& config) {
  std::ifstream ifs(config);
  Json::Reader reader;
  Json::Value val;
  Json::Value conSetting;
  Json::Value loggerSetting;
  Json::Value stratSetting;
  reader.parse(ifs, val);
  try {
    conSetting = val["connection"];
    loggerSetting = val["logger"];
    stratSetting = val["strategy"];
    // For connection Settings
    _host = conSetting["host"].asString();
    // host=conSetting.get("host","").asString();
    _user = conSetting["user"].asString();
    _password = conSetting["password"].asString();
    _database = conSetting["database"].asString();

    _logfile = loggerSetting["logfile"].asString();
    _archivelogfile = loggerSetting["archivelogfile"].asString();
    _vollogfile = loggerSetting["vollogfile"].asString();
    spdlog::set_async_mode(ASYNC_SIZE);
    logger =
        spdlog::rotating_logger_mt("file_logger", _logfile, ASYNC_SIZE * 5, 3);
    archivelogger = spdlog::rotating_logger_mt(
        "archive_logger", _archivelogfile, ASYNC_SIZE / 1024, 3);
    vollogger = spdlog::rotating_logger_mt("vol_logger", _vollogfile,
                                           ASYNC_SIZE / 1024, 3);
    spdlog::set_level(spdlog::level::info);
    logger->set_pattern("%v");
    archivelogger->set_pattern("%v");
    // Parse Data Configuration
    _esteeID = stratSetting["esteeid"].asString();
    _startdate = btime::time_from_string(stratSetting["startdate"].asString());
    _enddate = btime::time_from_string(stratSetting["enddate"].asString());
    std::cout << _startdate << ":" << _enddate << std::endl;

  } catch (const Json::Exception& e) {
    std::cout << e.what() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what();
  } catch (const boost::exception& e) {
    std::cout << "Error parsing date";
  }
}
std::string config::user() const { return _user; }
std::string config::password() const { return _password; }
std::string config::host() const { return _host; }
std::string config::database() const { return _database; }
std::string config::esteeID() const { return _esteeID; }
btime::ptime config::startdate() const { return _startdate; }
btime::ptime config::enddate() const { return _enddate; }
std::shared_ptr<spdlog::logger> config::log() { return logger; }
std::shared_ptr<spdlog::logger> config::archivelog() { return archivelogger; }
