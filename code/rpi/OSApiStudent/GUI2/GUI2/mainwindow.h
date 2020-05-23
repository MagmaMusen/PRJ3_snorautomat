#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
//! The class that starts the whole program
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! The constructor calls showOrderRopeLengthWindow 
    explicit MainWindow(QWidget *parent = nullptr);

    //! The destructor of the class
    ~MainWindow();

    //! Shows orderRopeLengthWindow
    void showOrderRopeLengthWindow();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
