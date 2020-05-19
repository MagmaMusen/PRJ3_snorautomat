#ifndef PAYMENTWINDOW_H
#define PAYMENTWINDOW_H

#include <QWizardPage>
#include <QWizard>
#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVector>

namespace Ui {
class paymentWindow;
}

class paymentWindow : public QWizardPage
{
    Q_OBJECT

public:
    explicit paymentWindow(QWidget *parent = nullptr);
    ~paymentWindow();
    void updateAmountToPay();
    void cancelButtonClicked();
    void amountReached();

private:
    Ui::paymentWindow *ui;

    //paidRopeWindow *myPaidRopeWindow;

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


public slots:
    void openOrderRopeLengthWindow();
    void openPaidWindow();




};

#endif // PAYMENTWINDOW_H
