#pragma once

#include <QLabel>
#include <QLCDNumber>
#include <QTimer>
#include <QSlider>

#include "iconButton.h"

class CellManager;

class ControlPanel : public QLabel
{
    Q_OBJECT
public:

    ControlPanel();

public slots:
    void startStop();
    void reset();
    void changeSpeed(int newSpeed);

protected slots:
    void makeNextStep();

signals:
    void nextStep();
    void clearCells();

protected:
    QTimer timer;
    int baseSpeed;
    int numIterations;

    // left group
    IconButton saveButton, loadButton, printScreenButton, saveMovieButton, resetButton, fullScreenButton;

    // central group
    IconButton startStopButton, fullBackButton, stepBackButton, stepForwardButton, fullForwardButton;
    QSlider navigationSlider;
    QLabel iterationCounterCurrent, iterationCounterTotal;

    // right group
    IconButton speedButton, reverseButton;
    QLabel speedLabel;
    QSlider speedSlider;
};
