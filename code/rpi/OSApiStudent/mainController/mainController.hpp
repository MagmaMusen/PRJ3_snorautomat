#pragma once
#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <osapi/MsgQueue.hpp>
#include <osapi/Mutex.hpp>
#include <osapi/ThreadFunctor.hpp>

#include "../../I2CVirtual/I2CVirtual.hpp"
//#include "../GUI1/guimessagequeue.h"


//! Struct that contains thow much the customer is missing to pay
//! Inherits from osapi::Message so it can be send to GUI's messagequeue
struct AmountLeft : public osapi::Message
{
    double amountLeft;
};


//! mainController's function is to put together the inputs from GUI and Monttaeller and then send continuously updates to GUI about how much money is missing to pay
//! It inherits from OSAPI ThreadFunctor to make it able to communicate with GUI and MontTaeller
//! After the customer has reached the amount it has to pay for the rope mainController sends to snorHaandtering and montDosering by the i2c class how much rope the customer is gonna get and how much change it gets
class mainController : public osapi::ThreadFunctor
{
public:

//! Struct that contains the customer have choosen to cancel the payment
    static const int MAX_QUEUE_SIZE = 10;

//!The constructor of the class with a parameter id
    mainController(unsigned long id);


//! Returns the messagequeue of the class
    osapi::MsgQueue* getMsgQueue();

//! Enum contains different message id's. 
    enum{
        ID_START_IND,
        ID_FINALROPELENGTHFROMGUI_IND,
        ID_UPDATEAMOUNTTOPAYTOGUI_IND,
        ID_CANCELFROMGUI_IND,
        ID_COIN_IND

    };
  
//! If priceForRope_ <= amoutPaid_ then it sends finalRopeLength_ to snorHaandtering
    void checkIfPriceReached();

    //double[] convertAmountToCoins(double amount);

protected:
    
//! The event-loop of the class. It receives a message, call the dispatcher with an id and a message and then delete the message.
     void run();

private:

//! Pointer to i2c class so the function i2cSend can be called
    i2c *helper;

//! mainController's FIFO message queue where received events are stored.
    osapi::MsgQueue mq_;

//! The id of the constructor
    unsigned long id_;
    
 //! Event loop exit if set to false.    
    bool running_; 

 //! The rope length GUI sends to mainController   
    int finalRopeLength_;

 //! The amount the customer have to pay for the choosen rope length   
    double priceForRope_;

//! The amount the customer have paid
    double amountPaid_;

 //! When the class receives the finalRopeLength from GUI it sets finalRopeLength_ equal to finalRopeLength    
    void finalRopeLengthFromGUIHandle(FinalRopeLength *ropeMessage);

 //! When receiving a coin input the coinHandle updates the amoutPaid_ and send it to GUI.    
    void coinHandle(double coinValue);

//!  It is supposed to send to MontDosering what it is going to give back to the customer
//! After that it reset the value of finalRopeLength_ and amountPaid_   
    void cancelFromGUIHandle();

//! The dispatcher of the class. It receives an id and a message. According to the id it calls a different function.   
    void mainControllerHandler(unsigned long id, osapi::Message* msg);    
};

#endif

