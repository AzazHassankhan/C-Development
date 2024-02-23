/*
 * MeasurementDb.h
 *
 *  Created on: Feb 18, 2024
 *      Author: Azaz
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_
#include <map>
#include <memory>
#include <vector>
#include "Measurement.h"
#include <fstream>
#include <istream>

class MeasurementDb {

private:
	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;

public:

	void addMeasurement(const std::string& location,std::shared_ptr<Measurement>  measurement);

	void print();

	void save();

	void load();

	bool maximumTemperature(std::string& location,  std::shared_ptr<Measurement>& measurement);

};

#endif /* MEASUREMENTDB_H_ */
