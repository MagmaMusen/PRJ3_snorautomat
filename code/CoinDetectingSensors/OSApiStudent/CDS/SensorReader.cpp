#include "SensorReader.hpp"

// Documentation comments in headerfile.

SensorReader::SensorReader(CoinIdentifier *identifier)
    : mq_(MAX_QUEUE_SIZE), running_(true)
{
  identifier_ = identifier;
}

osapi::MsgQueue *SensorReader::getMsgQueue() { return &mq_; }

void SensorReader::run()
{
  std::cout << "Event loop in SensorReader started running!" << std::endl;
  while (running_)
  {
    unsigned long int id;
    osapi::Message *  msg = mq_.receive(id);
    sensorReaderHandler(id, msg);
    delete msg;
  }
}

void SensorReader::sensorReaderHandler(unsigned int id, osapi::Message *msg)
{
  switch (id)
  {
  case ID_READ_IND:
    sensorReaderHandleRead();
    break;

  default:
    break;
  }
}

void SensorReader::sensorReaderHandleRead()
{
  std::ifstream sensordriverfile("/dev/CDS");

  std::cout << "Started read handler in SensorReader!" << std::endl;


  if (sensordriverfile.is_open())
  {
    while (getline(sensordriverfile, linereading_))
    {
      // 'Reading' string might now contain something like "353432,364335".

      // Seperate string into the two captured timings.
      CoinTimings* capture = new CoinTimings;
      extractTimes(linereading_, delimiter_, capture);

      // Send to identifier.
      identifier_->getMsgQueue()->send(ID_IDENTIFY_IND, capture);
      // identifier_->Identify(capturedTimeA_, capturedTimeB_);
    }

    sensordriverfile.close();
  }

  else
    std::cout << "Unable to open file /dev/CDS. Have you made a device node "
                 "for the sensors?"
              << std::endl;
}

// Seperate line by delimiter and update capture.
void SensorReader::extractTimes(std::string line, std::string delimiter, CoinTimings* timings)
{
  size_t                 pos = 0;
  std::string::size_type sz;

  pos = line.find(delimiter);

  timings->timeDifferenceRising = std::stol(line.substr(0, pos), &sz);
  line.erase(0, pos + delimiter_.length());
  timings->timeDifferenceEnterExit = std::stol(line, &sz);
}