#ifndef SNORWINDOW_H
#define SNORWINDOW_H

#include <QWizard>
#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVector>




namespace Ui {
class snorWindow;
}

class snorWindow : public QWizard
{
    Q_OBJECT

public:
    explicit snorWindow(QWidget *parent = nullptr);
   ~snorWindow();
    //void startMainWindow();
public slots:

private slots:
    void on_cancelButton_clicked();

private:
    Ui::snorWindow *ui;
    //MainWindow *myMainWindow;
    QLineEdit *youNeedToPay_;
    QLineEdit *test_;

    QDoubleSpinBox *whatYouAreMissingToPay_;


    QPushButton *fiftyCents_;
    QPushButton *oneCrown_;
    QPushButton *twoCrowns_;
    QPushButton *fiveCrowns_;
    QPushButton *tenCrowns_;
    QPushButton *twentyCrowns_;

};

#endif // SNORWINDOW_H
