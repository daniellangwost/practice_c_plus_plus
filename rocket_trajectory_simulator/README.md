# Rocket trajectory simulator

## Purpose
This project was created to practice C++ skills in conjunction with an actual application in rocketry physics. It focuses on the use of classes specifically.

## Overview
This project seeks to implement a rocket trajectory simulator that takes in an initial velocity and angle and then writes the trajectory over the next 100 seconds into a csv file.

Furthermore, a simple function is implemented to adjust the rocket's guidance based on a target altitude set by the user.

## Implementation details
To simulate the trajectory, the program uses a step size of 0.1s (1000 steps in total) and calculates an updated velocity due to gravity after each interval using the midpoint method.
All important data concerning position and velocity is saved into an instance of the Rocket class and modified by its own update() method.

To practice working with multiple files, function prototypes and the basic class functionality are abstracted away into header files (main.h and rocket.h).

## Issues
For shallow approach angles to the target altitude, the function would not increase the velocity enough, causing the rocket to plummet towards the ground. This was solved by implementing a minimum added velocity taking into account how negative the velocity would be after a 1s effect of gravity.

## Test Cases
- 30 m/s, 50°, 30m target → Peak ~31.6m
- 10 m/s, 30°, 5m target → Peak ~5.4m
- 100 m/s, 80°, 200m target → Peak ~494m

## Setup Instructions
Compile with: `g++ -o rocket main.cpp rocket.cpp`  
Run with: `./rocket`

## Future work ideas
In the future, it would be interesting to simulate a similar trajectory that does not only try to surpass a certain altitude, but reach some point as closely as possible, taking limitations of thrust and angle control into account.

Moreover, an adaptive timestep-size could be implemented to try to simulate extreme input cases realistically
