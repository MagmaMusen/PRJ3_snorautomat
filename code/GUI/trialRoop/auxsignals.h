#ifndef AUXSIGNALS_H
#define AUXSIGNALS_H
#include <mainwindow.h>
#include <QObject>
#include "globals.h"

class AuxSignals : public QObject
{
    Q_OBJECT
public:
    explicit AuxSignals(QObject *parent = nullptr);

signals:
    void valueChangedPositive(int);
    void valueChangedNegative(int);
    void valueReset(int);
    
    //Crowns input
    void valueChangedNegativeFiftyOre(double);
    void valueChangedNegativeOne(double);
    void valueChangedNegativeTwo(double);
    void valueChangedNegativeFive(double);
    void valueChangedNegativeTen(double);
    void valueChangedNegativeTwenty(double);
    
public slots:
    void buttonFivePositiveClicked()
    {
        emit valueChangedPositive(ropeLength = ropeLength + 5);

    }
    void buttonFiveNegativeClicked()
    {
        // Securing that the customer can't order a negative size rope
        if (ropeLength >= 5)
        {
        emit valueChangedNegative(ropeLength=ropeLength - 5);
        }
        else {
            {

            }
        }
    }
    void buttonCancelClicked()
    {
        emit valueReset(ropeLength = 0);
    }
    
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

#endif // AUXSIGNALS_H
