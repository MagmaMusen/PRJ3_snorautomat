#ifndef PAYMENTWINDOW_H
#define PAYMENTWINDOW_H
#include "globals.h"
#include <QWizardPage>
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleSpinBox>
namespace Ui {
class paymentWindow;
}
//! The class of the second window the customer meets.
//! It is the window where the customer can see how much it is missing to pay.
class paymentWindow : public QWizardPage
{
    Q_OBJECT

public:

    //! The constructor of the class
    //! It initializes all the attributes
    explicit paymentWindow(QWidget *parent = nullptr);

    //! The destructor of the class
    ~paymentWindow();

    //! It connects the action decline_ button clicked to the reaktion openOrderRopeWindow
    //! It also connects the action decline button clicked to the reaktion cancelButtonClickedCommunicationToMainControllerClass()
    //! To make sure the mainController also know the purchase is cancelled.
    void cancelButtonClicked();

    //! It connects the spinbox whatYouAreMissingToPay_ to the pointer of the window.
    //! So that when the amount changes to 0 or less for whatYouAreMissingToPay_ it will open paidWindow.
    void amountReached();

    //! It connects the spinbox whatYouAreMissingToPay_ with the aktion valueChanged(double) to the pointer of the window with the reaktion setValue(double)
    //! It is making sure that when the value of the spinbox changes the window will be updated so the customer also can see the new value
    void amountToPay();

private:
    Ui::paymentWindow *ui;

    //LineEdit

    //! It says "Du mangler at betale"
    QLineEdit *youNeedToPay_;

    //DoubleSpinBox

    //! It is the spinbox that contains the value of how much the customer are missing to pay for the rope
    QDoubleSpinBox *whatYouAreMissingToPay_;

    //PushButtons
    //! The button the customer click on if it wants to cancel the purchase
    QPushButton *decline_;


public slots:

    //! It creates a object of orderRopeLengthWindow
    //! Then it hide all showed windows and after that it shows orderRopeLengthWindow
        void openOrderRopeLengthWindow();

    //! It opens paidWindow and is called in the function amountReached()
        void openPaidWindow();

    //! It calls the function cancelFromGUIHandle() from communcationToMainController
        void cancelButtonClickedCommunicationToMainControllerClass();
        
};

#endif // PAYMENTWINDOW_H
