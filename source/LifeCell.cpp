#include "LifeCell.h"

LifeCell::LifeCell() :
    xCoord(0),
    yCoord(0),
    alive(true)
{

}

LifeCell::LifeCell(int xCoord, int yCoord):
    xCoord(xCoord),
    yCoord(yCoord),
    alive(false)
{

}

LifeCell::~LifeCell(){

}

bool LifeCell::isAlive(){
    return alive;
}

void LifeCell::death(){
    alive = false;
}

void LifeCell::birth(){
    alive = true;
}

int LifeCell::rx(){
    return xCoord;
}

int LifeCell::ry(){
    return yCoord;
}
