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
void udrulningStart(void);
void udrulningRunning(void);

/*
*   Same as the main program with I2C
*/
uint8 buffer[BUFFER_SIZE];
/*
*   Used in the delay buffer, can be ajusted to how fast the motor can go.
*/
int speed = 1; //speed 
/*
*   State used if you want more than one state in the driver system.
*/
int state = 0; //state
/*
*   Depending if it will run, is turned on and of in the software for the motor control.
*/
int start = 0; // start
/*
*   If changed it will go the opesit direction, it is used if we put antother motor in or changed the side, that we run the motor from.
*/
int dir = 0; //direction
/*
*   Same as the main program with I2C
*/
int BUFFER_SIZE = 6;
/*
*   Used to remember how many 1/4 rotations we have left 
*/
uint8 dispense = 0;
/*
*   
*/
int rotate = 0;//rotate
/*
*   Is used for the waveform we use, but it can contaion 3 more, if you need more power or steps from the motor.
*/
int stateArray[3][8][4] = //waveArray
                        {{{1,0,0,0},
                         {0,1,0,0},
                         {0,0,1,0},
                         {0,0,0,1},
                         {1,0,0,0},
                         {0,1,0,0},
                         {0,0,1,0},
                         {0,0,0,1}}};

/*
*   In main the system is initialized and the program part is in the forever foor loop. In the foor loop there is a function to start the motors and one to run the motor.
*/
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    initI2C();


    int index =0;

    for (;;)
    {
        udrulningStart();
        udrulningRunning();
    }
}


/*
*   Same as the main program with I2C
*/
void initI2C(void)
{
    I2C_Start();
    uint8* buf = &buffer[0];
    I2C_SlaveInitWriteBuf(buf, BUFFER_SIZE);
    I2C_SlaveClearWriteBuf();
}

/*
*   This function checks if the I2C have recived anything. If there is anything it takes the number and times it with 2025, the mumber is to be ajusted for the lenght of the command for every number. After this number of rotations is asigned to the global parameter it sends the I2C bus too sleep. 2025 is 10 centimeters with another and smaller motor, wich was tested but too small.
*/
void udrulningStart(void)
{

    if (I2C_SlaveStatus() & I2C_1_SSTAT_WR_CMPLT)
    {
        dispense = buf[0] * 2025;
        rotate = 1;
        start = 1;
        dir = 0;
        I2C_sleep();
    }
}


/*
*   If the previusly function is activated this functions starts to deliver the cord to the customer. When it is done it wakes up the I2C bus. It is in this function that the speed and rotation is used.
*/
void udrulningRunning(void)
{
    if (start == 1)
    {
        Pin_1A_Write(stateArray[state][index][0]);
        CyDelay(speed);
        Pin_2A_Write(stateArray[state][index][1]);
        CyDelay(speed);
        Pin_1B_Write(stateArray[state][index][2]);
        CyDelay(speed);
        Pin_2B_Write(stateArray[state][index][3]);
        CyDelay(speed);

        if (dir == 0 && index == 8)
            index = 0;
        else if (dir == 1 && index == 0)
            index = 8;
        else if (dir == 0)
            index++;
        else if (dir == 1)
            index--;

        if (rotate == 1)
        {
            dispence -= 1;

            if (dispence < 0)
            {
                start = 0;
                rotate = 0;
            }
            I2C_Wakeup();
        }
    }
}

/* [] END OF FILE */
