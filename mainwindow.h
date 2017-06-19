#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "source/CellField.h"
#include "source/CellManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int cellSize;
    int xSize;
    int ySize;
    int defaultSpeed;

protected:
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    CellManager cellManager;
    CellField* cellField;
};

#endif // MAINWINDOW_H
