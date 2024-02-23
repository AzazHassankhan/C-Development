/*
 * Temperature.h
 *
 *  Created on: Feb 18, 2024
 *      Author: Azaz
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Measurement.h"
#include <memory>

class Temperature: public Measurement {
private:
	 float temperature;
public:

	Temperature(uint16_t timestamp, float temperature);

	float getTemperature() const;

	std::string toString();

    std::shared_ptr<Temperature> fromString(uint16_t timestamp, std::string valuestr);

    Temperature* toType(Measurement* ptr);

	virtual ~Temperature();

};

#endif /* TEMPERATURE_H_ */
