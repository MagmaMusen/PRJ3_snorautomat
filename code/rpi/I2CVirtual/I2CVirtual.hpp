#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

class i2c
{
    public:
    /*
    *   @i2c()      Constructoren for I2C class. It opens the I2c protocol and IOCTL on the rpi
    *           
    *   @param[in]  adresse     Set the adress for the I2C protcol on the Rpi.
    *         
    */
    i2c(int adresse);
    /*
    *   @void i2cSend()     It sends a char buffer from master to slave by I2C.
    *   
    */
    void i2cSend(char buffer1);
    /*
    *   @char i2cReceive()      It returns a char buffer from slave to master by I2C.
    *   
    *   @param[out] buffer1     The buffer which is sent from master to slave
    */
    char i2cReceive();

    private:
    int adresse_;
    char buffer_;
};