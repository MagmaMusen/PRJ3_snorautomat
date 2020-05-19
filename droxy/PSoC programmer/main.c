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

void initI2C(void);
void udrulning(void);

/*! \mainpage Snor Maskine
 *
 * This project helps user to draw shapes.
 * Currently two types of shapes can be drawn:
 * - \subpage Snor "Main fra snorhåndtering PSoC"
 *
 * - \subpage Dosering "Main fra dosering PSoC"
 *
 */ 

/*! \page Snor Main fra snorhåndtering PSoC
 *
 * så bobbe det virker
 * \include <main.c
 *
 */

/*! \page Dosering Main fra dosering PSoC
 *
 *
 * \include <Doserings_main.c
 */



/*!
*Decleration of the buffer size which is used in thee function void initI2C(void). It is written as a global variable so it can be used every where in the program later.
*/
int BUFFER_SIZE = 6;

/*!
*Here is the buffer set, it is the one that initI2C(void) uses. It is preset to have six spots of 0, because when you use microprocessers, you cant use dynamic allocation as usualæ
*/
uint8 buffer[]= {0,0,0,0,0,0};

/*!
*   In main the program is put together in the start the function initI2C() is called.
*   After that there is an infinity for loop wich runs the udrulning() function.
*/
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    initI2C();
    
    for(;;)
    {
        udrulning();
    }
}

/*!
*
*To init the I2C function, firstly we start the I2C that we placed in the topdesign.
*Secondly the I2C Write Buf is initialized, this is the buf that the master writes too. It is the previously made buffer, this program will only use the first one, but this funtion is made so it can be implemented in our other PSoC programs.
*The last line do clear the buffer, the PSoC can have problems with it's topdesigns if you dont clear them.
*/
void initI2C(void)
{
    I2C_1_Start();
    uint8 *buf = &buffer[0];
    I2C_1_SlaveInitWriteBuf(buf, BUFFER_SIZE);
    I2C_1_SlaveClearWriteBuf();
}

/*!
*  This function will first tjek on the write slave flag, if it is low nothing will happen but the function will be runned agin. If it is high,the function will turn on the motor for 5 second for every number recived in the first byte.
*  To turn on the motor the PWM in the topdesign will be used. When the motor is done running, the slave buf and flag will be cleared.
*/
void udrulning(void)
{
    
    if(I2C_1_SlaveStatus() & I2C_1_SSTAT_WR_CMPLT)
        {
            uint8 i = 0;
            for(i = 0;i < buffer[0];++i)
            {
                PWM_1_Start();
                CyDelay(5000);
                PWM_1_Stop();
            }
            I2C_1_SlaveClearWriteBuf();
            I2C_1_SlaveClearWriteStatus();
        }
}

/* [] END OF FILE */