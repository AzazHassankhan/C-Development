/*
 * ParallelResister.cpp
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#include "ParallelResister.h"

ParallelResister::ParallelResister(std::string name):ResisterConnection(name) {
	// TODO Auto-generated constructor stub

}

char ParallelResister::seperator() {
	return '|';
}

float ParallelResister::nominalValue() {
	float nominalValue = 0;
	for(auto& Res: resister)
	{
		nominalValue+= (1/Res->nominalValue());
	}
	return 1 / nominalValue;
}

float ParallelResister::maximumValue() {
	float maximumValue = 0;
	for(auto& Res: resister)
	{
		maximumValue+=(1/Res->maximumValue());
	}
	return 1 / maximumValue;
}

float ParallelResister::minimumValue() {
	float minimumValue = 0;
	for(auto& Res: resister)
	{
		minimumValue+= (1/Res->minimumValue());
	}
	return 1 / minimumValue;
}


ParallelResister::~ParallelResister() {
	// TODO Auto-generated destructor stub
}

