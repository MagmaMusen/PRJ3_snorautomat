#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firstwindowsignal.h"
#include <QtEvents>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(600,600);
    //Create the 3 buttons with names
    buttonFivePositive_ = new QPushButton("+20", this);
    buttonFiveNegative_ = new QPushButton("-20", this);
    buttonDecline_ = new QPushButton("Decline", this);
    buttonAccept_ = new QPushButton("Accept", this);

    //Create a LineEdit object
    LE1_ = new QLineEdit("Indtast den onsket laengde snor", this);

    //Create a spinbox where the length of the rope is going to be showed
    ropeLength_ = new QSpinBox(this);

    //AuxSignal creates so there can establish connection between the buttons and the spinBox
    //and change the value in the spinBox continuously
    firstWindowSignal *fWS = new firstWindowSignal;

    //Sets the geometry for the 3 buttons
    buttonFivePositive_->setGeometry(10,80,80,30);
    buttonFiveNegative_->setGeometry(140, 80, 80, 30);

    //buttonAccept_->setGeometry(270, 10, 80, 30);
    buttonDecline_->setGeometry(400, 80, 80, 30);
    buttonAccept_->setGeometry(270, 80, 80, 30);

    //Set the LineEdit to Read Only
    LE1_->setReadOnly(true);

    //Set the LineEdit's geometry
    LE1_->setGeometry(10, 10, 340, 30);
    
    
    //Set the ropeLength_
    ropeLength_->setGeometry(10, 140, 80, 30);
    ropeLength_->setRange(0, maximumRopeLength);
    ropeLength_->setReadOnly(true);
    ropeLength_->setValue(0);

    //Set the suffix to cm
    ropeLength_->setSuffix(" cm");


    //Connect button FivePositive_ to ropeLength_
    connect(buttonFivePositive_, SIGNAL(clicked()),
            fWS, SLOT(buttonFivePositiveClicked()));
    connect(fWS, SIGNAL(valueChangedPositive(int)),
            ropeLength_, SLOT(setValue(int)));


    //Connect buttonFiveNegative_ to ropeLength_

    connect(buttonFiveNegative_, SIGNAL(clicked()),
            fWS, SLOT(buttonFiveNegativeClicked()));
    connect(fWS, SIGNAL(valueChangedNegative(int)),
            ropeLength_, SLOT(setValue(int)));


    //reset to 0

    connect(buttonDecline_, SIGNAL(clicked()),
            fWS, SLOT(buttonCancelClicked()));
    connect(fWS, SIGNAL(valueReset(int)),
            ropeLength_, SLOT(setValue(int)));

 //Accept button is pressed and should go to new window
    connect(buttonAccept_, SIGNAL(clicked()),
            this, SLOT(openPaymentWindow()));
}
    
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openPaymentWindow()
{
    paymentWindow *m = new paymentWindow();
    hide();
    m->show();
}

