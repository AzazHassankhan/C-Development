/*
 * Measurement.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Azaz
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_
#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>

class Measurement {
private:
	uint16_t timestamp;
public:
	Measurement(uint16_t timestamp=0);

	uint16_t toTimestamp(int minutes,int hours);

	std::string toTimeOfDay(uint16_t timestamp);

	uint16_t getTimestamp();

	virtual std::string toString()= 0 ;

	std::ostream& operator <<(std::ostream& out);

	void parseLine(const std::string& line, uint16_t& timestamp, std::string& type, std::string& remainder);

	virtual ~Measurement();
};

#endif /* MEASUREMENT_H_ */
