#ifndef COMMUNICATIONTOMAINCONTROLLER_H
#define COMMUNICATIONTOMAINCONTROLLER_H

#include <osapi/ThreadFunctor.hpp>
#include <osapi/Mutex.hpp>
#include <osapi/MsgQueue.hpp>


struct CancelPayments : public osapi::Message
{
    bool CancelClicked;
    //osapi::MsgQueue* mq_;
};
struct FinalRopeLength  :   public osapi::Message
{
    int finalRopeLength;
};


class communicationToMainController : public osapi::ThreadFunctor
{
public:
    communicationToMainController(unsigned int id);
    virtual ~communicationToMainController();
    static const int MAX_QUEUE_SIZE = 10;
    osapi::MsgQueue* getMsgQueue();
    enum
    {
      ID_START_IND,
      ID_FINALEROPELENGTHFROMGUI_IND,
      ID_UPDATEAMOUNTTOPAYTOGUI_IND,
      ID_CANCELFROMGUI_IND,

    };

    void communicationToMainControllerControllerHandler(unsigned int id, osapi::Message* msg);
    void finalRopeLengthFromGUIHandle();
    //void updateAmountToPayGUIHandle(AmountLeft *moneyLeft);
    void cancelFromGUIHandle();
    void startGUIMsgQueue();

protected:
    void run();
private:
    osapi::MsgQueue mq_;

    unsigned long id_;
    bool running_;

    //mainController* mC_;
};

#endif // COMMUNICATIONTOMAINCONTROLLER_H
