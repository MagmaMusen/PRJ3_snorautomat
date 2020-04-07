#include "I2CVirtual.hpp"
#define I2C_IOCTL 0x0703 // sytem call
//#define I2C_SLAVE 0x48
int fd_i2c;
i2c::i2c(int adresse)
{
    adresse_ = adresse; 
    
    char *filename = (char*) "/dev/i2c-1";

    if((fd_i2c = open (filename, O_RDWR)) < 0)
    {
        printf("Failed to open i2c\n"); // Printing out a error message if /dev/i2c wasn't able to be openned
    }

    if(ioctl(fd_i2c, I2C_IOCTL, adresse_) < 0)
    {
        printf("Failed to open IOCTL\n"); // Printing out a error message if IOCTL wasn't able to be openned
    }       
}
void i2c::i2cSend(char buffer1)
{
    // Write bytes
    //buffer[1] = 0b00000001; // Opportunity to expand
    int length = 2; // Number of bytes to send
    char bufferArray[60];
    bufferArray[0] = buffer1;
    //bufferArray[1] = buffer2;
    if(write(fd_i2c, bufferArray, length) != length)
    {
        printf("Failed to send I2C bus\n");
    }

}
char i2c::i2cReceive()
{
      // Receive bytes
        int length = 1; //Number of bytes to receive
        char bufferReceive;
        char bufferReceiveArray[60] = {0};
        //bufferReceiveArray[0] = bufferReceive;
        if (read(fd_i2c, bufferReceiveArray, length) != length)
        {
            
            printf("Failed to read I2C bus\n"); // Printing out a error message if it wasn't able to read bytes
            return 0;
        }
        else
        {
            bufferReceive = bufferReceiveArray[0];
            int value;
            sscanf(bufferReceiveArray, "%d",value); // Convert from char to integer
            printf("Received data: %d\n", value); //Print the value*/
            printf("Received data in char: %c \n", bufferReceiveArray);
            return bufferReceiveArray[0];
        }  
        
        /* return value; // if we want to return a integer instead */
    
}