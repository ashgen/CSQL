/*
 * TestData.cpp
 *
 *  Created on: 17-Sep-2016
 *      Author: ashish
 */
#include "VolStrategy.h"

int main(){
	VolStrategy* p=new VolStrategy("config/config.json");
	p->getFutureData();
	return 0;
}



