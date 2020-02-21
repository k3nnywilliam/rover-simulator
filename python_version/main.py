'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''

from rover import Rover
from plateau import Plateau

def main():
    orientation = 'n'
    x = 1
    y = 2
    px = 5
    py = 5
    instruction = 'lmlmlmlmm'

    #instruction = input("Please enter your instruction:")

    r = Rover(instruction, orientation, x, y, px, py)
    plt = Plateau(x, y)
    
    print(f"Initial orientation:{r.orientation}")
    print(f"Initial x: {r.x},y: {r.y}")
    r.moveRover()
    print(f"Final x: {r.x},y: {r.y}, orientation: {r.orientation}")


if __name__ == "__main__":
    main()