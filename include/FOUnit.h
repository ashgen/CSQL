/*
 * FOUnit.h
 *
 *  Created on: 22-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_FOUNIT_H_
#define INCLUDE_FOUNIT_H_
#include "Option.h"
class FOUnit{
public:
	FOUnit();
	FOUnit(const FOUnit&);
	std::unique_ptr<Spot> spot;
	std::unordered_map<int,std::unique_ptr<Spot>> 	future;
	std::unordered_map<int,std::unique_ptr<Spot>>	call;
	std::unordered_map<int,std::unique_ptr<Spot>> 	put;
	void calculate();
};




#endif /* INCLUDE_FOUNIT_H_ */
