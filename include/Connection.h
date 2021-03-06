/*
 * Connection.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_CONNECTION_H_
#define INCLUDE_CONNECTION_H_
#pragma once
#include <spdlog/spdlog.h>
#include "config.h"
#include "database.h"
class Connection {
 public:
  Connection(){};
  Connection(const Connection& c){};
  Connection(const std::string& path = "config/config.json");
  std::shared_ptr<odb::database> getConnection();
  std::shared_ptr<config> getConfig();

 private:
  std::shared_ptr<config> configuration;
  std::shared_ptr<odb::database> db;
};

#endif /* INCLUDE_CONNECTION_H_ */
