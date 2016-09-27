/*
 * Future.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_FUTURE_H_
#define INCLUDE_FUTURE_H_
#include "Spot.h"
class Future : public Spot {
 public:
  Future();
  Future(int, const Spot&);
  Future(int, const EsteeMaster&, const closingPrice&);
  int index;
};

#endif /* INCLUDE_FUTURE_H_ */
