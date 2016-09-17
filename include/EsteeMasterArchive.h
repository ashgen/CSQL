/*
 * EsteeMasterArchive.h
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#ifndef ESTEEMASTERARCHIVE_H_
#define ESTEEMASTERARCHIVE_H_

#pragma once
#include "EsteeMaster.h"
#include <odb/core.hxx>
#pragma db object
class EsteeMasterArchive:public EsteeMaster
{
public:
	EsteeMasterArchive(){};
	EsteeMasterArchive(const EsteeMasterArchive& e){};
	EsteeMasterArchive(std::string esteeID):EsteeMaster(esteeID){};
	int ID;

};




#endif /* ESTEEMASTERARCHIVE_H_ */
