#include "CoinIdentifier.hpp"

// Documentation comments in headerfile.

CoinIdentifier::CoinIdentifier(osapi::MsgQueue* receiver): mq_(MAX_QUEUE_SIZE), running_(true)
{
  receiver_ = receiver;
} 

void CoinIdentifier::run()
{
  std::cout << "Event loop in CoinIdentifier started running!" << std::endl;
  while(running_)
  {
    unsigned long int id;
    osapi::Message* msg = mq_.receive(id);
    CoinIdentifierHandler(id, msg);
    delete msg;
  }
}

osapi::MsgQueue *CoinIdentifier::getMsgQueue() { return &mq_; }

void CoinIdentifier::CoinIdentifierHandler(unsigned int id, osapi::Message* msg)
{
  switch(id)
  {
    case ID_IDENTIFY_IND:
      std::cout << "Received a time signature in identifer, running handler!" << std::endl;
      CoinIdentifierHandleIdentify(static_cast<CoinTimings*>(msg));
      break;
    default:
      std::cout << "Unidentified ID in Identifier handler." << std::endl;
      break;
  }
}

void CoinIdentifier::CoinIdentifierHandleIdentify(CoinTimings* timing)
{
  std::cout << "CoinTimings contains Rising:" << timing->timeDifferenceRising << " EnterExit: " << timing->timeDifferenceEnterExit << std::endl;
  // Physics! The distance covered divided by the time it took.
  float speed = sensorDistanceMillimeter_ / timing->timeDifferenceRising;

  // The speed of the coin multiplied by the amount of time spent in front of a sensor equals the width.
  float coinWidthMillimeter = speed * timing->timeDifferenceEnterExit;

  // For debugging.
  std::cout << "CoinIdentifier - Calculated coin width in millimeter:" << coinWidthMillimeter
            << std::endl;

  // Coin indication event message prepared.
  Coin* coin = new Coin;
  coin->value = widthToValue(coinWidthMillimeter);

  // Send message.
  receiver_->send(ID_COIN_IND, coin);
  std::cout << "Sent coin event to receiver from identifier!" << std::endl;
}

float CoinIdentifier::widthToValue(float width)
{
  // Convert the width to a value based on boundaries.
  if (width >= boundaryWidthOneLower && width < boundaryWidthOneFifty)
  {
    std::cout << "1 krone i identifier!" << std::endl;
    return 1;
  }
  else if (width > boundaryWidthOneFifty && width < boundaryWidthFiftyTen)
  {
    std::cout << "50 oere i identifier!" << std::endl;
    return 0.5;
  }
  else if (width > boundaryWidthFiftyTen && width < boundaryWidthTenTwo)
  {
    std::cout << "10 krone i identifier!" << std::endl;
    return 10;
  }
  else if (width > boundaryWidthTenTwo && width < boundaryWidthTwoTwenty)
  {
    std::cout << "2 krone i identifier!" << std::endl;
    return 2;
  }
  else if (width > boundaryWidthTwoTwenty && width < boundaryWidthTwentyFive)
  {
     std::cout << "20 krone i identifier!" << std::endl;
    return 20;
  }
  else if (width > boundaryWidthTwentyFive && width < boundaryWidthFiveUpper)
  {
    std::cout << "5 krone i identifier!" << std::endl;
    return 5;
  }
  else
  {
    std::cout << "Coin not identifiable, registered passing width: " << width << "mm!" <<  std::endl;
    return 0;
  }
}
