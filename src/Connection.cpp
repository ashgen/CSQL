/*
 * Connection.cpp
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */
#include "Connection.h"
#include "jsoncpp/json/json.h"
#include <fstream>
#include <string>
std::unique_ptr<odb::database> Connection::getConnection() const{
	db=std::unique_ptr<odb::database>(new ms::database(config->user,config->password,config->database,config->host));
	return db;
}
Connection::Connection(const std::string& path){
	config=std::make_shared<::config>(new ::config(path));
}


