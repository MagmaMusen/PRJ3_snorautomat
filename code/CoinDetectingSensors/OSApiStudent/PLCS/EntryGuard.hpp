#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <osapi/Message.hpp>
#include <osapi/MsgQueue.hpp>
#include <osapi/ThreadFunctor.hpp>

struct BarrierOpenReq : public osapi::Message
{
    osapi::MsgQueue* mq_;
};
struct BarrierOpenCfm : public osapi::Message
{
    bool result_;
};
struct CarInfo
{
    int id;
};

class EntryGuard : public osapi::ThreadFunctor
{
    public:
        static const int MAX_QUEUE_SIZE = 10;
        EntryGuard();
        osapi::MsgQueue* getMsgQueue();

        enum {
            ID_START_IND,
            ID_ENTRYBARRIER_OPEN_CFM,
            ID_ENTRYBARRIER_OPEN_REQ,
            ID_EXITBARRIER_OPEN_CFM,
            ID_EXITBARRIER_OPEN_REQ
        };

    protected:
        void run();
        
    private:
        void entryBarrierControllerHandler(unsigned long int id, osapi::Message* msg);
        void entryBarrierControllerHandleIdEntryBarrierOpenReq(BarrierOpenReq* req);
        
        bool running_;
        osapi::MsgQueue mq_;
};

#endif
