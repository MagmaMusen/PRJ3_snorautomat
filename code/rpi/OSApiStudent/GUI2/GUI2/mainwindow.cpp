#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderropelengthwindow.h"
#include "paymentwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //orderRopeLengthWindow *m = new orderRopeLengthWindow;
    //m->show();
    //paymentWindow *w = new paymentWindow;
    //w->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
