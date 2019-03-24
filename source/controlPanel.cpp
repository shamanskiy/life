#include "controlPanel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QLayout>

ControlPanel::ControlPanel():
    QLabel(),
    startStopButton(),
    iterationCounter(),
    timer(),
    numIterations(0)
{
    setMinimumHeight(60);
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::blue)));

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(&startStopButton);
    layout->addWidget(&iterationCounter);
    this->setLayout(layout);

    timer.setInterval(400);
    connect(&timer,SIGNAL(timeout()),SLOT(makeNextStep()));


    startStopButton.setIcon(QIcon(":/data/play.svg"));
    startStopButton.setMaximumWidth(50);
    startStopButton.setMaximumHeight(50);
    startStopButton.setIconSize(QSize(50,50));
    connect(&startStopButton,SIGNAL(clicked()),SLOT(startStop()));

}

void ControlPanel::startStop()
{
    if (timer.isActive())
    {
        timer.stop();
        startStopButton.setIcon(QIcon(":/data/play.svg"));
    }
    else
    {
        timer.start();
        startStopButton.setIcon(QIcon(":/data/pause.svg"));
    }

}

void ControlPanel::reset()
{
    emit clearCells();
    numIterations = 0;
    iterationCounter.display(0);
    startStop();
    if (timer.isActive())
    {
        timer.stop();
        startStopButton.setIcon(QIcon(":/data/play.svg"));
    }
}

void ControlPanel::makeNextStep()
{
    emit nextStep();
    numIterations++;
    iterationCounter.display(numIterations);
}
