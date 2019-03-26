#include "controlPanel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QLayout>

#include "colorScheme.h"

ControlPanel::ControlPanel():
    QLabel(),
    timer(),
    baseSpeed(200),
    numIterations(0),
    // left group
    saveButton(":/data/save.svg"),
    loadButton(":/data/load.svg"),
    printScreenButton(":/data/screen.svg"),
    saveMovieButton(":/data/movie.svg"),
    resetButton(":/data/reset.svg"),
    fullScreenButton(":/data/fullscreen.svg"),
    // central group
    startStopButton(":/data/play.svg",25),
    fullBackButton(":/data/fullback.svg"),
    stepBackButton(":/data/stepback.svg"),
    stepForwardButton(":/data/stepforward.svg"),
    fullForwardButton(":/data/fullforward.svg"),
    navigationSlider(Qt::Horizontal),
    iterationCounterCurrent(),
    iterationCounterTotal(),
    // right group
    speedLabel(),
    speedButton(":/data/speed.svg"),
    speedSlider(Qt::Horizontal),
    reverseButton(":/data/reverse.svg")
{
    setMinimumHeight(100);
    setMaximumHeight(100);
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(LIFE_LIGHT_GRAY)));


    timer.setInterval(baseSpeed);
    connect(&timer,SIGNAL(timeout()),SLOT(makeNextStep()));

    QHBoxLayout * mainLayout = new QHBoxLayout;
    QWidget * leftGroup = new QWidget;
    QWidget * centralGroup = new QWidget;
    QWidget * rightGroup = new QWidget;

    mainLayout->addWidget(leftGroup);
    mainLayout->addWidget(centralGroup);
    mainLayout->addWidget(rightGroup);
    this->setLayout(mainLayout);

    QGridLayout * leftGroupLayout = new QGridLayout;
    leftGroupLayout->addWidget(&saveButton,0,0);
    leftGroupLayout->addWidget(&loadButton,1,0);
    leftGroupLayout->addWidget(&printScreenButton,0,1);
    leftGroupLayout->addWidget(&saveMovieButton,1,1);
    leftGroupLayout->addWidget(&resetButton,0,2);
    leftGroupLayout->addWidget(&fullScreenButton,1,2);
    leftGroup->setLayout(leftGroupLayout);

    connect(&resetButton,SIGNAL(clicked()),SLOT(reset()));

    QGridLayout * centralGroupLayout = new QGridLayout;
    centralGroupLayout->addWidget(&startStopButton,0,3);
    centralGroupLayout->addWidget(&fullBackButton,0,1);
    centralGroupLayout->addWidget(&stepBackButton,0,2);
    centralGroupLayout->addWidget(&stepForwardButton,0,4);
    centralGroupLayout->addWidget(&fullForwardButton,0,5);
    centralGroupLayout->addWidget(&navigationSlider,1,1,1,5);
    centralGroupLayout->addWidget(&iterationCounterCurrent,1,0);
    centralGroupLayout->addWidget(&iterationCounterTotal,1,6);
    centralGroup->setLayout(centralGroupLayout);

    connect(&startStopButton,SIGNAL(clicked()),SLOT(startStop()));

    iterationCounterCurrent.setText(QString::number(numIterations));
    iterationCounterCurrent.setMinimumWidth(40);
    iterationCounterCurrent.setAlignment(Qt::AlignRight);
    iterationCounterTotal.setText(QString::number(numIterations));
    iterationCounterTotal.setMinimumWidth(40);

    QGridLayout * rightGroupLayout = new QGridLayout;
    rightGroupLayout->addWidget(&reverseButton,0,0);
    rightGroupLayout->addWidget(&speedButton,0,1);
    rightGroupLayout->addWidget(&speedLabel,0,3);
    rightGroupLayout->addWidget(&speedSlider,0,2);
    rightGroup->setLayout(rightGroupLayout);

    speedLabel.setAlignment(Qt::AlignHCenter);

    speedLabel.setText(QString::number(baseSpeed)+"ms");
    speedLabel.setMinimumWidth(50);
    speedSlider.setMinimumWidth(70);
    speedSlider.setMinimum(10);
    speedSlider.setMaximum(100);
    connect(&speedSlider,SIGNAL(valueChanged(int)),SLOT(changeSpeed(int)));
    speedSlider.setValue(10000/baseSpeed);
}

void ControlPanel::startStop()
{
    if (timer.isActive())
    {
        timer.stop();
        startStopButton.setIcon(":/data/play.svg");
    }
    else
    {
        timer.start();
        startStopButton.setIcon(":/data/pause.svg");
    }

}

void ControlPanel::reset()
{
    emit clearCells();
    numIterations = 0;
    changeSpeed(10000/baseSpeed);
    speedSlider.setValue(10000/baseSpeed);
    iterationCounterCurrent.setText(QString::number(0));
    iterationCounterTotal.setText(QString::number(0));
    startStop();
    if (timer.isActive())
    {
        timer.stop();
        startStopButton.setIcon(":/data/play.svg");
    }
}

void ControlPanel::makeNextStep()
{
    emit nextStep();
    numIterations++;
    iterationCounterCurrent.setText(QString::number(numIterations));
    iterationCounterTotal.setText(QString::number(numIterations));
}

void ControlPanel::changeSpeed(int newSpeed)
{
    timer.setInterval(10000/newSpeed);
    speedLabel.setText(QString::number(int(10000/newSpeed))+"ms");
}
