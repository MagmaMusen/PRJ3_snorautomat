#-------------------------------------------------
#
# Project created by QtCreator 2020-05-07T09:37:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI2
TEMPLATE = app
INCLUDEPATH += ../../inc/
LIBS += -L"../../inc" -osapi
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS OS_LINUX

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        mainwindow.cpp \
    orderropelengthwindow.cpp \
    globals.cpp \
    paymentwindow.cpp \
    paidwindow.cpp \
    communicationtomaincontroller.cpp \
    ../../linux/ClockTime.cpp \
    ../../linux/Conditional.cpp \
    ../../linux/Mutex.cpp \
    ../../linux/Semaphore.cpp \
    ../../linux/Thread.cpp \
    ../../linux/ThreadFunctor.cpp \
    ../../linux/Utility.cpp \
    ../../common/Completion.cpp \
    ../../common/Log.cpp \
    ../../common/LogOutputStdOut.cpp \
    ../../common/LogSystem.cpp \
    ../../common/LogTypes.cpp \
    ../../common/Time.cpp \
    ../../common/Timer.cpp \
    fakereceivergui.cpp \
    mainGUI2.cpp

HEADERS += \
        mainwindow.h \
    orderropelengthwindow.h \
    globals.h \
    paymentwindow.h \
    paidwindow.h \
    communicationtomaincontroller.h \
    ../../inc/osapi/ClockTime.hpp \
    ../../inc/osapi/Completion.hpp \
    ../../inc/osapi/Conditional.hpp \
    ../../inc/osapi/ConditionalError.hpp \
    ../../inc/osapi/ConditionalHelper.hpp \
    ../../inc/osapi/Exceptions.hpp \
    ../../inc/osapi/ILogOutput.hpp \
    ../../inc/osapi/Log.hpp \
    ../../inc/osapi/LogOutputStdOut.hpp \
    ../../inc/osapi/LogTypes.hpp \
    ../../inc/osapi/Message.hpp \
    ../../inc/osapi/MsgQueue.hpp \
    ../../inc/osapi/Mutex.hpp \
    ../../inc/osapi/MutexError.hpp \
    ../../inc/osapi/ScopedLock.hpp \
    ../../inc/osapi/Semaphore.hpp \
    ../../inc/osapi/SemaphoreError.hpp \
    ../../inc/osapi/Thread.hpp \
    ../../inc/osapi/ThreadError.hpp \
    ../../inc/osapi/ThreadFunctor.hpp \
    ../../inc/osapi/Time.hpp \
    ../../inc/osapi/Timer.hpp \
    ../../inc/osapi/Utility.hpp \
    fakereceivergui.h

FORMS += \
        mainwindow.ui \
    orderropelengthwindow.ui \
    paymentwindow.ui \
    paidwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
