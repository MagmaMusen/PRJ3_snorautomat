#include "mainwindow.h"
#include "tekst2.h"
#include "auxsignals.h"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QFocusEvent>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include <QProgressBar>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow;

    w->show();



    return a.exec();
}
