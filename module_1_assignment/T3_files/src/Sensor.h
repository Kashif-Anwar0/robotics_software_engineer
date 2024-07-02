// include/SensorLibrary/Sensor.h
// include/Sensor.h
#pragma once
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

template <typename T>
class Sensor {
public:
    Sensor(T reading) : reading(reading) {}
    virtual ~Sensor() = default;

    virtual void displayReading() const = 0;

protected:
    T reading;
};

template <>
void Sensor<double>::displayReading() const {
    std::cout << "Reading: " << reading << std::endl;
}

template <>
void Sensor<std::string>::displayReading() const {
    std::cout << "Reading: " << reading << std::endl;
}

template <>
void Sensor<char>::displayReading() const {
    std::cout << "Reading: " << reading << std::endl;
}
#endif // SENSOR_H
