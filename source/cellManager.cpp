#include "cellManager.h"

#include <QDebug>

CellManager::CellManager(int xSize, int ySize) :
    m_xSize(xSize),
    m_ySize(ySize),
    cells(xSize*ySize,false)
{}

void CellManager::computeNextStep()
{
    std::vector<bool> newCells(m_xSize*m_ySize);

    for (int i = 0; i < m_xSize; ++i)
        for (int j = 0; j < m_ySize; ++j)
            if (numberOfNeighbours(i,j) == 3)
                newCells[j*m_xSize+i] = true;
            else if (numberOfNeighbours(i,j) == 2 && checkCell(i,j))
                newCells[j*m_xSize+i] = true;
            else
                newCells[j*m_xSize+i] = false;

    cells = newCells;
}

void CellManager::clickCell(int x, int y)
{
    if (x >= 0 && x < m_xSize && y >= 0 && y < m_ySize)
        cells[y*m_xSize+x] = !cells[y*m_xSize+x];
    else
        qWarning() << "Invalid cell indices: (" << x << "," << y
                   << "). Cell field size is (" << m_xSize << "," << m_ySize << ").";
}

bool CellManager::checkCell(int x, int y) const
{
    if (x >= 0 && x < m_xSize && y >= 0 && y < m_ySize)
        return cells[y*m_xSize+x];
    else
    {
        qWarning() << "Invalid cell indices: (" << x << "," << y
                   << "). Cell field size is (" << m_xSize << "," << m_ySize << ").";
        return false;
    }
}

void CellManager::clear()
{
    std::fill(cells.begin(),cells.end(),false);
}

int CellManager::numberOfNeighbours(int x, int y) const
{
    int number = 0;

    if (cells[y*m_xSize + (x+1)%m_xSize])
        number++;
    if (cells[((y+1)%m_ySize)*m_xSize + (x+1)%m_xSize])
        number++;
    if (cells[((y+1)%m_ySize)*m_xSize + x])
        number++;
    if (cells[((y+1)%m_ySize)*m_xSize + (x-1+m_xSize)%m_xSize])
        number++;
    if (cells[y*m_xSize + (x-1+m_xSize)%m_xSize])
        number++;
    if (cells[((y-1+m_ySize)%m_ySize)*m_xSize + (x-1+m_xSize)%m_xSize])
        number++;
    if (cells[((y-1+m_ySize)%m_ySize)*m_xSize + x])
        number++;
    if (cells[((y-1+m_ySize)%m_ySize)*m_xSize + (x+1)%m_xSize])
        number++;

    return number;
}
