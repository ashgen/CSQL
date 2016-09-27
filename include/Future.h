/*
 * Future.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_FUTURE_H_
#define INCLUDE_FUTURE_H_
#include "Spot.h"
namespace Underlying {
class Future : public Spot {
 public:
  Future();
  Future(int, const Spot&);
  Future(int, EsteeMaster&, closingPrice&);
  int index;
};
}
#endif /* INCLUDE_FUTURE_H_ */
