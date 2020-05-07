#include "FakeReceiver.hpp"

// Documentation comments in headerfile.

FakeReceiver::FakeReceiver(): mq_(MAX_QUEUE_SIZE), running_(true) {} 

void FakeReceiver::run()
{
  std::cout << "Event loop in FakeReceiver started running!" << std::endl;
  while(running_)
  {
    unsigned long int id;
    osapi::Message* msg = mq_.receive(id);
    FakeReceiverHandler(id, msg);
    delete msg;
  }
}

osapi::MsgQueue *FakeReceiver::getMsgQueue() { return &mq_; }

void FakeReceiver::FakeReceiverHandler(unsigned int id, osapi::Message* msg)
{
  switch(id)
  {
    case ID_COIN_IND:
      FakeReceiverHandleCoin(static_cast<Coin*>(msg));
      break;

    default:
     break;
  }
}

void FakeReceiver::FakeReceiverHandleCoin(Coin* coin)
{
    std::cout << "FakeReceiver received coin with value: " << coin->value << "!" << std::endl;
}