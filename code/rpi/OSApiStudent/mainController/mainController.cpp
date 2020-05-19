#include "mainController.hpp"


#include "../../I2CVirtual/I2CVirtual.hpp"
#include <osapi/Utility.hpp>
#include <stdlib.h>
#include <iostream>
//GG
using namespace std;



mainController::mainController(unsigned long id)
: mq_(MAX_QUEUE_SIZE), running_(true)
{ 
    id_ = id;

}


void mainController::finalRopeLengthFromGUIHandle(FinalRopeLength * ropeMessage)
{
    finalRopeLength_ = ropeMessage->finalRopeLength;
    coinHandle();
}
void mainController::coinHandle(double coinValue)
{
    amountPaid_ = amountPaid_ + coinValue;
    AmountLeft *update = new AmountLeft;
    update->amountLeft = priceForRope_ - amountPaid_;
    
    //GUIObjekt = pointer til GUI
    //GUIObjekt -> getMsgQueue()-> send(ID_UPDATEAMOUNTTOPAYTOGUI_IND, AmountLeft);
    
    GMsgQue_->getMsgQueue()->send(ID_UPDATEAMOUNTTOPAYTOGUI_IND, update);
    checkIfPriceReached();
}
void mainController::checkIfPriceReached()
{
    if(priceForRope_ <= amountPaid_)
    {
        helper->i2cSend((char)finalRopeLength_);
    }
}

void mainController::cancelFromGUIHandle()
{
    //Forste skal den dosere monterne
    //->i2cSend((char)amountPaid);
    amountPaid_ = 0;
    finalRopeLength_ = 0;
}

/*double[]mainController::convertAmountToCoins(double amount)
{
    double coinArray[];
    while(amount > 0)
    {
        
    }
    amount%20
}
*/
osapi::MsgQueue* mainController::getMsgQueue()
{
    return &mq_;
}

void mainController::run()
{
    while(running_)
    {
        unsigned long id;
        osapi::Message* msg = mq_.receive(id);
        mainControllerHandler(id, msg);
        delete msg;
    }
}


void mainController::mainControllerHandler(unsigned long id, osapi::Message* msg)
{
    switch (id)
    {
        case ID_FINALROPELENGTHFROMGUI_IND:
             finalRopeLengthFromGUIHandle(static_cast<FinalRopeLength*>(msg));
            break;

        case ID_CANCELFROMGUI_IND:
             cancelFromGUIHandle();
            break;

        case ID_COIN_IND:
             coinHandle(static_cast <coin*>(msg));
            break;
        case ID_UPDATEAMOUNTTOPAYTOGUI_IND
             
            break;
        

        
        default:
            break;
    }
    
}