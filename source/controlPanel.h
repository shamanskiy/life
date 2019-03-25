#pragma once

#include <QLabel>
#include <QLCDNumber>
#include <QTimer>
#include <QSlider>

#include "source/customButton.h"

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
    int numIterations;

    // left group
    CustomButton saveButton, loadButton, printScreenButton, saveMovieButton, resetButton, fullScreenButton;

    // central group
    CustomButton startStopButton, fullBackButton, fullForwardButton, reverseButton, extraButton;
    QSlider navigationSlider;
    QLabel iterationCounterCurrent, iterationCounterTotal;

    // right group
    QLabel slowIcon, fastIcon;
    QSlider speedSlider;
};
