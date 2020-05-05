#ifndef SECONDWINDOWSIGNAL_H
#define SECONDWINDOWSIGNAL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "globals.h"


class secondWindowSignal
{

public:
    secondWindowSignal(){}


signals:
    void valueChangedNegativeFiftyOre(double);
    void valueChangedNegativeOne(double);
    void valueChangedNegativeTwo(double);
    void valueChangedNegativeFive(double);
    void valueChangedNegativeTen(double);
    void valueChangedNegativeTwenty(double);

    void valueChangedUnderOnePointZero(double);
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

#endif // SECONDWINDOWSIGNAL_H
