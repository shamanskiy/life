#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cellManager(30,30),
    cellDrawer(cellManager,this),
    timer()
{
    ui->setupUi(this);
    ui->mainToolBar->setVisible(false);
    setWindowTitle("Life");
    setCentralWidget(&cellDrawer);
    move(QPoint(50,50));
    setPalette(QPalette(QColor(Qt::black)));

    timer.setInterval(400);
    connect(&timer,SIGNAL(timeout()),SLOT(nextStep()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_Space)
    {
        if (timer.isActive())
            timer.stop();
        else
            timer.start();
    }

    if (event->key()==Qt::Key_C)
    {
        timer.stop();
        cellManager.clear();
        cellDrawer.update();
    }
    event->accept();
}

void MainWindow::nextStep()
{
    cellManager.computeNextStep();
    cellDrawer.update();
}
