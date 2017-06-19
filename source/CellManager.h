#ifndef CELLMANAGER_H
#define CELLMANAGER_H

#include <QVector>
#include <QTimer>
#include <QObject>

#include "LifeCell.h"

class CellManager: public QObject
{
    Q_OBJECT
public:
    CellManager();
    CellManager(int _xSize, int _ySize, int speed);
    ~CellManager();

private:
    int xSize;
    int ySize;
    QVector<LifeCell> cells;
    QTimer stepTimer;
    bool activeState;



public:
    void setTimerSpeed(int newSpeed);
    void start();
    void stop();
    bool isActive();
    void clickCell(int x, int y);
    void toggle();
    void clear();
    //temporary
    bool checkCell(int x, int y);

private:
    int numberOfNeighbours(int x, int y);
    LifeCell* getCell(int xCoord, int yCoord);

signals:

    void error();
    void drawMe();

private slots:
    void countNextStep();

};

#endif // CELLMANAGER_H
