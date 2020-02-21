'''
Written by Kenny William Nyallau ©2020
This is a python implementation of Rover challenge
'''
import re

class Rover:
    def __init__(self):
        self.instruction = ""
        self.__arr_instruction = []
        self.orientation = ""
        self.x = 0
        self.y = 0
        self.__save_x = 0
        self.__save_y = 0
        self.px = 0
        self.py = 0
        self.name =""

    def setRoverName(self):
        name = input("Please name your Rover:")
        self.name = name

    
    def setCoordinatesAndOrientation(self):
        
        while(True):
            
            x, y, orientation = input(f"Please enter {self.name}'s x,y, orientation:").split()

            self.x = int(x)
            self.y = int(y)
            self.orientation = orientation.upper()

            valid_orientation = "NSWEnswe"
            ori = re.findall(orientation, valid_orientation)
            if(int(x) < 0 or int(y) < 0):
                print("Invalid coordinates!")
            elif(int(x) >=0 and ori or int(y) >=0 and ori):
                break
            else:
                print("Invalid coordinates and/or orientation!")

    
    def setInstruction(self):
        
        cond = True
        
        while(cond):

            instruction = input(f"Please enter {self.name}'s' instruction:")

            self.instruction = instruction.upper()
            valid_instruction = "LRMlrm"

            self.__arr_instruction = [self.__arr_instruction 
        for self.__arr_instruction in self.instruction]

            for i in range(len(self.__arr_instruction)):
                val_inst = re.findall(self.__arr_instruction[i], valid_instruction)
                
                if(val_inst):
                    cond = False
                else:
                    print("Invalid instruction.")


    def setPlateauCoordinates(self, px, py):
        self.px = px
        self.py = py

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