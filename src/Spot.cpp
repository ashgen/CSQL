/*
 * Spot.cpp
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */
#include "Spot.h"

Spot::Spot(const closingPrice& p, const EsteeMaster& e) {
  setPrice(p);
  setSpec(e);
}
closingPrice* Spot::getPrice() const { return price.get(); }
EsteeMaster* Spot::getSpec() const { return esteemaster.get(); }

void Spot::setPrice(const closingPrice& p) { price.reset(new closingPrice(p)); }

void Spot::setSpec(const EsteeMaster& e) {
  esteemaster.reset(new EsteeMaster(e));
}
