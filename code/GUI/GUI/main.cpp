#include "mainwindow.h"
#include <QApplication>
#include <X11/X.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


   /* paymentWindow g;
    g.show();
    */return a.exec();
}
