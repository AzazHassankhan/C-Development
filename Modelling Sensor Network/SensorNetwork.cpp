#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor> &&sensor) {

    for(auto& existedsensor: sensors)
    {
        if (existedsensor->getName()==sensor->getName())
        {throw  DuplicateSensorName(sensor->getName());}
    }

    sensors.push_back(move(sensor));
    return *this;
}
