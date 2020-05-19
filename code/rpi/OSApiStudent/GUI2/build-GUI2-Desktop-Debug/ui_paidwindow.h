/********************************************************************************
** Form generated from reading UI file 'paidwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAIDWINDOW_H
#define UI_PAIDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_paidWindow
{
public:

    void setupUi(QWizardPage *paidWindow)
    {
        if (paidWindow->objectName().isEmpty())
            paidWindow->setObjectName(QString::fromUtf8("paidWindow"));
        paidWindow->resize(400, 300);

        retranslateUi(paidWindow);

        QMetaObject::connectSlotsByName(paidWindow);
    } // setupUi

    void retranslateUi(QWizardPage *paidWindow)
    {
        paidWindow->setWindowTitle(QApplication::translate("paidWindow", "WizardPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paidWindow: public Ui_paidWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAIDWINDOW_H
