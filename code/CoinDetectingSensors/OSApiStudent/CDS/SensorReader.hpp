#pragma once
#include "osapi/MsgQueue.hpp"
#include <osapi/Mutex.hpp>
#include <osapi/ThreadFunctor.hpp>
#include <string>
#include "CoinIdentifier.hpp"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

class CoinIdentifier;

//! Reads from the kernel character driver file at /dev/CDS to catch coin time signatures. 
//! Signatures are read as comma seperated values, then they are extracted and sent to a CoinIdentifier.
//! The class inherits from OSAPI ThreadFunctor class to enable starting the c++ class as a thread using POSIX-threads.
class SensorReader : public osapi::ThreadFunctor
{
public:
    //! Message queue size. Sending on a full queue will block sender to keep synchronized.
    static const int MAX_QUEUE_SIZE = 64;

    //! Constructor. Parameter is the identifier that will receive the time signature captures from SensorReader.
    SensorReader(CoinIdentifier* identifier);

    //! Event message ID's. Used to cast wrapper structs. They are received as their base-class Message and therefore need to be identified and casted. 
    enum {
        ID_READ_IND, 
        ID_IDENTIFY_IND
    };

    //! Returns message queue of the class.
    osapi::MsgQueue* getMsgQueue();

protected:

    //! Event loop. Receives messages from the message queue, calls the handler, then deletes the message.
    //! Is inherited from the ThreadFunctor class and overwritten.
    void run();

private:

    //! Indentifies messages on received on SensorReader's message queue, casts the message if needed and starts the correct handler function.
    void sensorReaderHandler(unsigned int id, osapi::Message* msg);

    //! Reads from /dev/CDS file which is the sensor character drivers node. Reading from the file returns time signatures as coins pass by the sensors.
    void sensorReaderHandleRead();

    //! Event loop exit if set to false.
    bool running_;


    //! SensorReader's FIFO message queue where received events are stored.
    osapi::MsgQueue mq_;

    //! Turns the string from read from the CDS-driver into captured timings in the specified CoinTimings struct. The delimiter is the seperator of the two time values read from the driver.
    void extractTimes(std::string line, std::string delimiter, CoinTimings* timings);

    //! Seperator between the time values read from the CDS-driver file.
    std::string delimiter_ = ",";

    //! Line read from the CDS-driver file.
    std::string linereading_;

    //! Receiver of the timing indication events, which will turn the time signatures into coin values.
    CoinIdentifier* identifier_;
};