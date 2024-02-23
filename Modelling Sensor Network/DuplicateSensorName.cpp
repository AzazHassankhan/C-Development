#include "DuplicateSensorName.h"

DuplicateSensorName::DuplicateSensorName(std::string sensorName):std::invalid_argument
("already includes a sensor wit  this sensor's name" + sensorName) {
}
