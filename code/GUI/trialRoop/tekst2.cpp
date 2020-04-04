#include "tekst2.h"
#include "mainwindow.h"
#include <QLineEdit>
#include <QApplication>
tekst2::tekst2(QWidget *parent) : QWidget(parent)
{
    QLineEdit *tekst_ = new QLineEdit ("Du mangler at betale");
    //QPushButton *m_button = new QPushButton ("Hello World", this);
}

void tekst2::print()
{
    QLineEdit LineEdit3("Du mangler at betale:");
}
