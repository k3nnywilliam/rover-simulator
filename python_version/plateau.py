'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''

class Plateau:
    def __init__(self, r1_x, r1_y):
        self.r1_x = r1_x
        self.r1_y = r1_y

    def __checkIfPositionOccupied(self):
        if(self.r1_x == self.r2_x and self.r1_y == self.r2_y):
            print("This position has been occupied")
            self.r2_x = 0
            self.r2_y = 0

