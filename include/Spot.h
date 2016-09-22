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
class Spot{
public:
	Spot();
	Spot(const Spot& s);
	Spot(const closingPrice& p,const EsteeMaster& e);
	std::unique_ptr<closingPrice> getPrice() const;
	std::unique_ptr<EsteeMaster> getSpec() const;
	void setPrice(const closingPrice& price);
	void setSpec(const EsteeMaster& master);
	void setPrice(const std::unique_ptr<closingPrice> price);
	void setSpec(const std::unique_ptr<EsteeMaster> master);


private:
	std::unique_ptr<closingPrice> price;
	std::unique_ptr<EsteeMaster> esteemaster;
};




#endif /* INCLUDE_SPOT_H_ */
