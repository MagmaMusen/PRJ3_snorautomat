#pragma once
#include <iostream>
#include <osapi/MsgQueue.hpp>
#include <osapi/Mutex.hpp>
#include <osapi/ThreadFunctor.hpp>
#include "FakeReceiver.hpp"


class SensorReader;
class FakeReceiver;

//! Wrapper message for the timesignature of a coin. Can be sent to message queues.
struct CoinTimings: public osapi::Message
{
    long timeDifferenceRising, timeDifferenceEnterExit;
};

//! Wrapper message for the value of a coin. Can be sent to message queues.
struct Coin: public osapi::Message
{
    float value;
};

//! Identifies coin values based on received coin time signatures and sends the value to specifiable receiver.
//! Coin width boundaries and sensor distances have been hard-coded into the class.
//! The class inherits from OSAPI ThreadFunctor class to enable starting the c++ class as a thread using POSIX-threads.
class CoinIdentifier : public osapi::ThreadFunctor
{
public:
    //! Message queue size. Sending on a full queue will block sender to keep synchronized.
    static const int MAX_QUEUE_SIZE = 64;

    //! Constructor. Parameter is the specifiable receiver of coin value indication events.
    CoinIdentifier(osapi::MsgQueue* receiverMq);

    //! Event message ID's. Used to cast wrapper structs. They are received as their base-class Message and therefore need to be identified and casted. 
    enum {
        ID_READ_IND,
        ID_IDENTIFY_IND,
        ID_COIN_IND
    };

    //! Returns message queue of the class.
    osapi::MsgQueue* getMsgQueue();

protected:

    //! Event loop. Receives messages from the message queue, calls the handler, then deletes the message.
    //! Is inherited from the ThreadFunctor class and overwritten.
    void run();

private:
    //! Event loop exit if set to false.
    bool running_;

    //! CoinIdentifier's FIFO message queue where received events are stored.
    osapi::MsgQueue mq_;

    //! Indentifies messages on received on CoinIdentifier's message queue, casts the message if needed and starts the correct handler function.
    void CoinIdentifierHandler(unsigned int id, osapi::Message* msg);

    //! Identifies a coin based on it's timesignature, then sends the appropriate coin value indication event to a receiver.
    void CoinIdentifierHandleIdentify(CoinTimings* timing);

    //! Lower boundary value in millimeters for one-crown. If a lower value is registered, the coin i undefined.
    float boundaryWidthOneLower = 18.82;

    //! Boundary value in millimeters between one-crown (lower) and fify-oere (upper). 
    float boundaryWidthOneFifty = 19.71;

    //! Boundary value in millimeters between fifty-oere (lower) and ten-crown (upper).
    float boundaryWidthFiftyTen = 20.77;

    //! Boundary value in millimeters between ten-crown (lower) and two-crown (upper).
    float boundaryWidthTenTwo = 21.77;

    //! Boundary value in millimeters between two-crown (lower) and twenty-crown (upper).
    float boundaryWidthTwoTwenty = 22.90; 

    //! Boundary value in millimeters between twenty-crown (lower) and five-crown (upper).
    float boundaryWidthTwentyFive = 24.10;

    //! Upper boundary value in millimeters for five-crown. If a higher value is registered, the coin is undefined.
    float boundaryWidthFiveUpper = 24.97;
    
    //! Distance in millimeters between sensors in the direction of coin-movement.
    float sensorDistanceMillimeter_ = 5;

    //! Calculate coin value based on its width, using the coin boundaries in the CoinIdentifier.
    float widthToValue(float widthInMillimeter);

    //! Message queue of the receiver of the coin value indication event.
    osapi::MsgQueue* receiver_;
};