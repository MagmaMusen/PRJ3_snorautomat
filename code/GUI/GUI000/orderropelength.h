#ifndef ORDERROPELENGTH_H
#define ORDERROPELENGTH_H
#include "globals.h"
#include <QWizardPage>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
namespace Ui {
class orderRopeLength;
}

class orderRopeLength : public QWizardPage
{
    Q_OBJECT

public:
    explicit orderRopeLength(QWidget *parent = nullptr);
    ~orderRopeLength();
    void acceptButtonClicked();
    void plusFiveClicked();
    void minusFiveClicked();
    void declineClicked();

private:
    Ui::orderRopeLength *ui;


    //Text
    QLineEdit *LE1_;
    QLineEdit *LE2_;


    //Buttons
    QPushButton *buttonFivePositive_;
    QPushButton *buttonFiveNegative_;
    QPushButton *buttonAccept_;
    QPushButton *buttonDecline_;

    //SpinBox
    QSpinBox *ropeLength_;




signals:

    void valueChangedPositive(int);
    void valueChangedNegative(int);
    void valueReset(int);


    //Crowns input - Second window


public slots:


     void openPaymentWindow();
    void buttonFivePositiveClicked()
    {
        if(ropeLength < maximumRopeLength)
            emit valueChangedPositive(ropeLength = ropeLength + ropeLengthAdded);
    }
    void buttonFiveNegativeClicked()
    {
        // Securing that the customer can't order a negative size rope
        if (ropeLength >= minimumRopeLength)
        {
            emit valueChangedNegative(ropeLength=ropeLength - ropeLengthAdded);
        }
        else
        {}
    }
    void buttonCancelClicked()
    {
        emit valueReset(ropeLength = 0);
    }
};

#endif // ORDERROPELENGTH_H
