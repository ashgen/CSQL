/*
 * Position.h
 *
 *  Created on: 29-Sep-2016
 *      Author: ashish
 */

#ifndef INCLUDE_POSITION_H_
#define INCLUDE_POSITION_H_
#include "Spot.h"
class Spot;
class Position {
 public:
  Position(Spot*, int);
  Position(const Position&);
  Spot* getInstrument() const;
  int getPosition() const;

  Spot* setInstrument();
  int setPosition();

  eaGreeks* greeks;

 private:
  Spot* instrument;
  int nPos;
};

#endif /* INCLUDE_POSITION_H_ */
