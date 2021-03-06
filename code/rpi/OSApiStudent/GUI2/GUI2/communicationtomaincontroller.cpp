#include "communicationtomaincontroller.h"
#include "globals.h"
#include "orderropelengthwindow.h"


communicationToMainController::communicationToMainController(unsigned int id)
    : mq_(MAX_QUEUE_SIZE), running_(true)
{
    id_ = id;
    //mC_ = mC;
}
communicationToMainController::~communicationToMainController()
{

}
osapi::MsgQueue* communicationToMainController::getMsgQueue()
{
    return &mq_;
}
void communicationToMainController::startGUIMsgQueue()
{
    orderRopeLengthWindow *m = new orderRopeLengthWindow;
    m->show();
    mq_.send(ID_START_IND);
}
void communicationToMainController::finalRopeLengthFromGUIHandle()
{
    FinalRopeLength *finalRope = new FinalRopeLength;
    finalRope->finalRopeLength = ropeLength;
    mq_.send(ID_FINALEROPELENGTHFROMGUI_IND, finalRope);
}

void communicationToMainController::updateAmountToPay(AmountLeft* moenyLeft)
{
    price = moneyLeft->amountLeft;

}


void communicationToMainController::cancelFromGUIHandle()
{
    CancelPayments *cancel = new CancelPayments;
    cancel->CancelClicked = true;
    mq_.send(ID_CANCELFROMGUI_IND, cancel);
    ropeLength = 0;
}

void communicationToMainController::communicationToMainControllerControllerHandler(unsigned int id, osapi::Message *msg)
{
    switch(id)
    {
        case ID_START_IND:
            startGUIMsgQueue();
            break;

        case ID_FINALEROPELENGTHFROMGUI_IND:
            finalRopeLengthFromGUIHandle();
            break;

        case ID_UPDATEAMOUNTTOPAYTOGUI_IND:
            updateAmountToPay(static_cast<AmountLeft*>(msg));
            break;
        case ID_CANCELFROMGUI_IND:
            cancelFromGUIHandle();
            break;

        default:
            break;
    }
}
void communicationToMainController::run()
{
    startGUIMsgQueue();
    while (running_)
    {
        unsigned long id;
        osapi::Message* msg = mq_.receive(id);
        communicationToMainControllerControllerHandler(id, msg);
        delete msg;
    }
}
