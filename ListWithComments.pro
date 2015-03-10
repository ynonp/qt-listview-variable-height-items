#-------------------------------------------------
#
# Project created by QtCreator 2015-03-10T07:29:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ListWithComments
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    listitem.cpp \
    mymodel.cpp \
    mydelegate.cpp

HEADERS  += mainwindow.h \
    listitem.h \
    mymodel.h \
    mydelegate.h

FORMS    += mainwindow.ui
