#ifndef COMMUNICATIONTOMAINCONTROLLER_H
#define COMMUNICATIONTOMAINCONTROLLER_H

#include <osapi/ThreadFunctor.hpp>
#include <osapi/Mutex.hpp>
#include <osapi/MsgQueue.hpp>


//! Struct that contains the customer have choosen to cancel the payment
struct CancelPayments : public osapi::Message
{
    bool CancelClicked;
    //osapi::MsgQueue* mq_;
};
//! Struct that contains the ropeLength the customer have choosen
struct FinalRopeLength  :   public osapi::Message
{
    int finalRopeLength;
};

//! The class is the communication between GUI and mainController
//! The class inherits from OSAPI ThreadFunctor to be able to communicate with mainController
class communicationToMainController : public osapi::ThreadFunctor
{
public:
    //!The constructor of the class with a parameter id
    communicationToMainController(unsigned long id);

    //! The size of the messagequeue
    static const int MAX_QUEUE_SIZE = 10;

    //! Returns the messagequeue of the class
    osapi::MsgQueue* getMsgQueue();

    //! Enum contains different message id's.
    enum
    {
      ID_START_IND,
      ID_FINALEROPELENGTHFROMGUI_IND,
      ID_UPDATEAMOUNTTOPAYTOGUI_IND,
      ID_CANCELFROMGUI_IND,
    };
    //! The dispatcher of the class. It receives an id and a message and decide by the id which method it is going to call.
    void communicationToMainControllerControllerHandler(unsigned long id, osapi::Message* msg);
    //! It sends the decided ropeLength that the customer have choosen to mainController
    void finalRopeLengthFromGUIHandle();
    //! It receives continuously the amount the customer have to pay for the rope
    void updateAmountToPayGUIHandle(AmountLeft *moneyLeft);
    //! It sends to the mainController that the customer have choosen to cancel the purchase
    void cancelFromGUIHandle();
    //! It begins the entire event-loop of the class
    void startGUIMsgQueue();


protected:
    //! The event-loop of the class. It receives a message, call the dispatcher with an id and a message and then delete the message.
    void run();
private:
    //! The class' messagequeue attribute. It stores message's in the messagequeue when receiving events.
    osapi::MsgQueue mq_;
    //! The 
    unsigned long id_;
    //! The event-loop run while it is set to true
    bool running_;

    //mainController* mC_;    
};

#endif // COMMUNICATIONTOMAINCONTROLLER_H
