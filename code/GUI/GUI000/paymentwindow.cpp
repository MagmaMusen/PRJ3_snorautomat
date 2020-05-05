#include "paymentwindow.h"
#include "ui_paymentwindow.h"
#include "paidwindow.h"
#include "secondwindowsignal.h"
#include "globals.h"
#include "orderropelength.h"
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
    fiftyCents_ = new QPushButton("50 Ore", this);
    oneCrown_ = new QPushButton("1 kr.", this);
    twoCrowns_ = new QPushButton("2 kr.", this);
    fiveCrowns_ = new QPushButton("5 kr.", this);
    tenCrowns_ = new QPushButton("10 kr.", this);
    twentyCrowns_ = new QPushButton("20 kr.", this);

    decline_ = new QPushButton("Annulere", this);



    //Set the geometry for all crowns
    fiftyCents_->setGeometry(10, 40, 80, 30);
    oneCrown_->setGeometry(80, 40, 80, 30);
    twoCrowns_->setGeometry(150, 40, 80, 30);
    fiveCrowns_->setGeometry(220, 40, 80, 30);
    tenCrowns_->setGeometry(290, 40, 80, 30);
    twentyCrowns_->setGeometry(360, 40, 80, 30);

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
    cancelButtonClicked();
    fiftyOreClicked();
    oneCrownClicked();
    twoCrownClicked();
    fiveCrownClicked();
    tenCrownClicked();
    twentyCrownClicked();
}

void paymentWindow::openOrderRopeLengthWindow()
{
    orderRopeLength *m = new orderRopeLength;
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
    }
}
void paymentWindow::cancelButtonClicked()
{
    connect(decline_, SIGNAL(clicked()),
            this, SLOT(openOrderRopeLengthWindow()));
}
void paymentWindow::amountReached()
{
    connect(whatYouAreMissingToPay_, SIGNAL(valueChanged(double)),
                this, SLOT(openPaidWindow()));
}
void paymentWindow::fiftyOreClicked()
{
    connect(fiftyCents_, SIGNAL(clicked()),
            this, SLOT(buttonFiftyOreClicked()));
    connect(this, SIGNAL(valueChangedNegativeFiftyOre(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

}
void paymentWindow::oneCrownClicked()
{
    connect(oneCrown_, SIGNAL(clicked()),
            this, SLOT(buttonOneCrownClicked()));
    connect(this, SIGNAL(valueChangedNegativeOne(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));
}
void paymentWindow::twoCrownClicked()
{
    connect(twoCrowns_, SIGNAL(clicked()),
            this, SLOT(buttonTwoCrownClicked()));
    connect(this, SIGNAL(valueChangedNegativeTwo(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));
}
void paymentWindow::fiveCrownClicked()
{
    connect(fiveCrowns_, SIGNAL(clicked()),
            this, SLOT(buttonFiveCrownClicked()));
    connect(this, SIGNAL(valueChangedNegativeFive(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));
}
void paymentWindow::tenCrownClicked()
{
    connect(tenCrowns_, SIGNAL(clicked()),
            this, SLOT(buttonTenCrownClicked()));
    connect(this, SIGNAL(valueChangedNegativeTen(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));
}
void paymentWindow::twentyCrownClicked()
{
    connect(twentyCrowns_, SIGNAL(clicked()),
            this, SLOT(buttonTwentyCrownClicked()));
    connect(this, SIGNAL(valueChangedNegativeTwenty(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

}
paymentWindow::~paymentWindow()
{
    delete ui;
}
