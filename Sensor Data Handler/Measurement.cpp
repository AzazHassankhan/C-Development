/*
 * Measurement.cpp
 *
 *  Created on: Feb 17, 2024
 *      Author: Azaz
 */

#include "Measurement.h"
#include <iostream>

using namespace std;

Measurement::Measurement(uint16_t timestamp):timestamp(timestamp) {
}

uint16_t Measurement::toTimestamp(int minutes, int hours) {
	if( minutes>59 || minutes<0 || hours>23 || hours<0)
	{
		throw std::invalid_argument("one of the parameter values is out of its valid range");
	}

	return ((hours*60) +minutes);
}


std::string Measurement::toTimeOfDay(uint16_t timestamp) {
	uint16_t hour = timestamp / 60;
	uint16_t minute = timestamp % 60;
	 return (hour<10 ? "0":"") + std::to_string(hour) +":"+
			 (minute<10 ? "0":"") + std::to_string(minute);
}

Measurement::~Measurement() {
	// TODO Auto-generated destructor stub
}

uint16_t Measurement::getTimestamp() {
	return timestamp;
}

std::ostream& Measurement::operator <<(std::ostream &out) {
	out<<toTimeOfDay(timestamp)<<" "<<toString();

	return out;
}

void Measurement::parseLine(const std::string &line, uint16_t &timestamp,
		std::string &type, std::string &remainder) {

    auto semicoln = line.find(";");

    string timestampstr = line.substr(1,semicoln - 1);

    timestamp = std::atol(timestampstr.c_str()); // Convert string to unsigned long

    size_t secondcolonPos = line.find(':', semicoln);

    type = line.substr(secondcolonPos + 1, semicoln - secondcolonPos - 1);

    remainder = line.substr(semicoln + 1);


}
