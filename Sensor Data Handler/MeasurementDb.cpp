/*
 * MeasurementDb.cpp
 *
 *  Created on: Feb 18, 2024
 *      Author: Azaz
 */

#include "MeasurementDb.h"
#include <iostream>
#include "Temperature.h"
#include "Humidity.h"
using namespace std;

void MeasurementDb::addMeasurement(const std::string &location,
		std::shared_ptr<Measurement> measurement) {

	auto exitinglocation= data.find(location);
	if(exitinglocation!=data.end())
	{
		exitinglocation->second.push_back(measurement);
	}
	else{
	vector<std::shared_ptr<Measurement>> temp;

	temp.push_back(measurement);

	data.insert(std::make_pair(location,std::move(temp)));
	}
}

void MeasurementDb::print() {
   for (const auto& values : data) {


        for (const auto& measurement : values.second) {
            cout  << values.first << ": ";
            cout <<measurement->toTimeOfDay(measurement->getTimestamp() ) <<" "<<measurement->toString() << std::endl; // Dereference the shared pointer to access the Measurement object
        }
    }
}

void MeasurementDb::save() {
	ofstream fout;
	fout.open("StudentDataBase.txt");
	if (fout.is_open())
		{
	   for (const auto& values : data) {
	       fout  << "["<< values.first << "]"<<endl;

	        for (const auto& measurement : values.second) {
	        	fout <<measurement->getTimestamp()<<";" <<measurement->toString() << std::endl; // Dereference the shared pointer to access the Measurement object
	        }
	    }
		}
	fout.close();
}

void MeasurementDb::load() {
    std::ifstream fin;
	fin.open("StudentDataBase.txt");
	data.clear();
    std::string line;
    std::string location;

	uint16_t timestamp;
    std::string type;
    std::string valueStr;
	if (fin.is_open())
	{
		while(getline(fin, line))

		{
			if(line.front()=='[' && line.back()==']')
			{   location = line.substr(1,line.size() - 1);
				continue;}


	        std::shared_ptr<Measurement> measurement;
	        std::shared_ptr<Temperature> Temperature;
	        std::shared_ptr<Humidity> Humidity;

	        measurement->parseLine(line, timestamp, type, valueStr);

	        if (type == "Temperature") {
	            measurement = Temperature->fromString(timestamp, valueStr);
	        } else if (type == "Humidity") {
	            measurement = Humidity->fromString(timestamp, valueStr);
	        } else {
	            // Unknown measurement type, skip to the next line
	            continue;
	        }

	        // Add the measurement to the database
	        addMeasurement(location, measurement);

		}
	}
}

bool MeasurementDb::maximumTemperature(string &location,shared_ptr<Measurement> &maxTempMeasurement) {
	float maxTemperature=0;
	 maxTempMeasurement = nullptr;
	 for (const auto& entry : data)
	 {
	        for (const auto& measurement : entry.second)
	        {
	            shared_ptr<Temperature> tempMeasurement = dynamic_pointer_cast<Temperature>(measurement);


	        	if(tempMeasurement!=nullptr)
	        	{
	        	                // If the measurement is of type Temperature
	        	                if (tempMeasurement->getTemperature() > maxTemperature)
	        	                {
	        	                    // Update the maximum temperature and location
	        	                    maxTemperature = tempMeasurement->getTemperature();
	        	                    maxTempMeasurement = tempMeasurement;

	        	                    location = entry.first;
	        	                }
	        	}
	        }

	 }

	    if (maxTempMeasurement != nullptr) {
	        return true; // Maximum temperature found
	    } else {
	        return false; // No temperature measurement found
	    }
}
