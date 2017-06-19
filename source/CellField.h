#ifndef CELLFIELD_H
#define CELLFIELD_H

#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>

#include "source/CellManager.h"

class CellField : public QLabel
{
    Q_OBJECT
public:
    explicit CellField(QWidget *parent = 0);
    CellField(int _xSize, int _ySize, int _cellSize, CellManager* _cellManager, QWidget *parent = 0);
    ~CellField();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    void drawMesh(QPainter& painter);
    void drawCell(int x, int y, QPainter& painter);

private:
    int xSize;
    int ySize;
    int cellSize;
    CellManager* cellManager;
signals:

public slots:

};

#endif // CELLFIELD_H
