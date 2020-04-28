#ifndef SECONDWINDOWSIGNALS_H
#define SECONDWINDOWSIGNALS_H
#include "globals.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "firstwindowsignal.h"

class secondwindowsignals : public firstWindowSignal
{
    Q_OBJECT
public:
    explicit secondwindowsignals(QObject *parent = nullptr);


signals:
    //Crowns input - Second window
    void valueChangedNegativeFiftyOre(double);
    void valueChangedNegativeOne(double);
    void valueChangedNegativeTwo(double);
    void valueChangedNegativeFive(double);
    void valueChangedNegativeTen(double);
    void valueChangedNegativeTwenty(double);
public slots:


    void buttonFiftyOreClicked()
    {
        emit valueChangedNegativeFiftyOre(price = price - 0.5);
    }
    void buttonOneCrownClicked()
    {
        emit valueChangedNegativeOne(price = price - 1);
    }
    void buttonTwoCrownClicked()
    {
        emit valueChangedNegativeTwo(price = price - 2);
    }
    void buttonFiveCrownClicked()
    {
        emit valueChangedNegativeFive(price = price - 5);
    }
    void buttonTenCrownClicked()
    {
        emit valueChangedNegativeTen(price = price - 10);
    }
    void buttonTwentyCrownClicked()
    {
        emit valueChangedNegativeTwenty(price = price - 20);
    }

};

#endif // SECONDWINDOWSIGNALS_H
