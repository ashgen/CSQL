/*
 * FOUnit.cpp
 *
 *  Created on: 26-Sep-2016
 *      Author: ashish
 */
#include "FOUnit.h"
FOUnit::FOUnit(const FOUnit* f) {
  this->call = f->call;
  this->future = f->future;
  this->put = f->put;
  this->spot = f->spot;
}
FOUnit::FOUnit(const FOUnit& f) {
  this->call = f.call;
  this->future = f.future;
  this->put = f.put;
  this->spot = f.spot;
}
void FOUnit::calculate() {
  // Do sense Check and then calculate the IV value
  for (auto& e : future) {
    std::cout << "Calculating for index" << e.first;
    auto fut = e.second;
    auto it = call.find(e.first);
    auto c = it == call.end() ? nullptr : it->second;
    it = put.find(e.first);
    auto p = it == put.end() ? nullptr : it->second;
    if (c != nullptr && p != nullptr) {
      // Carry on the calculations
      c->calculateIV(fut.get());
      p->calculateIV(fut.get());
    }
  }
}
