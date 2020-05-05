#ifndef FIRSTWINDOWSIGNAL_H
#define FIRSTWINDOWSIGNAL_H

#include <QObject>
#include <QWidget>
#include "globals.h"
class firstWindowSignal : public QObject
{
    Q_OBJECT
public:
    explicit firstWindowSignal();

signals:
    void valueChangedPositive(int);
    void valueChangedNegative(int);
    void valueReset(int);

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

#endif // FIRSTWINDOWSIGNAL_H
