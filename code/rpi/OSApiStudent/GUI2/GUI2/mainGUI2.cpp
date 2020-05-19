#include "mainwindow.h"
#include <QApplication>
#include "paymentwindow.h"
#include "fakereceivergui.h"
#include "communicationtomaincontroller.h"
#include <osapi/Thread.hpp>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPushButton hej("HELLO THERE");
    hej.setGeometry(100,100,100,100);
    hej.show();
    //w.show();

    fakeReceiverGUI fR;
    communicationToMainController *cM;
    osapi::Thread *threads;


    osapi::Thread g1(&fR);

    g1.start();

    g1.join();
    return a.exec();
}
