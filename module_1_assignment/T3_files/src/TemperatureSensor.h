// include/SensorLibrary/TemperatureSensor.h
#pragma once
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor<double> {
public:
    TemperatureSensor(double temperature) : Sensor(temperature) {}
    void displayReading() const override {
        std::cout << "Temperature: " << reading << "°C" << std::endl;
    }
};
#endif // TEMPERATURESENSOR_H
