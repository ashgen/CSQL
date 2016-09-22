/*
 * Spot.cpp
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */
#include "Spot.h"

Spot::Spot(const closingPrice& p,const EsteeMaster& e){
	setPrice(p);
	setSpec(e);
}
std::unique_ptr<closingPrice> Spot::getPrice(){
	return price;

}
std::unique_ptr<EsteeMaster> Spot::getSpec(){
	return esteemaster;

}

void Spot::setPrice(const closingPrice& p){
	price=std::make_unique<closingPrice>(new closingPrice(p));
}

void Spot::setSpec(const EsteeMaster& e){
	esteemaster=std::make_unique<EsteeMaster>(new EsteeMaster_Archive(e));
}

void Spot::setPrice(const std::unique_ptr<closingPrice> p){
	price=p;
}

void Spot::setSpec(const std::unique_ptr<EsteeMaster> s){
	esteemaster=s;
}
