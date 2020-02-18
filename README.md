# Rover Simulator

This is a small but fun programming challenge. This is part of my Project 52 (inspired by someone's who inspired to do Project 52). 

**Project 52** is a personal initiative to take on random programming challenge for 52 weeks. In order to have a successful execution of Project 52, you may:
- take on small or big project, but it has to be something new and not just refactoring old projects.
- use whatever programming languages that you want. However, I highly recommend to use more than one programming languages.

**Some advise:**
- It is recommended to implement a complete, minimal but useful software application. You will soon realize that you are building both personal experience and portfolio.
- Just because Project 52 encourages you to write one project per week, it doesn't mean that you have to. For example, if you are able to complete a project in a few days, then you should move on to another project on the same week.
- Try not to embark on too many trivial small and easy projects. Project 52 is supposed to help you gain more skillsets and learn new tricks.
- You could also try to incorporate dynamic programming once in a while. This is a great way to improve your understanding in algorithms and data structures.


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
