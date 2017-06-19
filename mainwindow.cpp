#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cellSize(20),
    xSize(60),
    ySize(40),
    defaultSpeed(500),
    cellManager(xSize,ySize,defaultSpeed)
{
    cellField = new CellField(xSize,ySize,cellSize,&cellManager,this);
    ui->setupUi(this);
    ui->mainToolBar->setVisible(false);
    setWindowTitle("Life");
    setCentralWidget(cellField);
    move(QPoint(50,50));
    setPalette(QPalette(QColor(Qt::black)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_Space){
        cellManager.toggle();
    }
    if (event->key()==Qt::Key_C)
    {
        cellManager.clear();
    }
    event->accept();
}
