'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''
from rover import Rover
from plateau import Plateau
import re

def main():
    
    while(True):
        x, y, orientation = input("Please enter x,y, orientation:").split()
        valid_orientation = "NSWEnswe"
        ori = re.findall(orientation, valid_orientation)
        if(int(x) < 0 or int(y) < 0):
            print("Invalid coordinates!")
        elif(int(x) >=0 and ori or int(y) >=0 and ori):
            break
        else:
            print("Invalid coordinates and/or orientation!")
            
    
    while(True):
        px, py = input("Please set a size for the Plateau:").split()
        
        if(int(x) > int(px) or int(y) > int(py)):
            print("Invalid. Plateau too small for Rovers!")
        elif(int(px) <=0 or int(py) <=0):
            print("Invalid. Plateau too small for Rovers!")
        else:
            break

    plt = Plateau(x, y, px, py)
    instruction = input("Please enter your instruction:")
    r = Rover(instruction, orientation, x, y, px, py)
    r.checkValidInstruction()
        
    print(f"Initial x: {r.x},y: {r.y}, orientation: {r.orientation}")
    r.moveRover()
    print(f"Final x: {r.x},y: {r.y}, orientation: {r.orientation}")


if __name__ == "__main__":
    main()