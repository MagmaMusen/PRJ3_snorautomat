#include "mainwindow01.h"
#include "ui_mainwindow01.h"
#include "orderropelengthwindow01.h"
MainWindow01::MainWindow01(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow01)
{
    ui->setupUi(this);
    openOrderRopeWindow();
}

MainWindow01::~MainWindow01()
{
    delete ui;
}
void MainWindow01::openOrderRopeWindow()
{
    orderRopeLengthWindow01 *m = new orderRopeLengthWindow01;
    m->show();
}
