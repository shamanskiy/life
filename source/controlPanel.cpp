#include "controlPanel.h"

#include <QPainter>
#include <QMouseEvent>

ControlPanel::ControlPanel():
    QLabel()
{
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::blue)));
}


void ControlPanel::paintEvent(QPaintEvent *event)
{

}

void ControlPanel::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    update();
}
