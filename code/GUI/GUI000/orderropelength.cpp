#include "orderropelength.h"
#include "ui_orderropelength.h"
#include "globals.h"

#include "paymentwindow.h"
orderRopeLength::orderRopeLength(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::orderRopeLength)
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
    //firstWindowSignals *fWS = new firstWindowSignals;

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
    /*connect(buttonFivePositive_, SIGNAL(clicked()),
            fWS, SLOT(buttonFivePositiveClicked()));
    connect(fWS, SIGNAL(valueChangedPositive(int)),
            ropeLength_, SLOT(setValue(int)));


    //Connect buttonFiveNegative_ to ropeLength_




    //reset to 0


*/
    acceptButtonClicked();
    plusFiveClicked();
    minusFiveClicked();
    declineClicked();
}

orderRopeLength::~orderRopeLength()
{
    delete ui;
}
void orderRopeLength::openPaymentWindow()
{
    paymentWindow *m = new paymentWindow();
    hide();
    m->show();
}
void orderRopeLength::acceptButtonClicked()
{
    connect(buttonAccept_, SIGNAL(clicked()),
            this, SLOT(openPaymentWindow()));
}
void orderRopeLength::plusFiveClicked()
{
    //firstWindowSignals *fWS = new firstWindowSignals;
    connect(buttonFivePositive_, SIGNAL(clicked()),
                this, SLOT(buttonFivePositiveClicked()));
    connect(this, SIGNAL(valueChangedPositive(int)),
                ropeLength_, SLOT(setValue(int)));

}
void orderRopeLength::minusFiveClicked()
{
    connect(buttonFiveNegative_, SIGNAL(clicked()),
            this, SLOT(buttonFiveNegativeClicked()));
    connect(this, SIGNAL(valueChangedNegative(int)),
            ropeLength_, SLOT(setValue(int)));
}
void orderRopeLength::declineClicked()
{
    connect(buttonDecline_, SIGNAL(clicked()),
            this, SLOT(buttonCancelClicked()));
    connect(this, SIGNAL(valueReset(int)),
            ropeLength_, SLOT(setValue(int)));
}
