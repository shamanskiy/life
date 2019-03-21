#include "patternSelector.h"

#include <QPainter>
#include <QMouseEvent>

PatternSelector::PatternSelector():
   QLabel()
{
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::green)));
}

void PatternSelector::drawMesh(QPainter &painter)
{

}

void PatternSelector::paintEvent(QPaintEvent *event)
{

}

void PatternSelector::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    update();
}
