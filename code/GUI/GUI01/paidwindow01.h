#ifndef PAIDWINDOW01_H
#define PAIDWINDOW01_H
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QWizardPage>

namespace Ui {
class paidWindow01;
}

//! The class of the last window the customer meets.
//! It is the window where the customer can see how much rope and change it is gonna get
//! It is inherits from QWizardPage to be able to make a window
class paidWindow01 : public QWizardPage
{
    Q_OBJECT

public:

    //! The constructor of the class
    //! It initializes all the attributes
    explicit paidWindow01(QWidget *parent = nullptr);

    //! The detructor of the class
    ~paidWindow01();

private:
    Ui::paidWindow01 *ui;

    //LineEdit

    //! It says "Bytte penge tilbage"
    QLineEdit *amountMoneyText_;

    //! It says "Snor der bliver udleveret"
    QLineEdit *ropeBackText_;

    //SpinBox

    //! The spinbox where the customer can see how much change it is gonna get
    QDoubleSpinBox *amountMoneyBack_;

    //! The spinbox where the customer can see how much rope it is gonna get
    QSpinBox *ropeBack_;

};

#endif // PAIDWINDOW01_H
