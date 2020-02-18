//Written by Kenny William Nyallau © 2020

#include <iostream>
#include <string>
#include "rover.h"
#include "plateau.h"


void test() {

    int p_x, p_y;
    int r1_x, r1_y;
    char r1_orient;

    ken::Plateau plt;
    ken::Rover r1;

    std::cout<<"-------WELCOME TO ROVER SIMULATOR--------"<<std::endl;
    std::cout<<"Please name your Rover: ";
    std::string r1_name;
    getline(std::cin, r1_name);
    r1.setRoverName(r1_name);
    std::cout<<std::endl;

    std::cout<<"Please set an instruction for "<<r1_name<<
               " for example: L for left, R for right, M for move forward."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Please enter "<<r1_name<<"'s instruction (i.e. LMLMLMLMM):"<<std::endl;
    std::string r1_cmd;
    getline(std::cin, r1_cmd);
    r1.isValidInstruction(r1_cmd);

    std::cout<<"Your input instruction is: "<<r1_cmd<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Please set starting x,y coordinates and also orientation for "<<r1_name<<std::endl;
    std::cout<<"For example, "<<std::endl;
    std::cout<<"x: 1 "<<std::endl;
    std::cout<<"y: 2 "<<std::endl;
    std::cout<<"Orientation: N"<<std::endl;
    std::cout<<"(N for north, S for south, E for east, W for west)"<<std::endl;
    std::cout<<std::endl;

    r1.isValidCoordinateX(r1_x);
    r1.isValidCoordinateY(r1_y);
    r1_orient = toupper(r1_orient);
    r1.isValidOrientation(r1_orient);
    std::cout<<std::endl;

    plt.checkValidCoordinates(r1_x, r1_y, p_x, p_y);
    r1.setPosition(r1_x, r1_y, p_x, p_y, r1_orient);
    plt.setPlateauCoordinates(p_x, p_y);
    r1.ExecuteRoverCommand(r1_cmd);

    //if(r1.commandIsDone == true) {
    //    r2.ExecuteRoverCommand(r2_cmd);
    //}

}


int main()
{
    test();
    return  0;
}
