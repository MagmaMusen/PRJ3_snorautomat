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

    w.show();

    return a.exec();
}
