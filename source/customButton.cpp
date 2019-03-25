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
    slider(Qt::Horizontal),
    numIterations(0)
{
    setMinimumHeight(60);
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(40,40,40)));

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(&slider);
    layout->addWidget(&startStopButton);
    layout->addWidget(&iterationCounter);

    this->setLayout(layout);

    timer.setInterval(100);
    connect(&timer,SIGNAL(timeout()),SLOT(makeNextStep()));


    slider.setMaximumWidth(250);
    slider.setMinimum(50);
    slider.setMaximum(500);
    connect(&slider,SIGNAL(valueChanged(int)),SLOT(changeSpeed(int)));

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

void ControlPanel::changeSpeed(int newSpeed)
{
    timer.setInterval(newSpeed);
}
