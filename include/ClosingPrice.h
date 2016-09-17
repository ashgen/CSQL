/*
 * ClosingPrice.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef CLOSINGPRICE_H_
#define CLOSINGPRICE_H_
#pragma once
#include <string>
#include <iostream>
#include <odb/core.hxx>
#include <boost/date_time/posix_time/ptime.hpp>
#pragma db value(boost::posix_time::ptime) type("DATETIME")

/*
 * Date	datetime
Open_Interest	decimal
Settlement_price	decimal
Open_Price	decimal
High_Price	decimal
Low_Price	decimal
Close_Price	decimal
Volume	decimal
Net_Traded_Val	decimal
Trades	int
Source	varchar
Estee_ID	varchar
 */
#pragma db object
class closingPrice{
public:
	closingPrice(){
		//Declare
	};
	boost::posix_time::ptime Date;
	double Open_Interest;
	double Settlement_price;
	double Open_Price;
	double High_Price;
	double Low_Price;
	double Close_Price;
	double Volume;
	double Net_Traded_Val;

	int Trades;
	std::string Source;
	std::string Estee_ID;
};




#endif /* CLOSINGPRICE_H_ */
