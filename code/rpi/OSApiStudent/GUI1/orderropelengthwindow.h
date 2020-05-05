#ifndef ORDERROPELENGTHWINDOW_H
#define ORDERROPELENGTHWINDOW_H

#include <QWizardPage>

namespace Ui {
class orderRopeLengthWindow;
}

class orderRopeLengthWindow : public QWizardPage
{
    Q_OBJECT

public:
    explicit orderRopeLengthWindow(QWidget *parent = nullptr);
    ~orderRopeLengthWindow();

private:
    Ui::orderRopeLengthWindow *ui;
};

#endif // ORDERROPELENGTHWINDOW_H
