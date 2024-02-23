/*
 * Resister.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Azaz
 */

#ifndef RESISTER_H_
#define RESISTER_H_
#include <iostream>
#include <string>

class Resister {
private:
	std::string name;
public:
	Resister(std::string name);

	virtual ~Resister();

	virtual std::string getName();

	std::string toString();

	virtual float nominalValue()=0;

	virtual float maximumValue()=0;

	virtual float minimumValue()=0;

	std::ostream& operator <<(std::ostream& out);



};

#endif /* RESISTER_H_ */
