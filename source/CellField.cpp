#include "CellField.h"

CellField::CellField(QWidget *parent) :
    QLabel(parent),
    xSize(0),
    ySize(0),
    cellSize(0),
    cellManager(nullptr)
{
}

CellField::CellField(int _xSize, int _ySize, int _cellSize, CellManager *_cellManager, QWidget *parent):
    QLabel(parent),
    xSize(_xSize),
    ySize(_ySize),
    cellSize(_cellSize),
    cellManager(_cellManager)
{
    setMinimumSize(cellSize*xSize,cellSize*ySize);
    setPalette(QPalette(QColor(Qt::black)));
    connect(cellManager,SIGNAL(drawMe()),SLOT(update()));
}

CellField::~CellField()
{
    cellManager = nullptr;
}

void CellField::drawMesh(QPainter &painter)
{
    QPoint begin,end;
    for (int i=0; i<= xSize;i++){
        begin = QPoint(i*cellSize,0);
        end = QPoint(i*cellSize,ySize*cellSize);
        painter.drawLine(begin,end);
    }

    for (int j=0; j<= ySize;j++){
        begin = QPoint(0,j*cellSize);
        end = QPoint(xSize*cellSize,j*cellSize);
        painter.drawLine(begin,end);
    }
}

void CellField::drawCell(int x, int y, QPainter &painter)
{
    QPoint begin, end;
    begin = QPoint(x*cellSize+1,y*cellSize+1);
    end = QPoint((x+1)*cellSize-2,(y+1)*cellSize-2);
    painter.drawRoundedRect(QRect(begin,end),3,3);
}

void CellField::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::white,0));
    drawMesh(painter);

    painter.setPen(QPen(Qt::green,0));
    painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));

    for (int i=0;i< xSize;i++){
        for (int j=0; j< ySize; j++){
            if (cellManager->checkCell(i,j)){
                drawCell(i,j,painter);
            }
        }
    }
}

void CellField::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        cellManager->clickCell(event->pos().rx()/cellSize,event->pos().ry()/cellSize);
    }
    event->accept();
}
