/*
 * ResisterPart.cpp
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#include "ResisterPart.h"


ResisterPart::ResisterPart(std::string name, float value, float tolerance):Resister(name),value(value),tolerance(tolerance) {
}

ResisterPart::~ResisterPart() {
	// TODO Auto-generated destructor stub
}

float ResisterPart::nominalValue() {
	return value;
}

float ResisterPart::maximumValue() {
	return value + (tolerance/100);
}

float ResisterPart::minimumValue() {
	return value - (tolerance/100);

}
