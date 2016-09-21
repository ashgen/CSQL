/*
 * config.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_CONFIG_H_
#define INCLUDE_CONFIG_H_
#include <string>
#include <spdlog/spdlog.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <json/json.h>
#include <fstream>
#include <iostream>
#define ASYNC_SIZE 1048576

namespace btime=boost::posix_time;
class config{
public:
	config(){
	}
	config(const config& c){
	}
	config(const std::string& path){
		ReadConfigXML(path);
	}
	void ReadConfigXML(const std::string& config) {
		std::ifstream ifs(config);
		Json::Reader reader;
		Json::Value val;
		Json::Value conSetting;
		Json::Value loggerSetting;
		Json::Value stratSetting;
		reader.parse(ifs,val);
		try{

			conSetting=val["connection"];
			loggerSetting=val["logger"];
			stratSetting=val["strategy"];
			//For connection Settings
			_host=conSetting["host"].asString();
			//host=conSetting.get("host","").asString();
			_user=conSetting["user"].asString();
			_password=conSetting["password"].asString();
			_database=conSetting["database"].asString();

			_logfile=loggerSetting["logfile"].asString();
			spdlog::set_async_mode(ASYNC_SIZE);
			logger=spdlog::rotating_logger_mt("file_logger", _logfile, ASYNC_SIZE* 5, 3);
			spdlog::set_level(spdlog::level::info);
			//Parse Data Configuration
			_esteeID=stratSetting["esteeid"].asString();
			_startdate=btime::time_from_string(stratSetting["startdate"].asString());
			_enddate=btime::time_from_string(stratSetting["enddate"].asString());
			std::cout<<_startdate<<":"<<_enddate<<std::endl;

		}catch (const Json::Exception& e){
			std::cout<<e.what()<<std::endl;
		}catch (const std::exception& e){
			std::cout<<e.what();
		}catch (const boost::exception& e){
			std::cout<<"Error parsing date";
		}
	}
	std::string user() const{
		return _user;
	}
	std::string password() const{
		return _password;
	}
	std::string host() const{
		return _host;
	}
	std::string database() const{
		return _database;
	}
	std::string esteeID() const{
		return _esteeID;
	}
	btime::ptime startdate() const{
		return _startdate;
	}
	btime::ptime enddate() const{
		return _enddate;
	}
	std::shared_ptr<spdlog::logger> log(){
		return logger;
	}

private:
	std::string _host;
	std::string _user;
	std::string _password;
	std::string _database;
	std::string _logfile;
	std::shared_ptr<spdlog::logger> logger;
	std::string _esteeID;
	btime::ptime _startdate;
	btime::ptime _enddate;


};




#endif /* INCLUDE_CONFIG_H_ */
