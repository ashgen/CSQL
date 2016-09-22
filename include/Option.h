/*
 * Option.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_OPTION_H_
#define INCLUDE_OPTION_H_

#include "Spot.h"
#include "eaBlackScholes.h"
#include "eaPercentile.h"
#include "eaFOMarketMakingUnit.h"
class Option:public Future{
public:
	Option();
	Option(int,Spot*);
	Option(int,EsteeMaster*,closingPrice*);
	eaGreeks* greeks;
	eaMoneyness moneyness;
};
#endif /* INCLUDE_OPTION_H_ */
