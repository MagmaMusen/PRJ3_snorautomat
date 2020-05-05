#ifndef PAYMENTWINDOW_H
#define PAYMENTWINDOW_H
#include "globals.h"
#include <QWizardPage>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
namespace Ui {
class paymentWindow;
}

class paymentWindow : public QWizardPage
{
    Q_OBJECT

public:
    explicit paymentWindow(QWidget *parent = nullptr);
    ~paymentWindow();
    void cancelButtonClicked();
    void amountReached();
    void fiftyOreClicked();
    void oneCrownClicked();
    void twoCrownClicked();
    void fiveCrownClicked();
    void tenCrownClicked();
    void twentyCrownClicked();




private:
    Ui::paymentWindow *ui;


    //LineEdit
    QLineEdit *youNeedToPay_;
    QLineEdit *test_;
    //DoubleSpinBox
    QDoubleSpinBox *whatYouAreMissingToPay_;

    //PushButtons
    QPushButton *fiftyCents_;
    QPushButton *oneCrown_;
    QPushButton *twoCrowns_;
    QPushButton *fiveCrowns_;
    QPushButton *tenCrowns_;
    QPushButton *twentyCrowns_;

    QPushButton *decline_;



signals:
    void valueChangedNegativeFiftyOre(double);
    void valueChangedNegativeOne(double);
    void valueChangedNegativeTwo(double);
    void valueChangedNegativeFive(double);
    void valueChangedNegativeTen(double);
    void valueChangedNegativeTwenty(double);

    void valueChangedUnderOnePointZero(double);
public slots:
    void buttonFiftyOreClicked()
        {
            emit valueChangedNegativeFiftyOre(price = price - 0.5);
        }
        void buttonOneCrownClicked()
        {
            emit valueChangedNegativeOne(price = price - 1);
        }
        void buttonTwoCrownClicked()
        {
            emit valueChangedNegativeTwo(price = price - 2);
        }
        void buttonFiveCrownClicked()
        {
            emit valueChangedNegativeFive(price = price - 5);
        }
        void buttonTenCrownClicked()
        {
            emit valueChangedNegativeTen(price = price - 10);
        }
        void buttonTwentyCrownClicked()
        {
            emit valueChangedNegativeTwenty(price = price - 20);
        }

        void openOrderRopeLengthWindow();
        void openPaidWindow();
};

#endif // PAYMENTWINDOW_H
