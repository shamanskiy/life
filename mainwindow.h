#pragma once

#include <QMainWindow>


#include "source/cellDrawer.h"
#include "source/cellManager.h"
#include "source/controlPanel.h"
#include "source/patternSelector.h"


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

protected:
    Ui::MainWindow *ui;
    CellManager cellManager;
    CellDrawer cellDrawer;
    ControlPanel controlPanel;
    PatternSelector patternSelector;

};

