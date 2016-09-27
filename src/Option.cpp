/*

 * Option.cpp
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */
#include "Option.h"
#include "eaBase.h"
#include "fmt/format.h"
using namespace Underlying;
static const double TIME_IN_YEAR_SEC = (3600 * 24.0 * 252);
Option::Option(int index, EsteeMaster& e, closingPrice& p)
    : Future(index, e, p) {
  greeks = new eaGreeks(e.getEsteeID());
}
void Option::calculateIV(Future* f) {
  auto spec = getSpec();
  auto price = getPrice();
  isCall = spec->Security_Type == 5 ? true : false;
  strikePrice = spec->Strike_Price;
  timeToExpiry =
      (spec->Expiry_Date - price->_id.Date).total_seconds() / TIME_IN_YEAR_SEC;
  lFuturePrice = f->getPrice()->Settlement_price;
  interestRate = 0.08;
  lOptionPrice = price->Settlement_price;
  iv = eaBlackScholes::calculateIVUsingFuture(isCall, strikePrice, timeToExpiry,
                                              lFuturePrice, interestRate,
                                              lOptionPrice);
  // std::cout << *this;
  // Calculate all Greeks
  if (iv > ea_DOUBLEMAX || iv < ea_DOUBLEMIN) {
    // Dont dont anything
    std::cout << "Implied Volatility is not correct";
    return;
  }
  // calculate Greeks
  greeks->delta = eaBlackScholes::blackScholesDelta(
      isCall, strikePrice, timeToExpiry, lFuturePrice, interestRate, iv);
  greeks->gamma = eaBlackScholes::blackScholesGamma(
      isCall, strikePrice, timeToExpiry, lFuturePrice, interestRate, iv);
  greeks->theta = eaBlackScholes::blackScholesTheta(
      isCall, strikePrice, timeToExpiry, lFuturePrice, interestRate, iv);
  greeks->vega = eaBlackScholes::blackScholesVega(
      isCall, strikePrice, timeToExpiry, lFuturePrice, interestRate, iv);
  greeks->rho = eaBlackScholes::blackScholesRho(
      isCall, strikePrice, timeToExpiry, lFuturePrice, interestRate, iv);
}

std::ostream& operator<<(std::ostream& s, const Option& o) {
  return s << fmt::format("{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11}",
                          o.isCall, o.strikePrice, o.timeToExpiry,
                          o.lFuturePrice, o.interestRate, o.lOptionPrice, o.iv,
                          o.greeks->delta, o.greeks->gamma, o.greeks->theta,
                          o.greeks->vega, o.greeks->rho);
}
