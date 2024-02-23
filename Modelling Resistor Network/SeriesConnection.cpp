/*
 * SeriesConnection.cpp
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#include "SeriesConnection.h"

SeriesConnection::SeriesConnection(std::string name):ResisterConnection(name) {
	// TODO Auto-generated constructor stub

}

char SeriesConnection::seperator() {
	return '-';
}

float SeriesConnection::nominalValue() {
	float nominalValue = 0;
	for(auto& Res: resister)
	{
		nominalValue+=Res->nominalValue();
	}
	return nominalValue;
}

float SeriesConnection::maximumValue() {
	float maximumValue = 0;
	for(auto& Res: resister)
	{
		maximumValue+=Res->maximumValue();
	}
	return maximumValue;
}

float SeriesConnection::minimumValue() {
	float minimumValue = 0;
	for(auto& Res: resister)
	{
		minimumValue+=Res->minimumValue();
	}
	return minimumValue;
}

SeriesConnection::~SeriesConnection() {
	// TODO Auto-generated destructor stub
}

