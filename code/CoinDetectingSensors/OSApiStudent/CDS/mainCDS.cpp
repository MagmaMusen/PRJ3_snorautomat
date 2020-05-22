#include "CoinIdentifier.hpp"
#include "SensorReader.hpp"
#include "FakeReceiver.hpp"
#include <iostream>
#include <osapi/Thread.hpp>
#include <stdlib.h>

int main()
{
  FakeReceiver myReceiver; 
  CoinIdentifier myCoinIdentifier(myReceiver.getMsgQueue());
  SensorReader mySensorReader(&myCoinIdentifier);

  osapi::Thread receiverThread(&myReceiver);
  osapi::Thread identifierThread(&myCoinIdentifier);
  osapi::Thread readerThread(&mySensorReader);

  receiverThread.start();
  identifierThread.start();
  readerThread.start();

  receiverThread.join();
  identifierThread.join();
  readerThread.join();

  std::cout << "Exited read function in main()" << std::endl;

  return 1;
}
