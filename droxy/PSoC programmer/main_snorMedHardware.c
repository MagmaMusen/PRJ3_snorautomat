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


uint8 buffer[BUFFER_SIZE];
int rot = 0; //Rotation
int speed = 1; //speed 
int state = 0; //state
int start = 0; // start
int dir = 0; //direction
int BUFFER_SIZE = 6;
uint8 dispense = 0;

int rotate = 0;//rotate

int stateArray[3][8][4] = //waveArray
                        {{{1,0,0,0},
                         {0,1,0,0},
                         {0,0,1,0},
                         {0,0,0,1},
                         {1,0,0,0},
                         {0,1,0,0},
                         {0,0,1,0},
                         {0,0,0,1}}};

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


//void udrulning(uint8 rot)
//{
//         
//            start = 0;
//            CyDelay(1000);
//            rotate = 1;
//            //rot;
//          
//            Pin_test_Write(1);
//            dir = 0;
//            state = 0;
//            start = 1;
//}







void initI2C(void)
{
    I2C_Start();
    uint8* buf = &buffer[0];
    I2C_SlaveInitWriteBuf(buf, BUFFER_SIZE);
    I2C_SlaveClearWriteBuf();
}

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
                UART_PutString("Rotation stoppet");
            }
            I2C_Wakeup();
        }
    }
}

/* [] END OF FILE */
