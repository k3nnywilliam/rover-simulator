//Written by Kenny William Nyallau © 2020

#include "rover.h"

namespace ken {

Rover::Rover()
{

}


void Rover::setRoverName(std::string& new_name) {
    name = new_name;
}

void Rover::setPosition(int& set_x, int& set_y, int& px, int& py, char set_orientation)
{
    x = set_x;
    y = set_y;
    plateau_x = px;
    plateau_y = py;
    orientation = set_orientation;

    std::cout<<"Setting "<<name<<"'s starting position at x: "<<set_x<<", y: "<<set_y<<" and facing "<<set_orientation<<std::endl;

}


void Rover::moveRover()
{
    savePreviousPosition(x, y);

    if (rover_instruction == 'L') {
        rotateRoverLeft();
    }
    if (rover_instruction == 'R') {
        rotateRoverRight();
    }
    if (rover_instruction == 'M') {
        moveForward();
    }
}


//We move forward based on which "north" that the rover's nose is facing
void Rover::moveForward(){

    switch (orientation) {

    case 'N' : y = y + 1;
        break;
    case 'W' : x = x - 1;
        break;
    case 'S' : y = y - 1;
        break;
    case 'E' : x = x + 1;
        break;
    }

    std::cout<<name<<" is moving forward..."<<std::endl;
    std::cout<<name<<"'s position is at x: "<< x <<", y: "<<y<<" and facing "<< orientation <<std::endl;

}

//We rotate left by assuming our north is moving counter clockwise
void Rover::rotateRoverLeft()
{
    switch (orientation) {

    case 'N' : orientation = 'W';
        break;
    case 'W' : orientation = 'S';
        break;
    case 'S' : orientation = 'E';
        break;
    case 'E' : orientation = 'N';
        break;
    }

    std::cout<<name<<" is rotating left..."<<std::endl;

}


//We rotate right by assuming our north is moving clockwise
void Rover::rotateRoverRight()
{
    switch (orientation) {

    case 'N' : orientation = 'E';
        break;
    case 'W' : orientation = 'N';
        break;
    case 'S' : orientation = 'W';
        break;
    case 'E' : orientation = 'S';
        break;
    }

    std::cout<<name<<" is rotating right..."<<std::endl;

}

//We save previous known valid position in case we went into an invalid position
void Rover::savePreviousPosition(int &curr_x, int &curr_y)
{
   reset_x = curr_x;
   reset_y = curr_y;
}


//This resets back to previous known valid position
void Rover::resetPosition()
{
    x = reset_x;
    y = reset_y;

    std::cout<<"Reseting to x: "<<reset_x<<", y: "<<reset_y<<std::endl;
}

void Rover::ExecuteRoverCommand(std::string& curr_command)
{
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"Executing rover command for "<<name<<std::endl;

    //We force the string instruction to use uppercase only
    std::transform(curr_command.begin(), curr_command.end(), curr_command.begin(), ::toupper);

    //we slice the string and performs each of the char instructions
    int n = curr_command.length();
    char command_array[n + 1];
    strcpy(command_array, curr_command.c_str());


    for (int i = 0; i < n;){
        setCommand(command_array[i]);
        initiateCommand();
        i++;
    }

    commandCompleted();

    std::cout<<name<<" has arrived. Final destination is x: "<<x <<", y: "<<y<<" and facing "<<orientation<<std::endl;

}

void Rover::isValidInstruction(std::string& string_instruction){
    while (string_instruction.find_first_not_of("LRMlrm") != std::string::npos) {
        std::cout<<"Error! Please enter a valid instruction (i.e. MRMMLMMR): "<<std::endl;
        getline(std::cin, string_instruction);
    }
}


void Rover::isValidCoordinateX(int& x){

    bool cond;
    do
       {
          std::cout<<"Please enter "<<name<<"'s x coordinate:"<<std::endl;
          std::cin >> x;

          cond = std::cin.fail();

          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');

       }while(cond);
}

void Rover::isValidCoordinateY(int& y)
{
    bool cond;

    do
       {
          std::cout<<"Please enter "<<name<<"'s y coordinate:"<<std::endl;
          std::cin >> y;

          cond = std::cin.fail();

          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');

       }while(cond);
}

void Rover::isValidOrientation(char& orient)
{
    while (!(orient == 'N' || orient == 'S' || orient == 'E' || orient == 'W'
           || orient == 'n' || orient == 's' || orient == 'e' || orient == 'w'))
    {
        std::cout<<"Please enter a valid orientation:"<<std::endl;
        std::cin>>orient;
        orient = toupper(orient);
    }

}


void Rover::setCommand(char& curr_instruction)
{
    rover_instruction = curr_instruction;
}

void Rover::initiateCommand()
{
    moveRover();
    isRoverOnPlateau();
}

void Rover::commandCompleted()
{
   bool *cmd_done;
   cmd_done = &commandIsDone;
   *cmd_done = true;
}

void Rover::isRoverOnPlateau()
{
    if (x < 0 || y < 0) {
       std::cout<<"WARNING: Rover is off the map! Your expected final destination may be affected!"<<std::endl;
       resetPosition();
    }
    else if (x > plateau_x || y > plateau_y){
       std::cout<<"WARNING: Rover is off the map! Your expected final destination may be affected!"<<std::endl;
       resetPosition();
    }
}




}


