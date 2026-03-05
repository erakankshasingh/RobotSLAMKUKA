# RobotSLAMKUKA

A ROS-based robotics workspace focused on **simulation, robot modelling, and perception-driven motion control** using **C++**, **Gazebo**, and **RViz**.

This repository demonstrates practical work in:
- ROS package development
- robot modelling with URDF
- Gazebo-based simulation
- image-driven robot behavior in C++
- service/topic-based node communication

## Project Overview

The workspace includes multiple ROS packages for building and simulating a mobile robot system and implementing a simple perception-to-action pipeline.

The main technical focus areas are:

- **Custom robot simulation** with URDF, Gazebo, and RViz
- **ROS C++ node development**
- **Image-based object tracking / chasing behavior**
- **Service-oriented robot motion control**
- **Hands-on robotics workflow in a Catkin workspace**

## Main Packages

### `my_robot`
Contains the robot simulation assets and configuration, including:
- launch files
- URDF files
- meshes
- RViz configuration
- Gazebo world files

### `ball_chaser`
Implements a simple vision-based chasing behavior in C++:
- `process_image.cpp` processes camera input
- `drive_bot.cpp` publishes motion commands
- `DriveToTarget.srv` defines the service interface
- `ball_chaser.launch` launches the package components

### `simple_arm`
Additional robotics package included in the workspace.

### `first_package`
Starter / practice ROS package included in the workspace.

## Tech Stack

- **ROS (Catkin workspace)**
- **C++**
- **Gazebo**
- **RViz**
- **URDF**
- **CMake**


## Prerequisites

- Ubuntu with ROS1 (Catkin workspace)
- Gazebo with `gazebo_ros` packages
- RViz

## Build

From the workspace root:

```bash
catkin_make
source devel/setup.bash
```

## Run

### Start the robot simulation

```bash
roslaunch my_robot world.launch
```
### Start the ball chaser behavior

```bash
roslaunch ball_chaser ball_chaser.launch
```
```markdown
## What This Project Demonstrates
- This project highlights my hands-on work in:
- Robotics software development with ROS packages and Catkin
- C++ implementation of ROS nodes and services, and topic-based control
- Integrating perception input with robot control
- Simulation-based testing and validation
- Structuring based testing and validation using Gazebo and RViz

## Repository Structure
```text
RobotSLAMKUKA/
├── src/
│   ├── ball_chaser/
│   ├── my_robot/
│   ├── simple_arm/
│   ├── first_package/
│   └── CMakeLists.txt
└── devel/
```
## Notes
- This repository is intended as a practical robotics portfolio project and reflects hands-on development in ROS, Gazebo, and C++-based robot behavior implementation.
