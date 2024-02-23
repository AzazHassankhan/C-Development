/*
 * Temperature.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: Azaz
 */

#include "Temperature.h"

Temperature::Temperature(uint16_t timestamp, float temperature):Measurement(timestamp),
temperature(temperature) {}

float Temperature::getTemperature() const {
	return temperature;
}

std::string Temperature::toString() {

	return ("Temperature: " + std::to_string(temperature) + "°C");
}

std::shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp,std::string valuestr) {
    double value;

	return std::make_shared<Temperature>(timestamp, value);
}

Temperature* Temperature::toType(Measurement *ptr) {

	Temperature* pTemp = dynamic_cast<Temperature*>(ptr);

	if(pTemp!=nullptr)
	{
		return nullptr;
	}
	return dynamic_cast<Temperature*>(ptr);
}

Temperature::~Temperature() {
	// TODO Auto-generated destructor stub
}

