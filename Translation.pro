#-------------------------------------------------
#
# Project created by QtCreator 2020-09-16T19:47:17
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Translation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    translationwidget.cpp \
    studywidget.cpp \
    reviewwidget.cpp \
    managewidget.cpp \
    adcs_widget.cpp

HEADERS  += mainwindow.h \
    translationwidget.h \
    studywidget.h \
    reviewwidget.h \
    managewidget.h \
    adcs_widget.h
