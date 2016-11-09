#-------------------------------------------------
#
# Project created by QtCreator 2015-04-19T17:19:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = V3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    license.cpp

HEADERS  += mainwindow.h \
    license.h \
    thread.h

FORMS    += mainwindow.ui \
    license.ui

RESOURCES += \
    dll.qrc
