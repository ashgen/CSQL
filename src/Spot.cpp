/*
 * Spot.cpp
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */
#include "Spot.h"
using namespace Underlying;
Spot::Spot(const Spot& s) {
  this->esteemaster = s.getSpec();
  this->price = s.getPrice();
  this->logger = s.logger;
}
Spot::Spot(closingPrice& p, EsteeMaster& e) {
  setPrice(p);
  setSpec(e);
}
Spot::~Spot() {
  delete price;
  delete esteemaster;
}
closingPrice* Spot::getPrice() const { return price; }
EsteeMaster* Spot::getSpec() const { return esteemaster; }

void Spot::setPrice(closingPrice& p) { price = new closingPrice(p); }

void Spot::setSpec(EsteeMaster& e) { esteemaster = new EsteeMaster(e); }
