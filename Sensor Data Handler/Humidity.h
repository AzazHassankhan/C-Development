/*
 * Humidity.h
 *
 *  Created on: Feb 18, 2024
 *      Author: Azaz
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_
#include <memory>

#include "Measurement.h"

class Humidity: public Measurement {
private:
	float humidity;

public:
	Humidity(uint16_t timestamp, float humidity);

	virtual ~Humidity();

	std::string toString();

    std::shared_ptr<Humidity> fromString(uint16_t timestamp, std::string valuestr);

    Humidity* toType(Measurement* ptr);

	float getHumidity() const;
};

#endif /* HUMIDITY_H_ */
