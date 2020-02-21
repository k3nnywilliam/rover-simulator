'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''
import re

class Rover:

    def __init__(self, instruction, orientation, x, y, px, py):
        self.instruction = instruction.upper()
        self.__arr_instruction = []
        self.orientation = orientation.upper()
        self.x = int(x)
        self.y = int(y)
        self.__save_x = x
        self.__save_y = y
        self.px = int(px)
        self.py = int(py)

    
    def checkValidInstruction(self):
        
        cond = True
        
        while(cond):
            valid_instruction = "LRMlrm"

            self.__arr_instruction = [self.__arr_instruction 
        for self.__arr_instruction in self.instruction]

            for i in range(len(self.__arr_instruction)):
                val_inst = re.findall(self.__arr_instruction[i], valid_instruction)
                
                if(val_inst):
                    cond = False
                else:
                    print("Invalid instruction.")
                    instruction = input("Please enter your instruction:")
                    self.instruction = instruction


    def __parseInstruction(self):
        self.__arr_instruction = [self.__arr_instruction 
        for self.__arr_instruction in self.instruction]


    def moveRover(self):

        self.__parseInstruction()
        
        for i in range(len(self.__arr_instruction)):
            if(self.__arr_instruction[i] == 'L'):
                self.__rotateLeft()
            elif(self.__arr_instruction[i] == 'R'):
                self.__rotateRight()
            elif(self.__arr_instruction[i]=='M'):
                self.__moveForward()
                self.__checkIsOutOfMap()


    def __rotateLeft(self):
        compass = {
            'N':'W',
            'W':'S',
            'S':'E',
            'E':'N'
        }
        self.orientation = compass.get(self.orientation)


    def __rotateRight(self):
        compass = {
            'N':'E',
            'E':'S',
            'S':'W',
            'W':'N'
        }
        self.orientation = compass.get(self.orientation)

    def __moveForward(self):

        if(self.orientation == 'N'):
            self.y = self.y + 1
        if(self.orientation == 'W'):
            self.x = self.x - 1
        if(self.orientation == 'S'):
            self.y = self.y - 1
        if(self.orientation == 'E'):
            self.x = self.x + 1


    def __resetToStartPosition(self):
            self.x = self.__save_x
            self.y = self.__save_y
            print("Reseting to start position.")


    def __checkIsOutOfMap(self):
        if(self.x < 0 or self.y < 0):
            print("Rover is out of map!")
            self.__resetToStartPosition()
        elif(self.x > self.px or self.y > self.py):
            print("Rover is out of map!")
            self.__resetToStartPosition()