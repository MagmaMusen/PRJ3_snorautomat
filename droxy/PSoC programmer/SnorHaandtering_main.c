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
 *  This is the documentation for the SnorAutomat software.
 *  It is possible too see the different main files for both the c++ and c programs for this project. For the project compiled to linux interfaced RPI, there is also a makefile.
 *  In the pages there is the different files for the different parts of this projects.
 *  For futher documentation on the libarys used, it is possible to see all the used files under files.
 * - \subpage SnorAutomat_Snor "SnorHaandtering PSoC"
 *
 * - \subpage SnorAutomat_Dosering "Dosering PSoC"
 *
 * - \subpage SnorAutomat_Snor_H "SnorHaandtering PSoC og Hardware"
 * 
 * - \subpage SnorAutomat_Monttaeller "Moenttaeller software"
 *
 * - \subpage SnorAutomat_I2C "I2C"
 *
 * - \subpage SnorAutomat_mainController "mainController"
 *
 * - \subpage SnorAutomat_GUI "2. udkast - med messageQueue"	
 */ 

/*! \page SnorAutomat_Snor SnorHaandtering PSoC
 *
 *  This is for the PSoC, it is the main file wich also contains all the functions that is run in the main.
 *  The program is for microcontroller PSoC CYCKIT-059 from cypress. For this to be implemented on the PSoC there is also a set up file for pins, I2C buss and so on, this is found in the ducumentation under ducumentation PSoC and you need PSoC creater to open it.
 *  
 * \include <SnorHaandtering_main.c
 *. 
 *
 */

/*! \page SnorAutomat_Dosering Dosering PSoC
 *
 *  This is for the PSoC, it is the main file wich also contains all the functions that is run in the main.
 *  The program is for microcontroller PSoC CYCKIT-059 from cypress. For this to be implemented on the PSoC there is also a set up file for pins, I2C buss and so on, this is found in the ducumentation under ducumentation PSoC and you need PSoC creater to open it.
 *
 *  \include <Doserings_main.c
 */

/*! \page SnorAutomat_Snor_H SnorHaandtering PSoC og Hardware
*   
*   
*   This is the main for the PSoC that isn't used but it shows how we would make it. The code isn't tested fully because we don't have the hardware to make it, but it is tested with the first ans smaller stepper motor.
*   The program is for microcontroller PSoC CYCKIT-059 from cypress. For this to be implemented on the PSoC there is also a set up file for pins, I2C buss and so on, this is found in the ducumentation under ducumentation PSoC and you need PSoC creater to open it.
*
*  \include <SnorHaandteringMedHardware_main.c
*/

/*! \page SnorAutomat_Monttaeller Moenttaeller software
 *
 *  This page is quick way to access the most important parts of the moenttaeller software.
 *
 *  \include <mainCDS.cpp
 *  \include <SensorReader.hpp
 *  \include <SensorReader.cpp
 *  \include <CoinIdentifier.hpp
 *  \include <CoinIdentifier.cpp
 *  \include <CDSdriver.c
 */

/*! \page SnorAutomat_I2C I2C
*
*	The code to the i2c class
*	
*	\include <I2CVirtual.hpp
*	\include <I2CVirtual.cpp
*	\include <mainI2CVirtual.cpp
*
*/


/*! \page SnorAutomat_mainController mainController
*
*	mainController's event-loop
*
*	\include <mainController.hpp
*	\include <mainController.cpp
*	\include <mainMainController.cpp
* 
*/


/*! \paeg SnorAutomat_GUI 2. udkast - med messageQueue
*
*	This is the GUI that are using osapi library
*
*	\include <communicationtomaincontroller.hpp
*	\include <globals.hpp
*	\include <mainwindow.hpp
*	\include <orderropelengthwindow.hpp
*	\include <paymentwindow.hpp
*	\include <paidwindow.hpp
*	\include <communicationtomaincontroller.cpp
*	\include <globals.cpp
*	\include <mainwindow.cpp
*	\include <orderropelengthwindow.cpp
*	\include <paymentwindow.cpp
*	\include <paidwindow.cpp
*	\include <mainGUI.cpp
*	\include <mainwindow.ui
*	\include <orderopelengthwindow.ui
*	\include <paymentwindow.ui
*	\include <paidwindow.ui
*
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
