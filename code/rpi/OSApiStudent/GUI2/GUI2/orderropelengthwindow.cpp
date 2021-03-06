#include "orderropelengthwindow.h"
#include "ui_orderropelengthwindow.h"
#include "paymentwindow.h"
#include "communicationtomaincontroller.h"
orderRopeLengthWindow::orderRopeLengthWindow(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::orderRopeLengthWindow)
{
    ui->setupUi(this);

    setFixedSize(600,600);
    //Create the 3 buttons with names

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

orderRopeLengthWindow::~orderRopeLengthWindow()
{
    delete ui;
}

void orderRopeLengthWindow::openPaymentWindow()
{
    paymentWindow *m = new paymentWindow;
    hide();
    m->show();
}
void orderRopeLengthWindow::sendRopeLength()
{
    communicationToMainController *cTMC;
    cTMC->MAX_QUEUE_SIZE;
    cTMC->finalRopeLengthFromGUIHandle();
    //communicationToMainController *m = new communicationToMainController;
    //m->finalRopeLengthFromGUIHandle();
}
void orderRopeLengthWindow::acceptButtonClicked()
{
    connect(buttonAccept_, SIGNAL(clicked()),
            this, SLOT(openPaymentWindow()));



    connect(buttonAccept_, SIGNAL(clicked()),
            this, SLOT(sendRopeLength()));



}
void orderRopeLengthWindow::plusFiveClicked()
{
    //firstWindowSignals *fWS = new firstWindowSignals;
    connect(buttonFivePositive_, SIGNAL(clicked()),
                this, SLOT(buttonFivePositiveClicked()));
    connect(this, SIGNAL(valueChangedPositive(int)),
                ropeLength_, SLOT(setValue(int)));

}
void orderRopeLengthWindow::minusFiveClicked()
{
    connect(buttonFiveNegative_, SIGNAL(clicked()),
            this, SLOT(buttonFiveNegativeClicked()));
    connect(this, SIGNAL(valueChangedNegative(int)),
            ropeLength_, SLOT(setValue(int)));
}
void orderRopeLengthWindow::declineClicked()
{
    connect(buttonDecline_, SIGNAL(clicked()),
            this, SLOT(buttonCancelClicked()));
    connect(this, SIGNAL(valueReset(int)),
            ropeLength_, SLOT(setValue(int)));
}
