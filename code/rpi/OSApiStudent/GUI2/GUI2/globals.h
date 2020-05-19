#ifndef GLOBALS_H
#define GLOBALS_H


/*
 * @int ropeLength  global variabel which is the value of the rope length the customer order
 */
extern int ropeLength;
/*
 * @double price    the price the customer has to pay for the rope
 */
extern double price;
/*
 * @double priceBack    The amount the customer has to get back after it has paid for the rope
 */
extern double priceBack;
/*
 *  @int maximumRopeLength  The maximum rope length a customer can order at the machine
 */
extern int maximumRopeLength;
/*
 * @int minimumRopeLength   The minimum rope length a customer can order at the machine
 */
extern int minimumRopeLength;
/*
 * @int ropeLengthAdded     The rope length the customer add to the current global variabel ropeLength
 */
extern int ropeLengthAdded;

extern bool sendRopeLength;
/*
 * @bool sendRopeLength     Sets
 */
#endif // GLOBALS_H
