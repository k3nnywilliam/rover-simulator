//Written by Kenny William Nyallau © 2020

#ifndef ROVER_H
#define ROVER_H

#include <iostream>
#include <vector>

namespace ken {

class Rover
{
public:
    Rover();

    int x;
    int y;
    bool commandIsDone = false;

    void setRoverName(std::string& new_name);
    void setPosition(int& set_x, int& set_y, int &px, int &py, char set_orientation='N');
    void ExecuteRoverCommand(std::string& curr_command);
    void isValidInstruction(std::string& string_instruction);
    void isValidCoordinateX(int& x);
    void isValidCoordinateY(int& y);
    void isValidOrientation(char& orient);

 private:
    std::string name = "Rover";
    char orientation = 'N';
    char rover_instruction;
    int plateau_x;
    int plateau_y;
    int reset_x = 0;
    int reset_y = 0;

    void moveRover();
    void moveForward();
    void rotateRoverLeft();
    void rotateRoverRight();
    void savePreviousPosition(int &cur_x, int &curr_y);
    void resetPosition();
    void setCommand(char& curr_instruction);
    void initiateCommand();
    void isRoverOnPlateau();
    void commandCompleted();
};

}



#endif // ROVER_H
