#ifndef GLOBALS_H
#define GLOBALS_H


//! Global variabel which is the value of the rope length the customer order
extern int ropeLength;

//! The price the customer has to pay for the rope
extern double price;

//! The amount the customer has to get back after it has paid for the rope
extern double priceBack;

//! The maximum rope length a customer can order at the machine
extern int maximumRopeLength;

//! The minimum rope length a customer can order at the machine
extern int minimumRopeLength;

//! The rope length the customer add to the current global variabel ropeLength
extern int ropeLengthAdded;

//! If the customer have choosen its ropeLength sendRopeLength is set to true
extern bool sendRopeLength;

#endif // GLOBALS_H
