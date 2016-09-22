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
#include <odb/nullable.hxx>
#include <boost/date_time/posix_time/posix_time.hpp>
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
#pragma db value
class id{
public:
	boost::posix_time::ptime Date;
	std::string Estee_ID;
};
#pragma db object bulk(5000)
class closingPrice{
public:
	closingPrice(){
		//Declare
	};
	closingPrice(const closingPrice& a){
		this->Close_Price=a.Close_Price;
		this->High_Price=a.High_Price;
		this->Low_Price=a.Low_Price;
		this->Net_Traded_Val=a.High_Price;
		this->Open_Interest=a.Open_Interest;
		this->Open_Price=a.Open_Price;
		this->Settlement_price=a.Settlement_price;
		this->Source=a.Source;
		this->Trades=a.Trades;
		this->Volume=a.Volume;

	}
	closingPrice(const closingPrice* a){
		this->Close_Price=a->Close_Price;
		this->High_Price=a->High_Price;
		this->Low_Price=a->Low_Price;
		this->Net_Traded_Val=a->High_Price;
		this->Open_Interest=a->Open_Interest;
		this->Open_Price=a->Open_Price;
		this->Settlement_price=a->Settlement_price;
		this->Source=a->Source;
		this->Trades=a->Trades;
		this->Volume=a->Volume;

	}
	friend std::ostream& operator<<(std::ostream& out,const closingPrice &a){
		out<<a._id.Estee_ID<<","
				<<boost::posix_time::to_simple_string(a._id.Date)<<","
				<<a.Open_Interest<<","
				<<a.Settlement_price<<","
				<<a.Open_Price<<","
				<<a.High_Price<<","
				<<a.Low_Price<<","
				<<a.Close_Price<<","
				<<a.Volume<<","
				<<a.Net_Traded_Val;
		return out;
	}
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
#pragma db id
#pragma db column("")
	id _id;

};




#endif /* CLOSINGPRICE_H_ */
