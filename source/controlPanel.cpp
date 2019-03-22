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
    numIterations = 0;
    iterationCounter.display(0);
    startStop();
    if (timer.isActive())
    {
        timer.stop();
        startStopButton.setText("Start");
    }
}

void ControlPanel::makeNextStep()
{
    emit nextStep();
    numIterations++;
    iterationCounter.display(numIterations);
}
