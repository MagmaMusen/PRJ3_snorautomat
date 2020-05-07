#include "CoinIdentifier.hpp"
#include "SensorReader.hpp"
#include "FakeReceiver.hpp"
#include <iostream>
#include <osapi/Thread.hpp>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  if (argc > 1)
  {
    std::cout << "Sensor main() called with millimeter calibration: " << *argv[1]
              << std::endl;
    

  }
  else
  {
    std::cout << "Sensor main() called without calibration argument which "
                 "hopefully works!"
              << std::endl;
    std::cout << "First argument can be used to increase or decrease expected "
                 "coin widths."
              << std::endl;

    
    
  }

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
