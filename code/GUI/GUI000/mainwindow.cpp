#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderropelength.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    presentOrderRopeLength();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::presentOrderRopeLength()
{
    hide();
    orderRopeLength *m = new orderRopeLength;
    m->show();
}
