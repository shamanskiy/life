#include "patternSelector.h"

#include <QPainter>
#include <QMouseEvent>

#include "colorScheme.h"

PatternSelector::PatternSelector():
   QLabel()
{
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(LIFE_DARK_GRAY)));
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
