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
namespace Underlying {
class Spot {
 public:
  Spot();
  Spot(const Spot& s);
  Spot(closingPrice& p, EsteeMaster& e);
  ~Spot();
  closingPrice* getPrice() const;
  EsteeMaster* getSpec() const;
  void setPrice(closingPrice& price);
  void setSpec(EsteeMaster& master);

  std::shared_ptr<spdlog::logger> logger;

 private:
  closingPrice* price;
  EsteeMaster* esteemaster;
};
}
#endif /* INCLUDE_SPOT_H_ */
