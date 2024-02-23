/*
 * ParallelResister.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#ifndef PARALLELRESISTER_H_
#define PARALLELRESISTER_H_

#include "ResisterConnection.h"

class ParallelResister: public ResisterConnection {
public:
	ParallelResister(std::string name);

	char seperator() override;

	float nominalValue();

	float maximumValue();

	float minimumValue();

	virtual ~ParallelResister();
};

#endif /* PARALLELRESISTER_H_ */
