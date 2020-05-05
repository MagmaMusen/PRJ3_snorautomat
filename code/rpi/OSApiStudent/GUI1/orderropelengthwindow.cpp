#include "orderropelengthwindow.h"
#include "ui_orderropelengthwindow.h"

orderRopeLengthWindow::orderRopeLengthWindow(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::orderRopeLengthWindow)
{
    ui->setupUi(this);
}

orderRopeLengthWindow::~orderRopeLengthWindow()
{
    delete ui;
}
