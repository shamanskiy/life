#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cellManager(40,40),
    cellDrawer(cellManager),
    controlPanel(),
    patternSelector()
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

    QFile styleFile(":/data/style.qss");
    styleFile.open(QFile::ReadOnly);
    setStyleSheet(QString::fromLatin1(styleFile.readAll()));
    styleFile.close();

    connect(&controlPanel,SIGNAL(nextStep()),&cellManager,SLOT(computeNextStep()));
    connect(&controlPanel,SIGNAL(nextStep()),&cellDrawer,SLOT(update()));
    connect(&controlPanel,SIGNAL(clearCells()),&cellManager,SLOT(clear()));
    connect(&controlPanel,SIGNAL(clearCells()),&cellDrawer,SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_Space)
        controlPanel.startStop();

    if (event->key()==Qt::Key_C)
        controlPanel.reset();

    event->accept();
}

