#include "orderropelengthwindow01.h"
#include "ui_orderropelengthwindow01.h"
#include "paymentwindow01.h"
orderRopeLengthWindow01::orderRopeLengthWindow01(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::orderRopeLengthWindow01)
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


    acceptButtonClicked();
    plusFiveClicked();
    minusFiveClicked();
    declineClicked();

}

orderRopeLengthWindow01::~orderRopeLengthWindow01()
{
    delete ui;
}
void orderRopeLengthWindow01::openPaymentWindow()
{
    paymentWindow01 *m = new paymentWindow01;
    hide();
    m->show();

}
void orderRopeLengthWindow01::acceptButtonClicked()
{
    connect(buttonAccept_, SIGNAL(clicked()),
            this, SLOT(openPaymentWindow()));
}
void orderRopeLengthWindow01::plusFiveClicked()
{

    connect(buttonFivePositive_, SIGNAL(clicked()),
                this, SLOT(buttonFivePositiveClicked()));
    connect(this, SIGNAL(valueChangedPositive(int)),
                ropeLength_, SLOT(setValue(int)));

}
void orderRopeLengthWindow01::minusFiveClicked()
{
    connect(buttonFiveNegative_, SIGNAL(clicked()),
            this, SLOT(buttonFiveNegativeClicked()));
    connect(this, SIGNAL(valueChangedNegative(int)),
            ropeLength_, SLOT(setValue(int)));
}
void orderRopeLengthWindow01::declineClicked()
{
    connect(buttonDecline_, SIGNAL(clicked()),
            this, SLOT(buttonCancelClicked()));
    connect(this, SIGNAL(valueReset(int)),
            ropeLength_, SLOT(setValue(int)));
}
