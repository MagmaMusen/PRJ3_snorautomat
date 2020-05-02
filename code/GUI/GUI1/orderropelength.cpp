#include "orderropelength.h"
#include "ui_orderropelength.h"

orderropelength::orderropelength(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::orderropelength)
{
    ui->setupUi(this);
}

orderropelength::~orderropelength()
{
    delete ui;
}
