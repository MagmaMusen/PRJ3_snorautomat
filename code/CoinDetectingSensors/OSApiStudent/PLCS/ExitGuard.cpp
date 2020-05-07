#include "ExitGuard.hpp"

ExitGuard::ExitGuard()
: mq_(MAX_QUEUE_SIZE), running_(true)
{

}

osapi::MsgQueue* ExitGuard::getMsgQueue()
{
    return &mq_;
}

void ExitGuard::exitBarrierControllerHandler(unsigned long id, osapi::Message* msg)
{
    switch (id)
    {
    case ID_EXITBARRIER_OPEN_REQ:
        exitBarrierControllerHandlerIdExitBarrierOpenReq(static_cast<BarrierOpenReq*>(msg));
        break;

    default:
        break;
    }
}

void ExitGuard::exitBarrierControllerHandlerIdExitBarrierOpenReq(BarrierOpenReq* req)
{
    BarrierOpenCfm* cfm = new BarrierOpenCfm;
    cfm->result_ = true;
    req->mq_->send(ID_EXITBARRIER_OPEN_CFM, cfm);
}

void ExitGuard::run()
{
    while (running_)//ever
    {
        unsigned long id;
        osapi::Message* msg = mq_.receive(id);
        exitBarrierControllerHandler(id, msg);
        delete msg;
    }
}
