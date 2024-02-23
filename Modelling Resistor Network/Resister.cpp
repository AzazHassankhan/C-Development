/*
 * Resister.cpp
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#include "Resister.h"
using namespace std;


Resister::Resister(std::string name):name(name) {
}

std::string Resister::getName()  {
	return name;
}

std::string Resister::toString()
{

	return getName()  + "=" + std::to_string(nominalValue()) + "Ohm";
}

std::ostream& Resister::operator <<(std::ostream &out)
{
	out<<toString()<<endl;
	return out;
}

Resister::~Resister() {}

