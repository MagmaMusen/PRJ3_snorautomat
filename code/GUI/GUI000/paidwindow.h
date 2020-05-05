#ifndef PAIDWINDOW_H
#define PAIDWINDOW_H

#include <QWizardPage>
#include <QLineEdit>
#include <QDoubleSpinBox>
namespace Ui {
class paidWindow;
}

class paidWindow : public QWizardPage
{
    Q_OBJECT

public:
    explicit paidWindow(QWidget *parent = nullptr);
    ~paidWindow();

private:
    Ui::paidWindow *ui;

    //LineEdit
    QLineEdit *amountMoneyText_;
    QLineEdit *ropeBackText_;
    //SpinBox
    QDoubleSpinBox *amountMoneyBack_;
    QSpinBox *ropeBack_;



};



#endif // PAIDWINDOW_H
