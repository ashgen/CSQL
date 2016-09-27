/*
 * Future.cpp
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#include "Future.h"

Future::Future(int index, const EsteeMaster& e, const closingPrice& p)
    : Spot(p, e) {
  this->index = index;
}

Future::Future(int index, const Spot& s) : Spot(s) { this->index = index; }
