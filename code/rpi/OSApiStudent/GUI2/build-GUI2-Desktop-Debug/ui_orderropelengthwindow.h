/********************************************************************************
** Form generated from reading UI file 'orderropelengthwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERROPELENGTHWINDOW_H
#define UI_ORDERROPELENGTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_orderRopeLengthWindow
{
public:

    void setupUi(QWizardPage *orderRopeLengthWindow)
    {
        if (orderRopeLengthWindow->objectName().isEmpty())
            orderRopeLengthWindow->setObjectName(QString::fromUtf8("orderRopeLengthWindow"));
        orderRopeLengthWindow->resize(400, 300);

        retranslateUi(orderRopeLengthWindow);

        QMetaObject::connectSlotsByName(orderRopeLengthWindow);
    } // setupUi

    void retranslateUi(QWizardPage *orderRopeLengthWindow)
    {
        orderRopeLengthWindow->setWindowTitle(QApplication::translate("orderRopeLengthWindow", "WizardPage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderRopeLengthWindow: public Ui_orderRopeLengthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERROPELENGTHWINDOW_H
