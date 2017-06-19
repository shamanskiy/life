#include "CellManager.h"

#include <QDebug>

CellManager::CellManager() :
    xSize(0),
    ySize(0),
    cells(),
    stepTimer(),
    activeState(false)
{

}

CellManager::CellManager(int _xSize, int _ySize, int speed) :
    xSize(_xSize),
    ySize(_ySize),
    cells(),
    stepTimer(),
    activeState(false)
{
    stepTimer.setInterval(speed);
    cells.reserve(xSize*ySize);
    for (int i=0; i<xSize; i++)
    {
        for (int j=0; j<ySize; j++)
        {
            cells.push_back(LifeCell(i,j));
        }
    }
    connect(&stepTimer,SIGNAL(timeout()),SLOT(countNextStep()));
}

CellManager::~CellManager()
{
    stepTimer.stop();
}

bool CellManager::isActive()
{
    return activeState;
}

void CellManager::start()
{
    stepTimer.start();
    activeState=true;
}

void CellManager::stop()
{
    stepTimer.stop();
    activeState=false;
}

void CellManager::toggle()
{
    if(activeState)
    {
        stop();
    }
    else
    {
        start();
    }
}

LifeCell* CellManager::getCell(int xCoord, int yCoord)
{
    if (xCoord < xSize || yCoord < ySize)
    {
        return &(cells[xCoord + yCoord*xSize]);
    }
    else
    {
        return &(cells[0]);
        emit error();
    }

}

bool CellManager::checkCell(int x, int y)
{
    return getCell(x,y)->isAlive();
}

void CellManager::setTimerSpeed(int newSpeed)
{
    if (newSpeed > 0)
    {
        stepTimer.setInterval(newSpeed);
    }
}

void CellManager::countNextStep()
{
    QVector<LifeCell> newCells=cells;

    for (int i=0; i<xSize; i++){
        for (int j=0; j<ySize; j++){
            if (!getCell(i,j)->isAlive() && numberOfNeighbours(i,j)==3)
            {
                newCells[j*xSize+i].birth();
            }
            /*if (!getCell(i,j)->isAlive() && numberOfNeighbours(i,j)!=3)
            {
                newCells[j*xSize+i].death();
            }
            if (getCell(i,j)->isAlive() && numberOfNeighbours(i,j)==2 || numberOfNeighbours(i,j)==3)
            {
                newCells[j*xSize+i].birth();
            }*/
            if (getCell(i,j)->isAlive() && numberOfNeighbours(i,j)<2 || numberOfNeighbours(i,j)>3)
            {
                newCells[j*xSize+i].death();
            }

        }
    }
    cells = newCells;
    emit drawMe();
}

int CellManager::numberOfNeighbours(int x, int y)
{
    int number = 0;
    if (x!=0 && y!=0 && x!=xSize-1 && y!=ySize-1){
        if (getCell(x-1,y-1)->isAlive()){
            number++;
        }
        if (getCell(x,y-1)->isAlive()){
            number++;
        }
        if (getCell(x+1,y-1)->isAlive()){
            number++;
        }
        if (getCell(x+1,y)->isAlive()){
            number++;
        }
        if (getCell(x+1,y+1)->isAlive()){
            number++;
        }
        if (getCell(x,y+1)->isAlive()){
            number++;
        }
        if (getCell(x-1,y+1)->isAlive()){
            number++;
        }
        if (getCell(x-1,y)->isAlive()){
            number++;
        }
    }
    return number;
}

void CellManager::clickCell(int x, int y)
{
    if (getCell(x,y)->isAlive())
    {
        getCell(x,y)->death();
    }
    else
    {
        getCell(x,y)->birth();
    }
    emit drawMe();
}

void CellManager::clear()
{
    stepTimer.stop();
    for(int i=0; i<xSize; i++)
    {
        for(int j=0;j<ySize;j++)
        {
            if (getCell(i,j)->isAlive())
            {
                getCell(i,j)->death();
            }
        }
    }
    emit drawMe();
}
