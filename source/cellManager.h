#pragma once

#include <vector>
#include <QObject>

class CellManager : public QObject
{
    Q_OBJECT

public:
    CellManager(int xSize, int ySize);

public:
    // toggle the cell
    void clickCell(int x, int y);
    // get the status of the cell
    bool checkCell(int x, int y) const;

    int xSize() { return m_xSize; }
    int ySize() { return m_ySize; }

public slots:
    // compute the next generation of cells
    void computeNextStep();
    // set all cells to dead/false
    void clear();

protected:
    int numberOfNeighbours(int x, int y) const;

protected:
    int m_xSize;
    int m_ySize;
    std::vector<bool> cells;
};

