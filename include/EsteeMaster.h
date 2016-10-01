#ifndef __ESTEEMASTER_H
#define __ESTEEMASTER_H
#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>
#include <odb/core.hxx>
#include <string>
#pragma db value(boost::posix_time::ptime) type("DATETIME")
#pragma db object
namespace btime = boost::posix_time;

inline std::ostream& operator<<(std::ostream& out, const btime::ptime& p) { return out << btime::to_simple_string(p); }
class EsteeMaster {
 public:
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

  EsteeMaster(std::string esteeID) : Estee_ID(esteeID){};
  EsteeMaster(){};
  EsteeMaster(const EsteeMaster& e) {
    this->DataFeed_Ticker = e.DataFeed_Ticker;
    this->Underlying_Ticker = e.Underlying_Ticker;
    this->ISIN = e.ISIN;
    this->Exchange_Code = e.Exchange_Code;
    this->Option_Type = e.Option_Type;
    this->Status = e.Status;
    this->TOKEN2 = e.TOKEN2;
    this->Expiry_Date2 = e.Expiry_Date2;
    this->SERIES = e.SERIES;
    this->Source = e.Source;
    this->UnderlyingEstee_Id = e.UnderlyingEstee_Id;
    this->Strike_Price = e.Strike_Price;
    this->Tick_Size = e.Tick_Size;
    this->Lot_Size = e.Lot_Size;
    this->Security_Type = e.Security_Type;
    this->Token = e.Token;
    this->Quote_Size = e.Quote_Size;
    this->Instrument_Type = e.Instrument_Type;
    this->TradingCurrency = e.TradingCurrency;
    this->SettlementCurrency = e.SettlementCurrency;
    this->TickSizeSlabId = e.TickSizeSlabId;
    this->AsOfDate = e.AsOfDate;
    this->Last_update_time = e.Last_update_time;
    this->Expiry_Date = e.Expiry_Date;
    this->SettlementDate = e.SettlementDate;
    this->TradingStartDate = e.TradingStartDate;
    this->LastTradingDate = e.LastTradingDate;
  };
  std::string getEsteeID() { return Estee_ID; }
  friend std::ostream& operator<<(std::ostream& out, const EsteeMaster& a) {
    out << a.DataFeed_Ticker << "," << a.Underlying_Ticker << "," << a.ISIN << "," << a.Exchange_Code << "," << a.Option_Type << "," << a.Status << "," << a.TOKEN2 << "," << a.Expiry_Date2 << ","
        << a.SERIES << "," << a.Source << "," << a.UnderlyingEstee_Id << "," << a.Strike_Price << "," << a.Tick_Size << "," << a.Lot_Size << "," << a.Security_Type << "," << a.Token << ","
        << a.Quote_Size << "," << a.Instrument_Type << "," << a.TradingCurrency << "," << a.SettlementCurrency << "," << a.TickSizeSlabId << "," << a.AsOfDate << "," << a.Last_update_time << ","
        << a.Expiry_Date << "," << a.SettlementDate << "," << a.TradingStartDate << "," << a.LastTradingDate;
    return out;
  }

 private:
  friend class odb::access;
#pragma db id auto
  std::string Estee_ID;
};
#endif
