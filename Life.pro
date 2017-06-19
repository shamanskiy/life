#-------------------------------------------------
#
# Project created by QtCreator 2014-08-17T22:53:02
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=gnu++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Life
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    source/CellManager.cpp \
    source/LifeCell.cpp \
    source/CellField.cpp \
    source/ControlPanel.cpp

HEADERS  += mainwindow.h \
    source/CellManager.h \
    source/LifeCell.h \
    source/CellField.h \
    source/ControlPanel.h

FORMS    += mainwindow.ui
