  cmake_minimum_required(VERSION 3.5)
  project(task1)

  # Find dependencies
  find_package(ament_cmake REQUIRED)
  find_package(rclcpp REQUIRED)
  find_package(geometry_msgs REQUIRED)

  # Add executable for your turtlesim pattern node
  add_executable(turtlesim_pattern src/turtlesim_pattern.cpp)
  ament_target_dependencies(turtlesim_pattern rclcpp geometry_msgs)

  # Install executable
  install(TARGETS
    turtlesim_pattern
    DESTINATION lib/${PROJECT_NAME})

  ament_package()
  # Install launch files
  install(DIRECTORY launch/
    DESTINATION share/${PROJECT_NAME}/launch
  )
