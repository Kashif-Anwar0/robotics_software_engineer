// include/SensorLibrary/DistanceSensor.h
#pragma once
#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "Sensor.h"

class DistanceSensor : public Sensor<double> {
public:
    DistanceSensor(double distance) : Sensor(distance) {}
    void displayReading() const override {
        std::cout << "Distance: " << reading << " cm" << std::endl;
    }
};
#endif // DISTANCESENSOR_H
