/*
 * Future.cpp
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#include "Future.h"

Future::Future(int index,const EsteeMaster& e,const closingPrice& p){
	this->index=index;
	this->setPrice(p);
	this->setSpec(e);
}

Future::Future(int index,const Spot& s){
	this->index=index;
	this->setPrice(s.getPrice());
	this->setSpec(s.getSpec());
}

