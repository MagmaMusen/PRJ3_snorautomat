#include "fakereceivergui.h"
#include <iostream>
using namespace std;
fakeReceiverGUI::fakeReceiverGUI()
    : mq_(MAX_QUEUE_SIZE), running_(true)
{

}
void fakeReceiverGUI::run()
{
    cout << "Event loop in fakeReceiverGUI starts" << endl;
    while(running_)
    {
        unsigned long int id;
        osapi::Message* msg = mq_.receive(id);
        fakeReceiverGUIHandler(id, msg);
        delete msg;
    }
}


osapi::MsgQueue *fakeReceiverGUI::getMsgQueue()
{
    return &mq_;
}
void fakeReceiverGUI::fakeReceiverGUIHandler(unsigned int id, osapi::Message *msg)
{
    switch(id)
    {
        case  ID_FINALEROPELENGTHFROMGUI_IND:
            receivedRopeLength(static_cast<FinalRopeLength*>(msg));
            break;
    }
}
void fakeReceiverGUI::receivedRopeLength(FinalRopeLength *ropeLength)
{
    cout << "Received rope length from communicationToMainController class. ropeLength is: " << ropeLength->finalRopeLength << endl;
}
