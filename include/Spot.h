/*
 * Spot.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_SPOT_H_
#define INCLUDE_SPOT_H_
#include "ClosingPrice.h"
#include "EsteeMaster.h"
#include "EsteeMasterArchive.h"
#include "spdlog/logger.h"
class Spot {
 public:
  Spot();
  Spot(const Spot& s);
  Spot(const closingPrice& p, const EsteeMaster& e);
  closingPrice* getPrice() const;
  EsteeMaster* getSpec() const;
  void setPrice(const closingPrice& price);
  void setSpec(const EsteeMaster& master);

  std::shared_ptr<spdlog::logger> logger;

 private:
  std::unique_ptr<closingPrice> price;
  std::unique_ptr<EsteeMaster> esteemaster;
};

#endif /* INCLUDE_SPOT_H_ */
