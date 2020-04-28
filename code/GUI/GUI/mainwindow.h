#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Text
    QLineEdit *LE1_;
    QLineEdit *LE2_;

    
    //Buttons
    QPushButton *buttonFivePositive_;
    QPushButton *buttonFiveNegative_;
    QPushButton *buttonAccept_;
    QPushButton *buttonDecline_;
    
    //SpinBox
    QSpinBox *ropeLength_;
    

public slots:
     void openPaymentWindow();

     
};

#endif // MAINWINDOW_H
