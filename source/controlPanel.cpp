#include "controlPanel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

ControlPanel::ControlPanel():
    QLabel(),
    startStopButton(this),
    //iterationCounter(),
    timer()
{
    setMinimumHeight(30);
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::blue)));

    timer.setInterval(100);
    connect(&timer,SIGNAL(timeout()),SLOT(makeNextStep()));

    startStopButton.setText("Start");
    connect(&startStopButton,SIGNAL(clicked()),SLOT(startStop()));
}

void ControlPanel::startStop()
{
    if (timer.isActive())
    {
        timer.stop();
        startStopButton.setText("Start");
    }
    else
    {
        timer.start();
        startStopButton.setText("Stop");
    }

}

void ControlPanel::reset()
{
    emit clearCells();
}

void ControlPanel::makeNextStep()
{
    emit nextStep();
}
