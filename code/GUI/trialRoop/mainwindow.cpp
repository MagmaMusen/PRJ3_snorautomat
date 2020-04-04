#include "mainwindow.h"
#include "snorwindow.h"
#include "auxsignals.h"
#include "ui_mainwindow.h"
#include "newwindow.h"
#include "globals.h"
#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>
#include <QTextDocument>
#include <QFile>
#include <QTextStream>
#include <QSlider>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(600,600);

    //Create the 3 buttons with names
    buttonFivePositve_ = new QPushButton("+5", this);
    buttonFiveNegative_ = new QPushButton("-5", this);
    buttonDecline_ = new QPushButton("Decline", this);

    //Create a LineEdit object
    LE1_ = new QLineEdit("Indtast den onsket laengde snor", this);

    //Create a spinbox where the length of the rope is going to be showed
    QSpinBox *progress1_ = new QSpinBox(this);

    //AuxSignal creates so there can establish connection between the buttons and the spinBox
    //and change the value in the spinBox continuously
    AuxSignals * auxSignals = new AuxSignals;

    //Sets the geometry for the 3 buttons
    buttonFivePositve_->setGeometry(10,80,80,30);
    buttonFiveNegative_->setGeometry(140, 80, 80, 30);

    //buttonAccept_->setGeometry(270, 10, 80, 30);
    buttonDecline_->setGeometry(400, 80, 80, 30);

    //Set the LineEdit to Read Only
    LE1_->setReadOnly(true);

    //Set the LineEdit's geometry
    LE1_->setGeometry(10, 10, 340, 30);

    //Set the progress1_
    progress1_->setGeometry(10, 140, 80, 30);
    progress1_->setRange(0, 100);
    progress1_->setReadOnly(true);
    progress1_->setValue(0);

    //Set the suffix to cm
    progress1_->setSuffix("cm");

    //Connect button FivePositive_ to progress1_
    connect(buttonFivePositve_, SIGNAL(clicked()),
            auxSignals, SLOT(buttonFivePositiveClicked()));
    connect(auxSignals, SIGNAL(valueChangedPositive(int)),
            progress1_, SLOT(setValue(int)));


    //Connect buttonFiveNegative_ to progress1_
    connect(buttonFiveNegative_, SIGNAL(clicked()),
            auxSignals, SLOT(buttonFiveNegativeClicked()));
    connect(auxSignals, SIGNAL(valueChangedNegative(int)),
            progress1_, SLOT(setValue(int)));

    //Accept button is pressed and should go to new window
    connect(buttonAccept_, SIGNAL(clickedButton()),
            this, SLOT(openSnorWindow()));

    //reset to 0
    connect(buttonDecline_, SIGNAL(clicked()),
            auxSignals, SLOT(buttonCancelClicked()));
    connect(auxSignals, SIGNAL(valueReset(int)),
            progress1_, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSnorWindow()
{
    mySnorWindow = new snorWindow();
    mySnorWindow->show();
}


void MainWindow::showWindowOne()
{
   /* this ->hide();
    MainWindow *w = new MainWindow();
    w->show();*/
}


void MainWindow::on_acceptButton_clicked()
{

    mySnorWindow = new snorWindow(this);
   // mysnorWindow->setGeometry(270, 10, 80, 30);

    hide();

    mySnorWindow->show();
}

