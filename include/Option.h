/*
 * Option.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_OPTION_H_
#define INCLUDE_OPTION_H_

#include "Future.h"
#include "eaBlackScholes.h"
#include "eaFOMarketMakingUnit.h"
#include "eaPercentile.h"
namespace Underlying {
class Option : public Future {
 public:
  Option();
  Option(int, Spot&);
  Option(int, EsteeMaster&, closingPrice&);
  double iv;
  eaGreeks* greeks;
  void calculateIV(Future* f);
  friend std::ostream& operator<<(std::ostream& s, const Option& o);
  bool isCall;
  double strikePrice;
  double timeToExpiry;
  double lFuturePrice;
  double interestRate;
  double lOptionPrice;

 private:
  /*
bool isCall;
double strikePrice;
double timeToExpiry;
double lFuturePrice;
double interestRate;
double lOptionPrice;
   */
};
}
#endif /* INCLUDE_OPTION_H_ */
