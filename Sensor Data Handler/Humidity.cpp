/*
 * Humidity.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: Azaz
 */

#include "Humidity.h"

Humidity::Humidity(uint16_t timestamp, float humidity):Measurement(timestamp),
humidity(humidity)  {
}

std::string Humidity::toString() {

	return ("Humidity: " + std::to_string(humidity) + "%");
}

std::shared_ptr<Humidity> Humidity::fromString(uint16_t timestamp,
		std::string valuestr) {
    double value;

	return std::make_shared<Humidity>(timestamp, value);
}

float Humidity::getHumidity() const {
	return humidity;
}

Humidity* Humidity::toType(Measurement *ptr) {

	Humidity* pHumid = dynamic_cast<Humidity*>(ptr);

	if(pHumid!=nullptr)
	{
		return nullptr;
	}
	return pHumid;
}

Humidity::~Humidity() {}

