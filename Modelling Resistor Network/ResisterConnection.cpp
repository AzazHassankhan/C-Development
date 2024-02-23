/*
 * ResisterConnection.cpp
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#include "ResisterConnection.h"


ResisterConnection::ResisterConnection(std::string name):Resister(name) {
}

char ResisterConnection::seperator() {
	return ',';
}

std::string ResisterConnection::getName()  {
	std::string name = Resister::getName() +"[";
	bool first = false;
	        for (const auto& res : resister) {
        if (first)
        {
        	name += seperator();
        }
        first = true;
        name += res->getName();
    }
    name+="]";

    return name;
}

ResisterConnection& ResisterConnection::operator +=(const std::shared_ptr<Resister> &res)
{
	resister.push_back(res);

	return *this;
}

ResisterConnection::~ResisterConnection() {
	// TODO Auto-generated destructor stub
}

