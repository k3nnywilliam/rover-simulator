'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''

class Plateau:
    def __init__(self):
        self.px = 0
        self.py = 0
        self.x = 0
        self.y = 0
        self.name = ""


    def setRoverCoordinates(self, x, y):
        self.x = x
        self.y = y

    def setPlateauSize(self):

        while(True):
            px, py = input("Please set x, y coordinates for the Plateau:").split()

            self.px = int(px)
            self.py = int(py)
        
            if(int(self.x) > int(self.px) or int(self.y) > int(self.py)):
                print("Invalid. Plateau too small for Rover!")
            elif(int(self.px) <=0 or int(self.py) <=0):
                print("Invalid. Plateau too small for Rover!")
            else:
                break

    def __checkIfPositionOccupied(self, r1_x, r1_y, r2_x, r2_y):
        if(self.r1_x == self.r2_x and self.r1_y == self.r2_y):
            print("This position has been occupied")
            self.r2_x = 0
            self.r2_y = 0

