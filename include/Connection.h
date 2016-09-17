/*
 * Connection.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_CONNECTION_H_
#define INCLUDE_CONNECTION_H_
#pragma once
#include <odb/database.hxx>
#include <odb/mssql/database.hxx>
#include <spdlog/spdlog.h>
#include "config.h"
namespace ms=odb::mssql;
class Connection{
public:
	Connection(){};
	Connection(const Connection& c){};
	Connection(const std::string& path="config/config.json");
	std::unique_ptr<odb::database> getConnection() const;

private:
	const std::shared_ptr<config> config;
	std::unique_ptr<odb::database> db;
};


#endif /* INCLUDE_CONNECTION_H_ */
