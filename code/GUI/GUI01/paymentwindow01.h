#ifndef PAYMENTWINDOW01_H
#define PAYMENTWINDOW01_H
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QWizardPage>
#include "globals01.h"
namespace Ui {
class paymentWindow01;
}

class paymentWindow01 : public QWizardPage
{
    Q_OBJECT

public:
    explicit paymentWindow01(QWidget *parent = nullptr);
    ~paymentWindow01();
    void cancelButtonClicked();
    void amountReached();
    void fiftyOreClicked();
    void oneCrownClicked();
    void twoCrownClicked();
    void fiveCrownClicked();
    void tenCrownClicked();
    void twentyCrownClicked();



private:
    Ui::paymentWindow01 *ui;

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

#endif // PAYMENTWINDOW01_H
