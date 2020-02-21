'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''

from rover import Rover
from plateau import Plateau

def main():

    x, y, orientation = input("Please enter x,y, orientation:").split()
    px, py = input("Please set a size for the Plateau:").split()
    instruction = input("Please enter your instruction:")

    r = Rover(instruction, orientation, x, y, px, py)
    plt = Plateau(x, y)
    
    print(f"Initial x: {r.x},y: {r.y}, orientation: {r.orientation}")
    r.moveRover()
    print(f"Final x: {r.x},y: {r.y}, orientation: {r.orientation}")


if __name__ == "__main__":
    main()