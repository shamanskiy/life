#pragma once

#include <QLabel>

class CellManager;

class CellDrawer : public QLabel
{
    Q_OBJECT
public:

    CellDrawer(CellManager & _cellManager, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    void drawMesh(QPainter& painter);
    void drawCell(int x, int y, QPainter& painter);

protected:
    int cellSize;
    CellManager & cellManager;
    int xSize;
    int ySize;

};
