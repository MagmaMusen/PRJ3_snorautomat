#-------------------------------------------------
#
# Project created by QtCreator 2020-04-16T09:50:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    paymentwindow.cpp \
    globals.cpp \
    firstwindowsignal.cpp \
    paidwindow.cpp \
    secondwindowsignal.cpp

HEADERS += \
        mainwindow.h \
    paymentwindow.h \
    globals.h \
    firstwindowsignal.h \
    paidwindow.h \
    secondwindowsignal.h

FORMS += \
        mainwindow.ui \
    paymentwindow.ui \
    paidwindow.ui


target.path = /home/root
INSTALLS += target
# Default rules for deployment.
export(INSTALLS)

#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target