/*
 * FOUnit.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_FOUNIT_H_
#define INCLUDE_FOUNIT_H_
#include "Option.h"

class FOUnit {
 public:
  FOUnit(){};
  FOUnit(const FOUnit*);
  FOUnit(std::shared_ptr<spdlog::logger> logger);
  FOUnit(const FOUnit&, std::shared_ptr<spdlog::logger>);
  FOUnit(const FOUnit*, std::shared_ptr<spdlog::logger>);
  std::shared_ptr<Underlying::Spot> spot;
  std::unordered_map<int, std::shared_ptr<Underlying::Future>> future;
  std::unordered_map<int, std::vector<std::shared_ptr<Underlying::Option>>> call;
  std::unordered_map<int, std::vector<std::shared_ptr<Underlying::Option>>> put;
  std::shared_ptr<spdlog::logger> vollogger;
  void calculate();
  double atmIV();
  void setAtmIV();

 private:
  double _atmiv;
};

#endif /* INCLUDE_FOUNIT_H_ */
