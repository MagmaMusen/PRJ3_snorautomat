#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define OS_LINUX
#include "paymentwindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
   // ~MainWindow();
    //virtual ~MainWindow();
    void presentOrderRopeLength();
    void presentPaymentWindow();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
