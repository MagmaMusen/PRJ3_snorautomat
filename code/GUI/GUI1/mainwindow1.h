#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>

namespace Ui {
class MainWindow1;
}


class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:

    //! The constructor that is calling openOrderRopeWindow
    explicit MainWindow1(QWidget *parent = nullptr);

    //! The destructor of the class
    ~MainWindow1();

    //! It is showing the orderRopeWindow
    void openOrderRopeWindow();
private:
    Ui::MainWindow1 *ui;
};

#endif // MAINWINDOW1_H
