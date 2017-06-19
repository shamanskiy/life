#ifndef LIFECELL_H
#define LIFECELL_H

#include <QPainter>
#include <QPoint>

class LifeCell
{

public:
    LifeCell();
    LifeCell(int xCoord,int yCoord);
    ~LifeCell();




private:
    int xCoord;
    int yCoord;
    bool alive;

public:
    bool isAlive();
    void death();
    void birth();

    int rx();
    int ry();



signals:


public slots:

};



#endif // LIFECELL_H
