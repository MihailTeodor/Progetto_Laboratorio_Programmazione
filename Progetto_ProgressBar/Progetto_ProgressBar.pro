#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T19:24:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto_ProgressBar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileloader.cpp

HEADERS  += mainwindow.h \
    fileloader.h \
    subject.h \
    observer.h \
    progressbar.h \
    bitprogressbar.h

FORMS    += mainwindow.ui
