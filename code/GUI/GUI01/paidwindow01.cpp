#include "paidwindow01.h"
#include "ui_paidwindow01.h"
#include "globals01.h"
paidWindow01::paidWindow01(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::paidWindow01)
{
    ui->setupUi(this);

    //Create the spinbox for the amount of rope and money the costumer will get
    amountMoneyBack_ = new QDoubleSpinBox(this);
    ropeBack_ = new QSpinBox(this);

    //Create the lineEdit where the text is added
    amountMoneyText_ = new QLineEdit("Bytte penge tilbage", this);
    ropeBackText_ = new QLineEdit("Snor der bliver udleveret", this);

    //set the Geometry for the spinBoxs and LineEdits
    amountMoneyBack_->setGeometry(240, 50, 100, 30);
    ropeBack_->setGeometry(240, 10, 100, 30);

    amountMoneyText_->setGeometry(0, 50, 240, 30);
    ropeBackText_->setGeometry(0, 10, 240, 30);

    //Set the suffix to cm and kr.
    ropeBack_->setSuffix(" cm");
    amountMoneyBack_->setSuffix(" kr.");

    //Set to read only
    amountMoneyBack_->setReadOnly(true);
    ropeBack_->setReadOnly(true);

    amountMoneyText_->setReadOnly(true);
    ropeBackText_->setReadOnly(true);

    //Set the range of the spinboxes
    amountMoneyBack_->setRange(-20, 20);
    ropeBack_->setRange(0, maximumRopeLength);


    //Set the values to the global variabels
    ropeBack_->setValue(ropeLength);
    amountMoneyBack_->setValue(price * -1);

}

paidWindow01::~paidWindow01()
{
    delete ui;
}
