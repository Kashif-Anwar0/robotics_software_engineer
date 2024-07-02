// src/main.cpp
#include <iostream>
#include "TemperatureSensor.h"
#include "DistanceSensor.h"

int main() {
    TemperatureSensor tempSensor(25.3);
    DistanceSensor distSensor(150.5);

    std::cout << "Sensors Readings:\n";
    tempSensor.displayReading();
    distSensor.displayReading();

    return 0;
}
