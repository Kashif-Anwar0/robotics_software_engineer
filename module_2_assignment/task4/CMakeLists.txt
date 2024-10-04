cmake_minimum_required(VERSION 3.8)
project(task4)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)  # Add geometry_msgs dependency

add_executable(turtlesim_dynamic src/turtlesim_dynamic.cpp)
ament_target_dependencies(turtlesim_dynamic rclcpp std_msgs geometry_msgs)  # Add geometry_msgs to dependencies

install(TARGETS
  turtlesim_dynamic
  DESTINATION lib/${PROJECT_NAME})

ament_package()

