//Written by Kenny William Nyallau © 2020

#include "plateau.h"

namespace ken {

Plateau::Plateau()
{

}


void Plateau::getPlateauCoordinates()
{
    std::cout<<"Plateau coordinates are x: "<<plateau_x<<","<<" y: "<<plateau_y<<std::endl;
}


void Plateau::setPlateauCoordinates(int& curr_x, int& curr_y)
{

    plateau_x = curr_x;
    plateau_y = curr_y;

    std::cout<<"Setting plateau coordinates at x: "<<plateau_x<<","<<" y: "<<plateau_y<<std::endl;
}

void Plateau::checkValidCoordinates(int& r_x, int& r_y, int& p_x, int& p_y)
{
    while (r_x > p_x || r_y > p_y)
    {
        std::cout<<"Please initialize the x,y coordinates of the Plateau: "<<std::endl;
        std::cout<<"x: ";
        std::cin>>p_x;
        std::cout<<"y: ";
        std::cin>>p_y;
        std::cout<<std::endl;

        if (r_x > p_x || r_y > p_y) {
            std::cout<<"ERROR: Invalid coordinates!!!";
            std::cout<<"Make sure the plateau is big enough for the Rover to move around!"<<std::endl;
            std::cout<<std::endl;
        }

    }
}


//This is to check if a particular position on the plateau is occupied by another rover
bool Plateau::checkifPositionOccupied(int& r1_x, int& r1_y, int& r2_x, int& r2_y)
{
    bool occupied = false;

    if (r1_x == r2_x && r1_y == r2_y){
        std::cout<<"I think the rovers need to stay clear from each other!"<<std::endl;
        return occupied = true;
    }
    else {
        std::cout<<"Rovers are moving around safely!"<<std::endl;
        occupied = false;
    }

    return occupied;
}



}


