#ifndef ORDERROPELENGTHWINDOW01_H
#define ORDERROPELENGTHWINDOW01_H
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>
#include <QWizardPage>
#include "globals01.h"

namespace Ui {
class orderRopeLengthWindow01;
}

//! the class that represent the first window the customer it is meeting.
//! And it is in this window the customer order the rope length
//! It is inherits from QWizardPage to be able to make a window
class orderRopeLengthWindow01 : public QWizardPage
{
    Q_OBJECT

public:

    //! The constructor of orderRopeLengthWindow
    //! It initializes all the attributes
    explicit orderRopeLengthWindow01(QWidget *parent = nullptr);

    //! The destructor of the class
    ~orderRopeLengthWindow01();

    //! It connect the *buttonAccept_ to the slot void openPaymentWindow.
    //! For understanding what the reaktion void openPaymentWindow does look at its description
    void acceptButtonClicked();

    //! If *buttonFivePositive_ is clicked, the value of the spinBox *ropeLength_ changes which the customer also can see.
    //! It is happening by connect *buttonFivePostive_ to the action clicked() and the slot void buttonFivePositiveClicked()
    //! Now the value is changed on the ropeLength but the customer can't see it. So the spinBox also have to update.
    //! This done by connect a pointer to the window to *ropeLength_ where the signal is void valueChangedPositive(int) and the slot is void setValue(int)
    void plusFiveClicked();

    //! If *buttonFiveNegative_ is clicked, the value of the spinBox *ropeLength_ changes which the customer also can see.
    //! It is happening by connect *buttonFiveNegative_ to the action clicked() and the slot void buttonFiveNegativeClicked()
    //! Now the value is changed on the *ropeLength_ but the customer can't see it. So the spinBox also have to update.
    //! This done by connect a pointer to the window to *ropeLength_ where the signal is void valueChangedNegative(int) and the slot is void setValue(int)
    void minusFiveClicked();

    //! Reset the value of the spinbox when the *buttonDecline_ is clicked. It is done by connect *buttonDecline_ to a pointer to the window
    //! where the signal is clicked() and slot is void buttonCancelClicked(). Which means the value is resat now the spinbox have to update so the customer also can see the new value.
    //! It is done by connect a pointer to the window to *ropeLength_ where the signal is valueReset(int) and the reaktion/slot is setValue(int)
    void declineClicked();

private:
    Ui::orderRopeLengthWindow01 *ui;
    //Text

    //! It is the textline which says "Indtast den onsket laengde snor"
    QLineEdit *LE1_;



    //Buttons

    //! It is the button the customer press to order a larger size of rope
    QPushButton *buttonFivePositive_;

    //! It is the button the customer press to order a smaller size of rope
    QPushButton *buttonFiveNegative_;

    //! It is the button the customer press when it is satisfied with the ropeLength
    QPushButton *buttonAccept_;

    //! It is the button the customer press if it wants to cancel the rope length
    QPushButton *buttonDecline_;

    //SpinBox

    //! It is the spinbox the customer can continually see how much rope it is ordering
    QSpinBox *ropeLength_;

signals:

    //! It is the signal that register the value has changed Postive which is implemented in the slot void buttonFivePositiveClicked()
    void valueChangedPositive(int);

    //! It is the signal that register the value has changed negative which is implemented in the slot void buttonFiveNegativeClicked()
    void valueChangedNegative(int);

    //! It is the signal that register the value has resat it is implemented in slot void buttonCancelClicked()
    void valueReset(int);


public slots:

    //! Create a new object from paymentWindow.
    //! Hide the current window and show the new object from paymentWindow
    void openPaymentWindow();

    //! It emits the signal valueChangedPositive with adding the global variabel ropeLengthAdded to the globalVariabel ropeLength
    //! If the value of ropeLength is less than maximumRopeLength
    void buttonFivePositiveClicked()
    {
        if(ropeLength < maximumRopeLength)
            emit valueChangedPositive(ropeLength = ropeLength + ropeLengthAdded);
    }

    //! It emits the signal valueChangedNegative with subtract the global variabel ropeLengthAdded from the globalVariabel ropeLength
    //! If the value of ropeLength is bigger than or equal to minimumRopeLength
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

    //! It emits valueReset by setting ropeLength = 0
    void buttonCancelClicked()
    {
        emit valueReset(ropeLength = 0);
    }

};

#endif // ORDERROPELENGTHWINDOW01_H
