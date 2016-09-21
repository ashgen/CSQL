#ifndef __ESTEEMASTER_H
#define __ESTEEMASTER_H
#pragma once

#include <string>
#include <odb/core.hxx>
#include <boost/date_time/posix_time/ptime.hpp>
#pragma db value(boost::posix_time::ptime) type("DATETIME")
#pragma db object
namespace btime=boost::posix_time;
class EsteeMaster{
public :


	std::string DataFeed_Ticker;
	std::string Underlying_Ticker;
	std::string ISIN;
	std::string Exchange_Code;
	std::string Option_Type;
	std::string Status;
	std::string TOKEN2;
	std::string Expiry_Date2;
	std::string SERIES;
	std::string Source;
	std::string UnderlyingEstee_Id;

	double Strike_Price;
	double Tick_Size;

	int Lot_Size;
	int Security_Type;
	int Token;
	int Quote_Size;
	int Instrument_Type;
	int TradingCurrency;
	int SettlementCurrency;
	int TickSizeSlabId;

	btime::ptime AsOfDate;
	btime::ptime Last_update_time;
	btime::ptime Expiry_Date;
	btime::ptime SettlementDate;
	btime::ptime TradingStartDate;
	btime::ptime LastTradingDate;

	EsteeMaster(std::string esteeID):Estee_ID(esteeID) {};
	EsteeMaster(){};
	EsteeMaster(const EsteeMaster& e){};
	std::string getEsteeID(){
		return Estee_ID;
	}
private:
	friend class odb::access;
	#pragma db id auto
	std::string Estee_ID;
};
#endif

