#include "controlPanel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QLayout>

ControlPanel::ControlPanel():
    QLabel(),
    timer(),
    numIterations(0),
    // left group
    saveButton(),
    loadButton(),
    printScreenButton(),
    saveMovieButton(),
    resetButton(),
    fullScreenButton(),
    // central group
    startStopButton(),
    fullBackButton(),
    fullForwardButton(),
    reverseButton(),
    extraButton(),
    navigationSlider(Qt::Horizontal),
    iterationCounterCurrent(),
    iterationCounterTotal(),
    // right group
    slowIcon(),
    fastIcon(),
    speedSlider(Qt::Horizontal)
{
    setMinimumHeight(100);
    setMaximumHeight(100);
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(40,40,40)));

    timer.setInterval(100);
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

    //resetButton.setIcon(QIcon(":/data/reset.svg"));
    connect(&resetButton,SIGNAL(clicked()),SLOT(reset()));

    QGridLayout * centralGroupLayout = new QGridLayout;
    centralGroupLayout->addWidget(&startStopButton,0,3);
    centralGroupLayout->addWidget(&fullBackButton,0,2);
    centralGroupLayout->addWidget(&fullForwardButton,0,4);
    centralGroupLayout->addWidget(&reverseButton,0,1);
    centralGroupLayout->addWidget(&extraButton,0,5);
    centralGroupLayout->addWidget(&navigationSlider,1,1,1,5);
    centralGroupLayout->addWidget(&iterationCounterCurrent,1,0);
    centralGroupLayout->addWidget(&iterationCounterTotal,1,6);
    centralGroup->setLayout(centralGroupLayout);

    startStopButton.setIcon(":/data/play.svg",QColor(200,200,200));
    connect(&startStopButton,SIGNAL(clicked()),SLOT(startStop()));

    iterationCounterCurrent.setText(QString::number(numIterations));
    iterationCounterCurrent.setStyleSheet("QLabel {color : #B3B3B3; }");
    iterationCounterCurrent.setMinimumWidth(40);
    iterationCounterCurrent.setAlignment(Qt::AlignRight);
    iterationCounterTotal.setText(QString::number(numIterations));
    iterationCounterTotal.setStyleSheet("QLabel {color : #B3B3B3; }");
    iterationCounterTotal.setMinimumWidth(40);

    QHBoxLayout * rightGroupLayout = new QHBoxLayout;
    rightGroupLayout->addWidget(&slowIcon);
    rightGroupLayout->addWidget(&speedSlider,2);
    rightGroupLayout->addWidget(&fastIcon);
    rightGroup->setLayout(rightGroupLayout);

    slowIcon.setText("slow");
    slowIcon.setStyleSheet("QLabel { color : #B3B3B3; }");
    fastIcon.setText("fast");
    fastIcon.setStyleSheet("QLabel { color : #B3B3B3; }");
    speedSlider.setMinimumWidth(70);
    speedSlider.setMinimum(10);
    speedSlider.setMaximum(100);
    connect(&speedSlider,SIGNAL(valueChanged(int)),SLOT(changeSpeed(int)));
    speedSlider.setValue(70);
}

void ControlPanel::startStop()
{
    if (timer.isActive())
    {
        timer.stop();
        //startStopButton.setIcon(QIcon(":/data/play.svg"));
    }
    else
    {
        timer.start();
        //startStopButton.setIcon(QIcon(":/data/pause.svg"));
    }

}

void ControlPanel::reset()
{
    emit clearCells();
    numIterations = 0;
    iterationCounterCurrent.setText(QString::number(0));
    iterationCounterTotal.setText(QString::number(0));
    startStop();
    if (timer.isActive())
    {
        timer.stop();
        //startStopButton.setIcon(QIcon(":/data/play.svg"));
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
}
