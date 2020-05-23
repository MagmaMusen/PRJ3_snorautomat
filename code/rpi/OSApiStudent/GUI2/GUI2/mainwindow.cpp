#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderropelengthwindow.h"
#include "paymentwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    showOrderRopeLengthWindow();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showOrderRopeLengthWindow()
{

    orderRopeLengthWindow *m = new orderRopeLengthWindow;
    m->show();
}
