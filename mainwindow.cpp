#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cellManager(30,30),
    cellDrawer(cellManager),//,this),
    controlPanel(),//this),
    patternSelector(),//this),
    timer()
{
    ui->setupUi(this);
    ui->mainToolBar->setVisible(false);
    ui->statusBar->hide();
    setWindowTitle("Life");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(&cellDrawer,0,0);
    layout->addWidget(&controlPanel,1,0);
    layout->addWidget(&patternSelector,0,1,2,1);
    QWidget* widget = new QWidget;
    layout->setSpacing(0);
    layout->setMargin(0);
    widget->setLayout(layout);
    setCentralWidget(widget);

    timer.setInterval(100);
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
