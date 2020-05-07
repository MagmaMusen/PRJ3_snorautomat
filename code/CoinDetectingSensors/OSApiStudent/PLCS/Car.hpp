#ifndef CAR_HPP
#define CAR_HPP

#include <osapi/MsgQueue.hpp>
#include <osapi/Mutex.hpp>
#include <osapi/ThreadFunctor.hpp>
#include "EntryGuard.hpp"
#include "ExitGuard.hpp"

class EntryGuard;
class ExitGuard;

class Car : public osapi::ThreadFunctor
{
    public:
        static const int MAX_QUEUE_SIZE = 1;
        Car(unsigned int id, EntryGuard* eng, ExitGuard* exg);
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
        void carHandler(unsigned int id, osapi::Message* msg);
        void carHandleIdStartInd();
        void carHandleIdEntryBarrierOpenCfm(BarrierOpenCfm* cfm);
        void carHandleIdExitBarrierOpenCfm(BarrierOpenCfm* cfm);
        void startCar();

        bool running_;
        osapi::Mutex mut_;
        osapi::MsgQueue carMq_;
        unsigned int id_;
        EntryGuard* eng_;
        ExitGuard* exg_;
};

#endif