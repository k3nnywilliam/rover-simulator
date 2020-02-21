'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''
from rover import Rover
from plateau import Plateau
import re

def main():

    print("---WELCOME TO ROVER SIMULATOR---")
    rover = Rover()
    plateau = Plateau()

    rover.setRoverName()
    plateau.setPlateauSize()
    rover.setCoordinatesAndOrientation()
    rover.setInstruction()
    plateau.setRoverCoordinates(rover.x, rover.y)
    rover.setPlateauCoordinates(plateau.px, plateau.py)
        
    print(f"{rover.name} is starting at x: {rover.x},y: {rover.y}, orientation: {rover.orientation}")
    rover.moveRover()
    print(f"{rover.name} has arrived at x: {rover.x},y: {rover.y}, orientation: {rover.orientation}")


if __name__ == "__main__":
    main()