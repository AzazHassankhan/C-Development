/*
 * ResisterPart.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#ifndef RESISTERPART_H_
#define RESISTERPART_H_

#include "Resister.h"

class ResisterPart: public Resister {
private:
	float value;
	float tolerance;
public:
	ResisterPart(std::string name, float value, float tolerance);

	virtual ~ResisterPart();

	float nominalValue();

	float maximumValue();

	float minimumValue();


};

#endif /* RESISTERPART_H_ */
