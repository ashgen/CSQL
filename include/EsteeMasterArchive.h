/*
 * EsteeMasterArchive.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef ESTEEMASTERARCHIVE_H_
#define ESTEEMASTERARCHIVE_H_

#pragma once
#include <odb/core.hxx>
#include "EsteeMaster.h"
#pragma db object
class EsteeMaster_Archive : public EsteeMaster {
 public:
  EsteeMaster_Archive(){};
  EsteeMaster_Archive(const EsteeMaster_Archive& e) : EsteeMaster(e) { this->ID = e.ID; }
  EsteeMaster_Archive(std::string esteeID) : EsteeMaster(esteeID){};
  int ID;

  friend std::ostream& operator<<(std::ostream& out, const EsteeMaster_Archive& a) {
    out << a.DataFeed_Ticker << "," << a.Underlying_Ticker << "," << a.ISIN << "," << a.Exchange_Code << "," << a.Option_Type << "," << a.Status << "," << a.TOKEN2 << "," << a.Expiry_Date2 << ","
        << a.SERIES << "," << a.Source << "," << a.UnderlyingEstee_Id << "," << a.Strike_Price << "," << a.Tick_Size << "," << a.Lot_Size << "," << a.Security_Type << "," << a.Token << ","
        << a.Quote_Size << "," << a.Instrument_Type << "," << a.TradingCurrency << "," << a.SettlementCurrency << "," << a.TickSizeSlabId << "," << a.AsOfDate << "," << a.Last_update_time << ","
        << a.Expiry_Date << "," << a.SettlementDate << "," << a.TradingStartDate << "," << a.LastTradingDate;
    return out;
  }
};

#endif /* ESTEEMASTERARCHIVE_H_ */
