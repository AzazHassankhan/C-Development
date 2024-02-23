/*
 * SeriesConnection.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#ifndef SERIESCONNECTION_H_
#define SERIESCONNECTION_H_

#include "ResisterConnection.h"

class SeriesConnection: public ResisterConnection {
private:

public:
	SeriesConnection(std::string name);

	char seperator() override;

	float nominalValue();

	float maximumValue();

	float minimumValue();

	virtual ~SeriesConnection();
};

#endif /* SERIESCONNECTION_H_ */
