//Written by Kenny William Nyallau © 2020

#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <vector>

namespace ken {

class Plateau
{
public:
    Plateau();
    int plateau_x;
    int plateau_y;

    void getPlateauCoordinates();
    void setPlateauCoordinates(int& curr_x, int& curr_y);
    void checkValidCoordinates(int& r_x, int& r_y, int& p_x, int& p_y);
    bool checkifPositionOccupied(int& r1_x, int& r1_y, int& r2_x, int& r2_y);
};

}


#endif // PLATEAU_H
