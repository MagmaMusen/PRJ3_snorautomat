#ifndef FIRSTWINDOWSIGNALS_H
#define FIRSTWINDOWSIGNALS_H
#include "globals.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class firstWindowSignals : public QObject
{
    Q_OBJECT
public:
    firstWindowSignals(QObject *parent = nullptr);

signals:

    void valueChangedPositive(int);
    void valueChangedNegative(int);
    void valueReset(int);


    //Crowns input - Second window


public slots:

    void buttonFivePositiveClicked()
    {
        if(ropeLength < maximumRopeLength)
            emit valueChangedPositive(ropeLength = ropeLength + ropeLengthAdded);
    }
    void buttonFiveNegativeClicked()
    {
        // Securing that the customer can't order a negative size rope
        if (ropeLength >= minimumRopeLength)
        {
            emit valueChangedNegative(ropeLength=ropeLength - ropeLengthAdded);
        }
        else
        {}
    }
    void buttonCancelClicked()
    {
        emit valueReset(ropeLength = 0);
    }
};

#endif // FIRSTWINDOWSIGNALS_H
