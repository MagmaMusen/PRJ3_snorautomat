#ifndef FAKERECEIVERGUI_H
#define FAKERECEIVERGUI_H
#include "communicationtomaincontroller.h"
#include <osapi/ThreadFunctor.hpp>
#include <osapi/Mutex.hpp>
#include <osapi/MsgQueue.hpp>

class fakeReceiverGUI : public osapi::ThreadFunctor
{
public:
    enum
    {
        ID_FINALEROPELENGTHFROMGUI_IND,
    };
    fakeReceiverGUI();
    void fakeReceiverGUIHandler(unsigned int id, osapi::Message* msg);
    static const int MAX_QUEUE_SIZE = 10;
    osapi::MsgQueue* getMsgQueue();
    void receivedRopeLength(FinalRopeLength* ropeLength);
protected:
    void run();


private:
    bool running_;
    osapi::MsgQueue mq_;
};

#endif // FAKERECEIVERGUI_H
