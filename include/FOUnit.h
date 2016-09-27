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
  FOUnit(const FOUnit&);
  FOUnit(const FOUnit*);
  std::shared_ptr<Underlying::Spot> spot;
  std::unordered_map<int, std::shared_ptr<Underlying::Future>> future;
  std::unordered_map<int, std::shared_ptr<Underlying::Option>> call;
  std::unordered_map<int, std::shared_ptr<Underlying::Option>> put;
  void calculate();
};

#endif /* INCLUDE_FOUNIT_H_ */
