#ifndef MAINWINDOW01_H
#define MAINWINDOW01_H

#include <QMainWindow>

namespace Ui {
class MainWindow01;
}

class MainWindow01 : public QMainWindow
{
    Q_OBJECT

public:
    //! The constructor that is calling openOrderRopeWindow
    explicit MainWindow01(QWidget *parent = nullptr);

    //! The destructor of the class
    ~MainWindow01();

    //! It is showing the orderRopeWindow
    void openOrderRopeWindow();
private:
    Ui::MainWindow01 *ui;
};

#endif // MAINWINDOW01_H
