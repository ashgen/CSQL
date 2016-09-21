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
class EsteeMaster_Archive:public EsteeMaster
{
public:
	EsteeMaster_Archive(){};
	EsteeMaster_Archive(const EsteeMaster_Archive& e){};
	EsteeMaster_Archive(std::string esteeID):EsteeMaster(esteeID){};
	int ID;

};




#endif /* ESTEEMASTERARCHIVE_H_ */
