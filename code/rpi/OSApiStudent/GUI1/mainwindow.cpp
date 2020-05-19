#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firstwindowsignal.h"
#include "orderropelengthwindow.h"
//#include "guimsgqueue.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QEventLoop w;
    presentOrderRopeLength();


    
    
    
    w.exec();


}
void MainWindow::presentOrderRopeLength()
{
    orderRopeLengthWindow *m = new orderRopeLengthWindow;
    m->show();
}
void MainWindow::presentPaymentWindow()
{
    paymentWindow *m = new paymentWindow;
    m->show();
}
