#include "Car.hpp"
#include <iostream>
#include <osapi/Utility.hpp>
#include <stdlib.h>

Car::Car(unsigned int id, EntryGuard* eng, ExitGuard* exg)
: carMq_(MAX_QUEUE_SIZE), running_(true)
{
    id_ = id;
    eng_ = eng;
    exg_ = exg;
}

osapi::MsgQueue* Car::getMsgQueue()
{
    return &carMq_;
}

void Car::run()
{
    startCar();
    while(running_)
    {
        unsigned long int id;
        osapi::Message* msg = carMq_.receive(id);
        carHandler(id, msg);
        delete msg;
    }
}

void Car::carHandler(unsigned int id, osapi::Message* msg)
{
    switch(id)
    {
        case ID_START_IND:
            carHandleIdStartInd();
            break;

        case ID_ENTRYBARRIER_OPEN_CFM:
            carHandleIdEntryBarrierOpenCfm(static_cast<BarrierOpenCfm*>(msg));
            break;

        case ID_EXITBARRIER_OPEN_CFM:
            carHandleIdExitBarrierOpenCfm(static_cast<BarrierOpenCfm*>(msg));
            break;

        default:
            break;
    }
}

void Car::carHandleIdStartInd()
{
    mut_.lock();
    std::cout << "Car \e[1m#" << id_ << "\e[0m - drives \e[1mUP TO \e[0mPLCS" << std::endl;
    mut_.unlock();
    
    BarrierOpenReq* req = new BarrierOpenReq;
    req->mq_ = &carMq_;
    eng_->getMsgQueue()->send(ID_ENTRYBARRIER_OPEN_REQ, req);
}

void Car::carHandleIdEntryBarrierOpenCfm(BarrierOpenCfm* cfm)
{
    if(cfm->result_)
    {
        /*Bilen kører ind på parkeringspladsen*/
        mut_.lock();
        std::cout << "Car \e[1m#" << id_ << "\e[0m - drives \e[1mINTO \e[0mPLCS" << std::endl;
        mut_.unlock();

        /*Bilen venter tilfældig lang tid inde på parkeringspldsen*/
        unsigned int sleepTime = (rand()%5000+1000);
        osapi::sleep(sleepTime);

        /*Bilen kører ud fra perkeringspladsen*/
        mut_.lock();
        std::cout << "Car \e[1m#" << id_ <<"\e[0m - \e[1mPARKED \e[0mfor \e[1m"<< (sleepTime/1000) <<" sec.\e[0m" << std::endl;
        mut_.unlock();

        BarrierOpenReq* req = new BarrierOpenReq;
        req->mq_ = &carMq_;
        exg_->getMsgQueue()->send(ID_EXITBARRIER_OPEN_REQ, req);
    }
}

void Car::carHandleIdExitBarrierOpenCfm(BarrierOpenCfm* cfm)
{
    if(cfm->result_)
    {
        mut_.lock();
        std::cout << "Car \e[1m#"<< id_ << "\e[0m - drives \e[1mOUT OF \e[0mPLCS" << std::endl;
        mut_.unlock();

        osapi::sleep(rand()%5000+1000);

        /*Gentag parkerings process*/
        startCar();
    }
}

void Car::startCar()
{
    carMq_.send(ID_START_IND);
}



