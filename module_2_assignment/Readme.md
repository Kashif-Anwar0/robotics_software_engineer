# ROS2 Turtlesim Assignment - Module 2

## Objective

This assignment focuses on developing custom ROS2 nodes and utilizing launch files to execute multiple nodes simultaneously. The aim is to create a custom ROS2 node that controls the Turtlesim simulation and develop a launch file to run both the simulation and the node concurrently.

## Tasks Overview

### Task 1: Create a Custom ROS2 Node

The first task was to develop a custom ROS2 node that makes the Turtlesim follow unique movement patterns:

- **Circle Movement**: The turtle moves in a circle with a user-defined radius.
- **Logarithmic Spiral Movement**: The turtle follows a logarithmic spiral pattern, with the radius increasing as the turtle moves forward.

**Implementation**: 
- The `turtlesim_pattern.cpp` file was updated to include functionality for user input, allowing the turtle to move either in a circle or a logarithmic spiral based on parameter inputs.
- The node calculates the velocity and angular speed required to follow the respective patterns.

### Task 2: Develop a Launch File

A launch file was created to start both the Turtlesim simulation and the custom ROS2 node simultaneously.

**Implementation**:
- A `launch/turtlesim.launch.py` file was written to initialize the Turtlesim node and the custom node for movement control.
- The launch file was configured to allow parameter adjustments directly from the command line, ensuring flexibility in setting up the turtle's movements (circle radius, spiral increment).

### Task 3: Modify the Turtlesim Simulation Environment

This task required modifying the Turtlesim environment by spawning multiple turtles and controlling their movement.

**Implementation**:
- Using ROS2 services, 5 Turtlebots were spawned in the environment. The turtles were placed diagonally from the top left to the bottom right corner of the screen using a single launch file.
- The middle 3 turtles were programmed to move back and forth continuously by interacting with the ROS2 service `turtle1/cmd_vel` and similar services for the other turtles.

### Task 4: Modify Turtle Behavior with Parameters

The final task involved modifying the turtle's speed dynamically during the simulation using ROS2 parameters.

**Implementation**:
- Parameters were introduced in the node to allow real-time control of the turtle's speed and movement dynamics. By adjusting these parameters, the speed of each turtle could be changed during the simulation without restarting the nodes.
- This was achieved by subscribing to the parameter server, allowing continuous updates to the turtle's behavior as required.

## Learning Outcomes

By completing this assignment, the following objectives were achieved:

- Learned to develop and execute custom nodes in ROS2.
- Gained experience in creating and managing ROS2 launch files.
- Understood how to interact with ROS2 services to modify node behavior and simulation environments.
- Explored using ROS2 parameters to control the behavior of nodes dynamically during simulation.

## Submission Process

1. Created the required custom ROS2 node and launch files inside the `module_2_assignment` package.
2. Documented the code thoroughly to explain how to run the node and launch file.
3. Pushed the changes to the repository.
4. Provided the repository link for submission.
5. Submitted the assignment for review.


