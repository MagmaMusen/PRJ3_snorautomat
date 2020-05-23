#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "orderropelengthwindow1.h"
MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    openOrderRopeWindow();
}

MainWindow1::~MainWindow1()
{
    delete ui;
}
void MainWindow1::openOrderRopeWindow()
{
    orderRopeLengthWindow1 *m = new orderRopeLengthWindow1;
    m->show();
}
