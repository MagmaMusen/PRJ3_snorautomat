#include "I2CVirtual.hpp"
#include <unistd.h>


int main()
{
    i2c name(0x48);
    
    for(;;)
    {
       name.i2cSend(0b00000011);
       /*sleep(1);
       name.i2cReceive();*/
        /*if (name.i2cReceive() == 0b11111111)
        {
            printf("RecievedGGGGG data\n");*/
        //}
        sleep(1);
    }
    return 0;
}