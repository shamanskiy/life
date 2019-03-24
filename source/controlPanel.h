#pragma once

#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>
#include <QSlider>

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
    QPushButton startStopButton;
    QLCDNumber iterationCounter;
    QTimer timer;
    QSlider slider;

    int numIterations;
};
