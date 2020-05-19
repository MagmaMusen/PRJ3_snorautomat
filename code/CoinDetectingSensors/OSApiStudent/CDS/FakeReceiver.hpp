#pragma once
#include "osapi/MsgQueue.hpp"
#include <osapi/Mutex.hpp>
#include <osapi/ThreadFunctor.hpp>
#include <string>
#include "CoinIdentifier.hpp"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

class CoinIdentifier;
class SensorReader;
struct Coin;

class FakeReceiver : public osapi::ThreadFunctor
{
public:
    static const int MAX_QUEUE_SIZE = 10;
    FakeReceiver();
    osapi::MsgQueue* getMsgQueue();
    enum {
        ID_READ_IND,
        ID_IDENTIFY_IND,
        ID_COIN_IND
    };

protected:

    //! Event loop. Receives messages from the message queue, calls the handler, then deletes the message.
    //! Is inherited from the ThreadFunctor class and overwritten.
    void run();

private:
    //! Indentifies messages on received on FakeReceiver's message queue, casts the message if needed and starts the correct handler function.
    void FakeReceiverHandler(unsigned int id, osapi::Message* msg);

    //! Prints received coin value to console.
    void FakeReceiverHandleCoin(Coin* msg);

    //! Event loop exit if set to false.
    bool running_;

    //! FakeReceiver's FIFO message queue where received events are stored.
    osapi::MsgQueue mq_;
};