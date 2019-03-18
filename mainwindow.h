#pragma once

#include <QMainWindow>
#include <QTimer>

#include "source/cellDrawer.h"
#include "source/cellManager.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *event);

protected slots:
    void nextStep();

protected:
    Ui::MainWindow *ui;
    CellManager cellManager;
    CellDrawer cellDrawer;
    QTimer timer;
};

