# Rover Simulator

This is a small but fun programming challenge. This is part of my Project 52 (inspired by someone's who inspired to do Project 52). 

**Project 52** is a personal initiative to take on random programming challenge for 52 weeks.

Task
------
The task is to drive a Rover on a plateau given the following user inputs:
- The initial setting of X, Y coordinates of the plateau
- The starting X, Y position and orientation (N, S, E, W) for the Rover
- A set of instructions that allows the Rover to rotate left (L), right (R) and move forward (M).

Example
------
- Plateau x,y coordinates input: 5 5

- Rover's x,y position and orientation input: 1 2 N

- Rover's instruction input: LMLMLMLMM

- Expected output: 1 3 N

### Optional challenge
- The Rover must be roaming around within the range of the plateau
- Try to spawn two rovers and make sure that they are not occupying the same spot on the plateau
- If you are spawning two rovers, the first rover must complete its instruction before executing the instructions for the next rover.


Hint: You can try to plot out the Rover's path on paper first and verify if the Rover is expectedly to arrive at a certain position on the plateau.

License
------
This package is licensed under MIT license. See LICENSE for details.
