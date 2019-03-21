#pragma once

#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QTimer>

class CellManager;

class ControlPanel : public QLabel
{
    Q_OBJECT
public:

    ControlPanel();

public slots:
    void startStop();
    void reset();

protected slots:
    void makeNextStep();

signals:
    void nextStep();
    void clearCells();

protected:
    QPushButton startStopButton;
    //QLCDNumber iterationCounter;
    QTimer timer;
};
