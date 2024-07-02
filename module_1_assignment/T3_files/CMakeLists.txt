# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(RobotSimulation)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(robot_simulation
    src/main.cpp
    src/Sensor.cpp
    src/TemperatureSensor.cpp
    src/DistanceSensor.cpp
)
