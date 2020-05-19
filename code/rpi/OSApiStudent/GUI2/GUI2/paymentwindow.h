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
    explicit paymentWindow(QWidget *parent = nullptr);
    ~paymentWindow();
    void cancelButtonClicked();
    void amountReached();
    void amountToPay();

private:
    Ui::paymentWindow *ui;

    //LineEdit
    QLineEdit *youNeedToPay_;
    QLineEdit *test_;
    //DoubleSpinBox
    QDoubleSpinBox *whatYouAreMissingToPay_;

    //PushButtons
    QPushButton *decline_;

signals:
     //void valueChangedUnderPointZero(double);

public slots:

        void openOrderRopeLengthWindow();
        void openPaidWindow();
        void cancelButtonClickedCommunicationToMainControllerClass();
        
};

#endif // PAYMENTWINDOW_H
