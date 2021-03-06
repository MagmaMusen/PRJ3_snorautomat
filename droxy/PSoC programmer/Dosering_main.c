/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

/*!
* Just for writeability 
*/


#define Wait(x)					                        // Just for readability
/*!
* Size of I2C buffers
*/
#define BufSize					10						//	Size of I2C buffers
/*!
* Slave Address, every Slave must have an address to be known by the Master 
*/
#define SlaveAddr				0x08					//	Address of slave
/*!
* This is the Buffer for the Slave, Master will use this buffer.
*/
uint8  wrBuf[BufSize];						//	Buffer for Master -> Slave
uint8  rdBuf[BufSize];							//	Buffer for Master <- Slave

uint8 byteCnt = 0;
/*!
* This part is to init the PWM. First we start the PWM that we placed in the TopDesign.
*after that the PWM_x_WriteCompare Writes the compare values for the compare output. 
*to init the I2C, The I2C slave fisrt will start, the I2C write buf will be initialized. this is the buffer that the Master will write too. 
*/
void InitializeSystem(void)
{ 

	CyGlobalIntEnable;

    
    PWM_50_Start();
    PWM_50_WriteCompare(1);
    PWM_1_Start();
    PWM_1_WriteCompare(1);
    PWM_2_Start();
    PWM_2_WriteCompare(1);
    PWM_5_Start();
    PWM_5_WriteCompare(1);
    PWM_10_Start();
    PWM_10_WriteCompare(1);
    Slave_I2C_Start();	
  
    uint8 *buf = &wrBuf[0];
	Slave_I2C_SlaveInitWriteBuf(buf,BufSize);
    //Slave_I2C_Start();										//	Initialize I2C slave

    CyDelay(500); 
    
}

/*!
* The program will run in the main. The InitializeSystem  will be called to initialize the I2C function and PWM function.
* The for Loop contains the Dosering function which is the most important part in the program. 
* This the if() will first check on the write slave flag, if it is low nothing will happen but the function will be runned agin. the function will turn on the specific servo motor all after which is the buffer size contains, and after that will generate the PWM signal to run the Motor.
* when the motor is done running, the slave buffer and flag will be cleared.  
*/
int main()
{
  
    InitializeSystem();
    
    for(;;)
    {
        if(Slave_I2C_SlaveStatus() & Slave_I2C_SSTAT_WR_CMPLT )  //Check if read transaction is completed
        {    
            uint8 I2C= Slave_I2C_SlaveGetWriteBufSize();
              uint8 ii = 0;
            for (ii = 0; ii < I2C; ii++)
            {
                
            	if (wrBuf[ii] == 0b00110010)
            	{
                    Pin_1_Write(1);
                    PWM_50_WriteCompare(5990);
                    CyDelay(1000);
                    PWM_50_WriteCompare(99);
                    CyDelay(1000);
                  
            		//gør hvad der skal gøres for 50 øre
            	}
            	if (wrBuf[ii] == 0b00000001)
            	{
                     PWM_1_WriteCompare(5990);
                    CyDelay(1000);
                    PWM_1_WriteCompare(99);
                    CyDelay(1000);
                    Pin_1_Write(1);
            		//gør hvad der skal gøres for 1 krone
            	}
            	if (wrBuf[ii] == 0b00000010)
            	{
                     PWM_2_WriteCompare(5990);
                    CyDelay(1000);
                    PWM_2_WriteCompare(99);
                    CyDelay(1000);
            		//gør hvad der skal gøres for 2 kroner
            	}
            	if (wrBuf[ii] == 0b00000101)
            	{
                     PWM_5_WriteCompare(5990);
                    CyDelay(1000);
                    PWM_5_WriteCompare(99);
                    CyDelay(1000);
            		//gør hvad der skal gøres for 5 kroner
            	}
            	if (wrBuf[ii] == 0b00001010)
            	{
                    PWM_10_WriteCompare(5990);
                    CyDelay(1000);
                    PWM_10_WriteCompare(99);
                    CyDelay(1000);
            		//gør hvad der skal gøres for 10 kroner
            	}
            Slave_I2C_SlaveClearWriteBuf();
        	
        	Slave_I2C_SlaveClearWriteStatus();
            }
       
        } 
    } 
  
    

   return 0; 
}

/* [] END OF FILE */
