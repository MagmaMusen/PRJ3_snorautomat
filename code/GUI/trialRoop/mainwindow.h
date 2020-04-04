#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <snorwindow.h>

#include <QLineEdit>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    double lineEdit();
    void showWindowOne();
    ~MainWindow();
signals:
    bool clickedButton();
    void valuesChanged(int);

private:
    //Windows
    Ui::MainWindow *ui;
    MainWindow *cancel_;
    snorWindow *mySnorWindow;

    //Texst
    QLineEdit *LE1_;
    QLineEdit *LE2_;
    //Buttons
    QPushButton *buttonFivePositve_;
    QPushButton *buttonFiveNegative_;
    QPushButton *buttonAccept_;
    QPushButton *buttonDecline_;

    QSpinBox *testSB_;

public slots:
     void openSnorWindow();


private slots:
    void on_acceptButton_clicked();
};

#endif // MAINWINDOW_H
