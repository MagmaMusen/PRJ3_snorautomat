#include "snorwindow.h"
#include "auxsignals.h"
#include "ui_snorwindow.h"
#include "globals.h"
#include <mainwindow.h>
#include <QPushButton>
#include <iostream>
#include <mainwindow.h>
#include <QLineEdit>
#include <string.h>
snorWindow::snorWindow(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::snorWindow)

{
    ui->setupUi(this);

    setFixedSize(600, 600);

    // set the price for the rope
    price = ropeLength *2;
    youNeedToPay_ = new QLineEdit("Du mangler at betale",this);



    AuxSignals *auxSignal = new AuxSignals;

    //Creating a SpinBox to show how much money the customer is missing to pay for the rope
    whatYouAreMissingToPay_ = new QDoubleSpinBox(this);

    //Creating all crown buttons
    fiftyCents_ = new QPushButton("50 Ore", this);
    oneCrown_ = new QPushButton("1 kr.", this);
    twoCrowns_ = new QPushButton("2kr.", this);
    fiveCrowns_ = new QPushButton("5kr.", this);
    tenCrowns_ = new QPushButton("10kr.", this);
    twentyCrowns_ = new QPushButton("20kr.", this);

    //Set the geometry for all crowns
    fiftyCents_->setGeometry(10, 40, 80, 30);
    oneCrown_->setGeometry(80, 40, 80, 30);
    twoCrowns_->setGeometry(150, 40, 80, 30);
    fiveCrowns_->setGeometry(220, 40, 80, 30);
    tenCrowns_->setGeometry(290, 40, 80, 30);
    twentyCrowns_->setGeometry(360, 40, 80, 30);

    //Set the geometry for Spinbox and Text to spinBox
    youNeedToPay_->setGeometry(10, 80, 240, 30);
    whatYouAreMissingToPay_->setGeometry(200, 80, 80, 30);


    //Sets to Read only
    youNeedToPay_->setReadOnly(true);
    whatYouAreMissingToPay_->setReadOnly(true);

    //Sets range to negative at the mimum so it also can handle exchange.
    //And set the maximum twice as big as the range in
    whatYouAreMissingToPay_->setRange(-20, 200);
    whatYouAreMissingToPay_->setSuffix("kr.");


    //Beginning at the total price for the rope
    whatYouAreMissingToPay_->setValue(price );


    //Connect the fiftyCent button to payment // callBack
    connect(fiftyCents_, SIGNAL(clicked()),
            auxSignal, SLOT(buttonFiftyOreClicked()));
    connect(auxSignal, SIGNAL(valueChangedNegativeFiftyOre(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

    //Connect the oneCrown button to payment //callBack
    connect(oneCrown_, SIGNAL(clicked()),
            auxSignal, SLOT(buttonOneCrownClicked()));
    connect(auxSignal, SIGNAL(valueChangedNegativeOne(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

    //Connect the twoCrown button to payment
    connect(twoCrowns_, SIGNAL(clicked()),
            auxSignal, SLOT(buttonTwoCrownClicked()));
    connect(auxSignal, SIGNAL(valueChangedNegativeTwo(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

    //Connect the fiveCrown button to payment
    connect(fiveCrowns_, SIGNAL(clicked()),
            auxSignal, SLOT(buttonFiveCrownClicked()));
    connect(auxSignal, SIGNAL(valueChangedNegativeFive(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

    //Connect the tenCrown button to payment
    connect(tenCrowns_, SIGNAL(clicked()),
            auxSignal, SLOT(buttonTenCrownClicked()));
    connect(auxSignal, SIGNAL(valueChangedNegativeTen(double)),
            whatYouAreMissingToPay_, SLOT(setValue(double)));

    //Connect the twentyCrown button to payment
     connect(twentyCrowns_, SIGNAL(clicked()),
             auxSignal, SLOT(buttonTwentyCrownClicked()));
     connect(auxSignal, SIGNAL(valueChangedNegativeTwenty(double)),
             whatYouAreMissingToPay_, SLOT(setValue(double)));

}
snorWindow::~snorWindow()
{
    delete ui;
}
void snorWindow::on_cancelButton_clicked()
{
    //MainWindow::showWindowOne();
    hide();


}
