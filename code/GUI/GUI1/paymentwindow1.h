#ifndef PAYMENTWINDOW1_H
#define PAYMENTWINDOW1_H
#include "globals1.h"
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QWizardPage>

namespace Ui {
class paymentWindow1;
}

//! The class of the second window the customer meets.
//! It is the window where the customer can see how much it is missing to pay.
class paymentWindow1 : public QWizardPage
{
    Q_OBJECT

public:

    //! The constructor of the class
    //! It initializes all the attributes
    explicit paymentWindow1(QWidget *parent = nullptr);

    //! The destructor of the class
    ~paymentWindow1();

    //! It connects the action decline_ button clicked to the reaktion openOrderRopeWindow
    void cancelButtonClicked();

    //! It connects the spinbox whatYouAreMissingToPay_ to the pointer of the window.
    //! So that when the amount changes to 0 or less for whatYouAreMissingToPay_ it will open paidWindow.
    void amountReached();

    //! When fiftyCents_ is clicked value of the spinbox whatYouAreMissingToPay_ will the value fall by 0.5 crowns
    void fiftyOreClicked();


    //! When oneCrown_ is clicked the value of the spinbox whatYouAreMissingToPay_ will the value fall by 1 crown
    void oneCrownClicked();


    //! When twoCrowns_ is clicked the value of the spinbox whatYouAreMissingToPay_ will the value fall by 2 crowns
    void twoCrownClicked();


    //! When fiveCrowns_ is clicked the value of the spinbox whatYouAreMissingToPay_ will the value fall by 5 crowns
    void fiveCrownClicked();


    //! When tenCrownss_ is clicked the value of the spinbox whatYouAreMissingToPay_ will the value fall by 10 crowns
    void tenCrownClicked();

    //! When twentyCrowns_ is clicked the value of the spinbox whatYouAreMissingToPay_ withe value fall by 20 crowns
    void twentyCrownClicked();


private:
    Ui::paymentWindow1 *ui;

    //LineEdit

    //! It says "Du mangler at betale"
    QLineEdit *youNeedToPay_;

    //DoubleSpinBox
    //! It is the spinbox that contains the value of how much the customer are missing to pay for the rope
    QDoubleSpinBox *whatYouAreMissingToPay_;

    //PushButtons
    //! The button that represent 0.5 crowns
    QPushButton *fiftyCents_;

    //! The button that represent 1 crown
    QPushButton *oneCrown_;

    //! The button that represent 2 crowns
    QPushButton *twoCrowns_;

    //! The button that represent 5 crowns
    QPushButton *fiveCrowns_;

    //! The button that represent 10 crowns
    QPushButton *tenCrowns_;

    //! The button that represent 20 crowns
    QPushButton *twentyCrowns_;

    //! The button the customer click on if it wants to cancel the purchase
    QPushButton *decline_;


    signals:

    //! The signal that the value is falling by 0.5 crowns
    void valueChangedNegativeFiftyOre(double);

    //! The signal that the value is falling by 1 crown
    void valueChangedNegativeOne(double);

    //! The signal that the value is falling by 2 crowns
    void valueChangedNegativeTwo(double);

    //! The signal that the value is falling by 5 crowns
    void valueChangedNegativeFive(double);

    //! The signal that the value is falling by 10 crowns
    void valueChangedNegativeTen(double);

    //! The signal that the value is falling by 20 crowns
    void valueChangedNegativeTwenty(double);


    public slots:

    //! The reaktion that the value is falling by 0.5 crowns
    void buttonFiftyOreClicked()
    {
        emit valueChangedNegativeFiftyOre(price = price - 0.5);
    }
    //! The reaktion that the value is falling by 0.5 crowns
    void buttonOneCrownClicked()
    {
        emit valueChangedNegativeOne(price = price - 1);
    }

    //! The reaktion that the value is falling by 0.5 crowns
    void buttonTwoCrownClicked()
    {
        emit valueChangedNegativeTwo(price = price - 2);
    }

    //! The reaktion that the value is falling by 0.5 crowns
    void buttonFiveCrownClicked()
    {
        emit valueChangedNegativeFive(price = price - 5);
    }

    //! The reaktion that the value is falling by 0.5 crowns
    void buttonTenCrownClicked()
    {
        emit valueChangedNegativeTen(price = price - 10);
    }

    //! The reaktion that the value is falling by 0.5 crowns
    void buttonTwentyCrownClicked()
    {
        emit valueChangedNegativeTwenty(price = price - 20);
    }

    //! It creates a object of orderRopeLengthWindow
    //! Then it hide all showed windows and after that it shows orderRopeLengthWindow
    void openOrderRopeLengthWindow();

    //! It opens paidWindow and is called in the function amountReached()
    void openPaidWindow();


};

#endif // PAYMENTWINDOW1_H
