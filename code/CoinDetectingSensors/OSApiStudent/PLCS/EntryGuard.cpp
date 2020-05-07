#include "EntryGuard.hpp"

EntryGuard::EntryGuard()
: mq_(MAX_QUEUE_SIZE), running_(true)
{
    
}

osapi::MsgQueue* EntryGuard::getMsgQueue()
{
    return &mq_;
}

void EntryGuard::entryBarrierControllerHandleIdEntryBarrierOpenReq(BarrierOpenReq* req)
{
    BarrierOpenCfm* cfm = new BarrierOpenCfm;
    cfm->result_ = true;
    req->mq_->send(ID_ENTRYBARRIER_OPEN_CFM, cfm); 
}

void EntryGuard::entryBarrierControllerHandler(unsigned long id, osapi::Message* msg)
{
    switch(id)
    {
        case ID_ENTRYBARRIER_OPEN_REQ:
            entryBarrierControllerHandleIdEntryBarrierOpenReq(static_cast<BarrierOpenReq*>(msg));
            break;
            
        default:
            break;
    }
}

void EntryGuard::run()
{
    while(running_)
    {
        unsigned long int id;
        osapi::Message* msg = mq_.receive(id);
        entryBarrierControllerHandler(id, msg);
        delete msg;
    }
}
