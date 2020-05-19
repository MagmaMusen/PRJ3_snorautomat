/********************************************************************************
** Form generated from reading UI file 'paymentwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTWINDOW_H
#define UI_PAYMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_paymentWindow
{
public:

    void setupUi(QWizardPage *paymentWindow)
    {
        if (paymentWindow->objectName().isEmpty())
            paymentWindow->setObjectName(QString::fromUtf8("paymentWindow"));
        paymentWindow->resize(400, 300);

        retranslateUi(paymentWindow);

        QMetaObject::connectSlotsByName(paymentWindow);
    } // setupUi

    void retranslateUi(QWizardPage *paymentWindow)
    {
        paymentWindow->setWindowTitle(QApplication::translate("paymentWindow", "WizardPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paymentWindow: public Ui_paymentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTWINDOW_H
