#-------------------------------------------------
#
# Project created by QtCreator 2017-05-07T13:56:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AI
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    grid.cpp \
    hueristics.cpp \
    piece.cpp \
    search.cpp \
    structures.cpp \
    graphicboard.cpp \
    mythread.cpp

HEADERS  += widget.h \
    grid.h \
    hueristics.h \
    piece.h \
    search.h \
    structures.h \
    graphicboard.h \
    mythread.h

FORMS    += widget.ui

RESOURCES += \
    resources.qrc
