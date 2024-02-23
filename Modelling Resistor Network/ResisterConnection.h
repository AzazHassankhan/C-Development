/*
 * ResisterConnection.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#ifndef RESISTERCONNECTION_H_
#define RESISTERCONNECTION_H_
#include <iostream>
#include <memory>
#include <list>
#include "Resister.h"
#include <string>

class ResisterConnection: public Resister {
protected:
	std::list <std::shared_ptr<Resister>> resister;
public:
	ResisterConnection(std::string name);

	virtual char seperator();

	std::string  getName();

	ResisterConnection& operator +=(const std::shared_ptr<Resister>& resister);

	virtual ~ResisterConnection();
};

#endif /* RESISTERCONNECTION_H_ */
