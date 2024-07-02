# Assignment for Module 1 
# C++ from Robotics Prespective by Kashif Anwar

## Overview

1. Task 1 simulates the movement of two popular robots, TurtleBot3 Burger and Husky UGV, using C++. It demonstrates the use of object-oriented programming (OOP) principles, including class definitions, namespaces, and method invocations. The simulation showcases how each robot moves forward, moves backward, and stops.

2. Task 2 simulates the movement of a robot equipped with temperature and distance sensors. The robot, named Burger, moves forward, stops, and then moves backward. At each stage, the robot displays its sensor readings, which include temperature and distance values.

3. Task 3 simulates a robot equipped with temperature and distance sensors using C++. It demonstrates the use of object-oriented programming (OOP) principles, including class templates. The simulation showcases how the robot obtains and displays readings from different types of sensors.

## Robots Background

### TurtleBot3 Burger
TurtleBot3 Burger is a compact, affordable, and programmable robot used widely in research and education. It is known for its small size and versatility in various applications. Key features include:
- **Speed:** 0.22 m/s (max)
- **Weight:** 1.2 kg
- **Size:** 138 mm (H) x 178 mm (W) x 192 mm (L)
- **Sensors:** 1x LiDAR, 1x IMU, 2x Wheel encoders

### Husky UGV
Husky UGV (Unmanned Ground Vehicle) is a robust and versatile robot used for outdoor research, industrial applications, and field robotics. It is known for its rugged design and ability to carry heavy payloads. Key features include:
- **Speed:** 1.0 m/s (max)
- **Weight:** 50 kg
- **Size:** 430 mm (H) x 670 mm (W) x 990 mm (L)
- **Sensors:** 1x IMU, 4x Wheel encoders, Optional sensors (LiDAR, GPS, Cameras, etc.)


# Task 1
## Code Structure

The Code is structured as follows:

- **Robot Class Definition**
- **Namespaces for Robot Creation**
- **Main Function for Simulation**

### Robot Class Definition

The `Robot` class defines the attributes and methods for a robot. It includes:
- **Attributes:**
  - `name`: The name of the robot.
  - `speed`: The speed of the robot.
  - `Physical`: A nested structure that includes `weight`, `sizeH` (height), `sizeW` (width), `sizeL` (length), and `numberOfSensors`.

- **Methods:**
  - `moveForward()`: Simulates the robot moving forward.
  - `moveBackward()`: Simulates the robot moving backward.
  - `stop()`: Simulates the robot stopping.

```cpp
#include <iostream>
#include <string>

class Robot {
public:
    std::string name;
    double speed;

    struct Physical {
        double weight;
        double sizeH;
        double sizeW;
        double sizeL;
        int numberOfSensors;

        Physical(double w, double h, double wdt, double l, int nos) 
            : weight(w), sizeH(h), sizeW(wdt), sizeL(l), numberOfSensors(nos) {}
    };

    Physical physical;

    Robot(std::string n, double s, double w, double h, double wdt, double l, int nos) 
        : name(n), speed(s), physical(w, h, wdt, l, nos) {}

    void moveForward() {
        std::cout << name << " is moving forward at speed " << speed << " m/s." << std::endl;
    }

    void moveBackward() {
        std::cout << name << " is moving backward at speed " << speed << " m/s." << std::endl;
    }

    void stop() {
        std::cout << name << " has stopped." << std::endl;
    }
};
```
### Namespaces for Robot Creation
Namespaces Burger and Husky are used to define the specific robots and their attributes. Each namespace includes a createRobot function that returns a Robot object.

```cpp
namespace Burger {
    Robot createRobot() {
        return Robot("Burger", 0.22, 1.2, 138, 178, 192, 3);
    }
}

namespace Husky {
    Robot createRobot() {
        return Robot("Husky", 1.0, 50.0, 430, 670, 990, 4);
    }
}
```
### Main Function for Simulation
The main function instantiates the robots using the createRobot functions from each namespace and simulates their actions by invoking the methods.
```cpp
int main() {
    Robot robotA = Burger::createRobot();  
    Robot robotB = Husky::createRobot();  

    std::cout << "Simulating actions for " << robotA.name << ":\n";
    robotA.moveForward();
    robotA.stop();
    robotA.moveBackward();
    robotA.stop();

    std::cout << "\nSimulating actions for " << robotB.name << ":\n";
    robotB.moveForward();
    robotB.stop();
    robotB.moveBackward();
    robotB.stop();

    return 0;
}
```

### How to Run
**1. Compile the Code:**
```
g++ -o T1_code.cpp
```

**2. Run the Executable:**
```
./T1_code
```

## Conclusion
Task 1 shows a simple simulation of robot movements using C++. It uses OOP principles to define the robot's attributes and behaviors, and namespaces to organize different types of robots. The simulation can be extended further to include more complex behaviors and additional types of robots.


# Task 2
## Code Structure

The Code is structured as follows:

- **Robot Class Definition**
- **Namespaces for Robot Creation**
- **Main Function for Simulation**

### Robot Class Definition

The `Robot` class defines the attributes and methods for a robot. It includes:
- **Attributes:**
  - `name`: The name of the robot.
  - `speed`: The speed of the robot.
  - `Physical`: A nested structure that includes `weight`, `sizeH` (height), `sizeW` (width), `sizeL` (length), and `numberOfSensors`.
  - `Sensors`: A nested structure that includes arrays for temperature and distance values.

- **Methods:**
  - `moveForward()`: Simulates the robot moving forward.
  - `moveBackward()`: Simulates the robot moving backward.
  - `stop()`: Simulates the robot stopping.
  - `displaySensorData(int index)`:  Displays the sensor data for the given index.


```cpp
#include <iostream>
#include <string>
#include <array>

class Robot {
public:
    std::string name;
    double speed;

    struct Physical {
        double weight;
        double sizeH;
        double sizeW;
        double sizeL;
        int numberOfSensors;

        Physical(double w, double h, double wdt, double l, int nos) 
            : weight(w), sizeH(h), sizeW(wdt), sizeL(l), numberOfSensors(nos) {}
    };

    struct Sensors {
        std::array<double, 3> temperatures;
        std::array<double, 3> distances;

        Sensors(std::array<double, 3> temps, std::array<double, 3> dists) 
            : temperatures(temps), distances(dists) {}

        void displaySensorData(int index) {
            std::cout << "Temperature: " << temperatures[index] << "°C" << std::endl;
            std::cout << "Distance: " << distances[index] << " cm" << std::endl;
        }
    };

    Physical physical;
    Sensors sensors;

    Robot(std::string n, double s, double w, double h, double wdt, double l, int nos, std::array<double, 3> temps, std::array<double, 3> dists) 
        : name(n), speed(s), physical(w, h, wdt, l, nos), sensors(temps, dists) {}

    void moveForward() {
        std::cout << name << " is moving forward at speed " << speed << " m/s." << std::endl;
    }

    void moveBackward() {
        std::cout << name << " is moving backward at speed " << speed << " m/s." << std::endl;
    }

    void stop() {
        std::cout << name << " has stopped." << std::endl;
    }

    void displaySensorData(int index) {
        sensors.displaySensorData(index);
    }
};
```
### Namespaces for Robot Creation
Namespaces Burger and Husky are used to define the specific robots and their attributes. Each namespace includes a createRobot function that returns a Robot object.

```cpp
namespace Burger {
    Robot createRobot() {
        return Robot("Burger", 0.22, 1.2, 138, 178, 192, 3, {20.0, 21.5, 20.0}, {100.0, 95.0, 100.0});
    }
}
```
### Main Function for Simulation
The main function instantiates the robots using the createRobot functions from each namespace and simulates their actions by invoking the methods.
```cpp
int main() {
    Robot robot = Burger::createRobot();

    std::cout << "Sensor readings for " << robot.name << " before moving forward:\n";
    robot.displaySensorData(0);

    r+obot.moveForward();
    robot.stop();

    std::cout << "Sensor readings for " << robot.name << " after stopping:\n";
    robot.displaySensorData(1);

    robot.moveBackward();
    robot.stop();

    std::cout << "Sensor readings for " << robot.name << " after moving backward and stopping:\n";
    robot.displaySensorData(2);

    return 0;
}

```

### How to Run
**1. Compile the Code:**
```
g++ -o T2_code.cpp
```

**2. Run the Executable:**
```
./T2_code
```
## Conclusion
Task 2 demonstrates a simple simulation of a robot equipped with temperature and distance sensors using C++. The program leverages OOP principles to define the robot's attributes and behaviors, and namespaces to organize different types of robots. The simulation can be extended further to include more complex behaviors and additional types of robots.


# Task 3
## Code Structure

The Code is structured as follows:

- **Robot Class Definition**
- **Namespaces for Robot Creation**
- **Main Function for Simulation**

### Robot Class Definition

The `Robot` class defines the attributes and methods for a robot. It includes:
- **Attributes:**
  - `reading`: The current reading of the sensor.

- **Methods:**
  - `displayReading()`: A pure virtual function to display the sensor reading. Specialized for - `double`, std::string, and char.

```cpp
//Sensor.h
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

```
## TemperatureSensor and DistanceSensor Class Definitions

These classes inherit from the Sensor template class and implement the displayReading method to provide specific functionality for temperature and distance readings.

TemperatureSensor.h

```cpp
// include/TemperatureSensor.h
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

```
DistanceSensor.h

```cpp
// include/DistanceSensor.h
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
```
## Main Function for Simulation
The main function instantiates the TemperatureSensor and DistanceSensor classes and simulates obtaining and displaying readings from these sensors.

main.cpp

```cpp
//main.cpp
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

```

### How to Build and Run

**1. 1. Create the Directory Structure:**
```
mkdir -p T3_files/src
```

**2. Place the header and source files in the appropriate directories**

**3. Create the CMakeLists.txt file in the robot_simulation directory:**
```
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(SensorSimulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(T3_files
    src/main.cpp
    src/Sensor.h
    src/TemperatureSensor.h
    src/DistanceSensor.h
)
```
**4. 4. Build the Project Using CMake:**
```
cd T3_files
mkdir build
cd build
cmake ..
make
```
## Conclusion
Task 3 demonstrates a simple simulation of sensors using C++. It leverages OOP principles to define the sensor attributes and behaviors using templates. The simulation can be extended further to include more complex behaviors and additional types of sensors.
