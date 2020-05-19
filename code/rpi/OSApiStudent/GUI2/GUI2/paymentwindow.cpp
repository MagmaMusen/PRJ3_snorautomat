#include "paymentwindow.h"
#include "ui_paymentwindow.h"
#include "orderropelengthwindow.h"
#include "paidwindow.h"
#include "communicationtomaincontroller.h"
paymentWindow::paymentWindow(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::paymentWindow)
{
    ui->setupUi(this);

    // set the price for the rope
    price = ropeLength *2;
    youNeedToPay_ = new QLineEdit("Du mangler at betale",this);

    //QPushButton *test = new QPushButton("test", this);
    //test->setGeometry(400, 400, 30, 30);

    //secondWindowSignal *sWS = new secondWindowSignal;

     //Creating a SpinBox to show how much money the customer is missing to pay for the rope
    whatYouAreMissingToPay_ = new QDoubleSpinBox(this);

    //Creating all crown buttons
    decline_ = new QPushButton("Annulere", this);



    //Set the geometry for all crowns
    decline_->setGeometry(10, 120, 80, 30);
    //Set the geometry for Spinbox and Text to spinBox
    youNeedToPay_->setGeometry(10, 80, 240, 30);
    whatYouAreMissingToPay_->setGeometry(200, 80, 100, 30);


    //Sets to Read only
    youNeedToPay_->setReadOnly(true);
    whatYouAreMissingToPay_->setReadOnly(true);

    //Sets range to negative at the mimum so it also can handle exchange.
    //And set the maximum twice as big as the range in
    whatYouAreMissingToPay_->setRange(-20, maximumRopeLength*2);
    whatYouAreMissingToPay_->setSuffix(" kr.");


    //Beginning at the total price for the rope
    whatYouAreMissingToPay_->setValue(price);


    amountReached();

}

paymentWindow::~paymentWindow()
{
    delete ui;
}

void paymentWindow::openOrderRopeLengthWindow()
{
    orderRopeLengthWindow *m = new orderRopeLengthWindow;
    ropeLength = 0;
    hide();
    m->show();
}
void paymentWindow::openPaidWindow()
{
    //price er en global variabel,
    //som ogsaa er koblet til spinboksen 'whatYouAreMissingToPay_'
    if(price < 0.5)
    {
        paidWindow *m = new paidWindow;
        hide();
        m->show();
        //communicationToMainController *cTMC = new communicationToMainController;

    }

}
void paymentWindow::cancelButtonClickedCommunicationToMainControllerClass()
{
    //communicationToMainController *cTMC = new communicationToMainController;
    //cTMC->cancelFromGUIHandle();
}
void paymentWindow::cancelButtonClicked()
{
    connect(decline_, SIGNAL(clicked()),
            this, SLOT(openOrderRopeLengthWindow()));
    connect(decline_, SIGNAL(clicked()),
            this, SLOT(cancelButtonClickedCommunicationToMainControllerClass()));
}
void paymentWindow::amountReached()
{
    connect(whatYouAreMissingToPay_, SIGNAL(valueChanged(double)),
                this, SLOT(openPaidWindow()));
}

