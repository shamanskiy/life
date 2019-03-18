#pragma once

#include <vector>

class CellManager
{

public:
    CellManager(int xSize, int ySize);

public:
    // compute the next generation of cells
    void computeNextStep();
    // toggle the cell
    void clickCell(int x, int y);
    // get the status of the cell
    bool checkCell(int x, int y) const;
    // set all cells to dead/false
    void clear();

    int xSize() { return m_xSize; }
    int ySize() { return m_ySize; }

protected:
    int numberOfNeighbours(int x, int y) const;

protected:
    int m_xSize;
    int m_ySize;
    std::vector<bool> cells;
};

