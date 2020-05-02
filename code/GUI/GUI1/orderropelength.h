#ifndef ORDERROPELENGTH_H
#define ORDERROPELENGTH_H

#include <QWizardPage>

namespace Ui {
class orderropelength;
}

class orderropelength : public QWizardPage
{
    Q_OBJECT

public:
    explicit orderropelength(QWidget *parent = nullptr);
    ~orderropelength();

private:
    Ui::orderropelength *ui;
};

#endif // ORDERROPELENGTH_H
