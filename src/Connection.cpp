/*
 * Connection.cpp
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */
#include "Connection.h"
#include "json/json.h"
#include <fstream>
#include <string>
std::shared_ptr<ms::database> Connection::getConnection(){
	if(db !=nullptr)
		return db;
	db=std::make_shared<ms::database>(configuration->user(),configuration->password(),
			configuration->database(),configuration->host());
	return db;
}
std::shared_ptr<config> Connection::getConfig(){
	return configuration;
}
Connection::Connection(const std::string& path){
	db=nullptr;
	configuration=std::make_shared<config>(path);
}


