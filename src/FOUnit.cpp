/*
 * FOUnit.cpp
 *
 *  Created on: 26-Sep-2016
 *      Author: ashish
 */
#include "FOUnit.h"
FOUnit::FOUnit(std::shared_ptr<spdlog::logger> logger) { this->vollogger = logger; }
FOUnit::FOUnit(const FOUnit* f) { this->vollogger = f->vollogger; }
FOUnit::FOUnit(const FOUnit* f, std::shared_ptr<spdlog::logger> logger) {
  this->call = f->call;
  this->future = f->future;
  this->put = f->put;
  this->spot = f->spot;
  this->vollogger = logger;
}
FOUnit::FOUnit(const FOUnit& f, std::shared_ptr<spdlog::logger> logger) {
  this->call = f.call;
  this->future = f.future;
  this->put = f.put;
  this->spot = f.spot;
  this->vollogger = logger;
}
void FOUnit::calculate() {
  // Do sense Check and then calculate the IV value
  for (auto& e : future) {
    std::cout << "Calculating for index" << e.first;
    auto fut = e.second;
    auto it = call.find(e.first);
    std::vector<std::shared_ptr<Underlying::Option>> c, p;
    if (it != call.end()) {
      c = it->second;
    }
    it = put.find(e.first);
    if (it != put.end()) {
      p = it->second;
    }
    if (!c.empty() && !p.empty()) {
      // Carry on the calculations
      using namespace Underlying;
      for (auto a : c) {
        a->calculateIV(fut.get());
        vollogger->info("{}", *a);
      }
      for (auto a : p) {
        a->calculateIV(fut.get());
        vollogger->info("{}", *a);
      }
    }
  }
}

double FOUnit::atmIV() { return _atmiv; }

void FOUnit::setAtmIV() {}
