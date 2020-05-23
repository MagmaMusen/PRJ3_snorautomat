#ifndef PAIDWINDOW_H
#define PAIDWINDOW_H

#include <QWizardPage>
#include <QLineEdit>
#include <QDoubleSpinBox>

namespace Ui {
class paidWindow;
}

//! The class of the last window the customer meets.
//! It is the window where the customer can see how much rope and change it is gonna get
//! It is inherits from QWizardPage to be able to make a window
class paidWindow : public QWizardPage
{
    Q_OBJECT

public:

    //! The constructor of the class
    //! It initializes all the attributes
    explicit paidWindow(QWidget *parent = nullptr);

    //! The destructor of the class
    ~paidWindow();

private:
    Ui::paidWindow *ui;

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

#endif // PAIDWINDOW_H
