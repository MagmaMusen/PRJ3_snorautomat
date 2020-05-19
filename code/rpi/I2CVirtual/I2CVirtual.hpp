#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

class i2c
{
    public:
    
    //! Costructoren for I2C class. It opens the I2c protocol and IOCTL on the Rpi
    //! Set the address for the I2C protocol on the Rpi         
    i2c(int adresse);
    
    //! It sends a char buffer from master to slave by I2C. 
    void i2cSend(char buffer1);

//! It returns a char buffer from slave to master by I2C. 
//! The buffer1 is the buffer which is sent from master to slave
    char i2cReceive();

    private:
    
//! The address of i2c slave 
    int adresse_;

//! The buffer that is being send from master to slave
    char buffer_;
};