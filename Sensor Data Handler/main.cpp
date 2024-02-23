//============================================================================
// Name        : Exam-2019.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>

using namespace std;
#include "Temperature.h"
#include "Humidity.h"
#include "Measurement.h"
#include "MeasurementDb.h"

int main() {

	Temperature measurement1(measurement1.toTimestamp(0, 6),-3);
	cout<<measurement1.toString()<<endl;
	measurement1<<cout<<endl;

	////////////////////////////////////////////
	Humidity measurement2(measurement1.toTimestamp(0, 8),80);
	Temperature measurement3(measurement1.toTimestamp(5, 10),22);
	Temperature measurement4(measurement1.toTimestamp(0, 12),22);

	MeasurementDb database;
	database.addMeasurement("Bath",std::make_shared<Humidity>(measurement2) );
	database.addMeasurement("Kitchen",std::make_shared<Temperature>(measurement4) );
	database.addMeasurement("Kitchen",std::make_shared<Temperature>(measurement3) );

	database.print();
	database.save();

	////////////////////////////////////////////
	MeasurementDb database1;

	database1.load();
	database1.print();

	return 0;
}
