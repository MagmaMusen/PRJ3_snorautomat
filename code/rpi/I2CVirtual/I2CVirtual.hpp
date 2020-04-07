#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>







class i2c
{
    public:
    i2c(int adresse);
    void i2cSend(char buffer1);
    char i2cReceive();

    private:
    int adresse_;
    char buffer_;
};