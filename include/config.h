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
#include <boost/date_time/posix_time/ptime.hpp>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
namespace btime=boost::posix_time;
class config{
public:
	config(){

	}
	config(const std::string& path){
		ReadConfigXML(path);
	}
	void ReadConfigXML(const std::string& config) const{
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
				host=conSetting["host"].asString();
				//host=conSetting.get("host","").asString();
				user=conSetting["user"].asString();
				password=conSetting["password"].asString();
				database=conSetting["database"].asString();

				logfile=loggerSetting["logfile"].asString();
				logger=spdlog::basic_logger_mt("basic_logger",logfile);
				//Parse Data Configuration
				esteeID=stratSetting["esteeid"].asString();
				startdate=btime::time_from_string(stratSetting["startdate"].asString());
				enddate=btime::time_from_string(stratSetting["enddate"].asString());

			}catch (const Json::Exception& e){
				std::cout<<e.what()<<std::endl;
			}catch (const std::exception& e){
				std::cout<<e.what();
			}catch (const boost::exception& e){
				std::cout<<"Error parsing date";
			}

	}
private:
	const std::string host;
	const std::string user;
	const std::string password;
	const std::string database;
	const std::string logfile;
	std::shared_ptr<spdlog::logger> logger;
	const std::string esteeID;
	const btime::ptime startdate;
	const btime::ptime enddate;


};




#endif /* INCLUDE_CONFIG_H_ */
