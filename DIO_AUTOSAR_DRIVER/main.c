
/**
 * main.c
 */
#include "Dio.h"
void Init(void);
void Test_Valid_WriteChannel(uint8 Channel_ID, uint8 LEVEL);
void Test_inValid_WriteChannel(uint8 Channel_ID, uint8 LEVEL);
void Test_Valid_WritePort(uint8 PORTid, uint8 LEVEL_PORT);
void Test_inValid_WritePort(uint8 PORTid, uint8 LEVEL_PORT);
void Test_Valid_ReadChannelGroup(Dio_ChannelGroupType ChannelGroup);
void Test_inValid_ReadChannelGroup(uint8);

#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE108))
/*Activate PORTF Clock*/
volatile unsigned long delay;

void main(void);
void main(void)
{   /*******************************************STUB CODE ******************************************************/
    SYSCTL_RCGC2_R |= 0x00000020; /* 1) activate clock for Port F */

    delay = SYSCTL_RCGC2_R; /* allow time for clock to start */

    /*Disable Analog Function of PORTF*/
    PORTF->AMSEL = 0x00;
    /*Set Direction of PF1 , PF2 , PF3 output , PF4 i/p */
    PORTF->DIR |= 0x0E;
    /*Disable Alternate Function of PORTF*/
    PORTF->AFSEL = 0x00;
    /*Enable digital I/O on PF1 , PF2 , PF3 */
    PORTF->DEN = 0xff;
    /* Enable internal pull up */
    PORTF->PUR = 0x11;

    PORTF->DATA = 0x00;
    /**********************************************START OF TEST SECTION ********************************************/
    // Test_Valid_WriteChannel(1,STD_HIGH);
    // Test_inValid_WriteChannel(5,STD_HIGH);
    // Test_Valid_WritePort(5,STD_HIGH);
    // Test_inValid_WritePort(6,STD_HIGH);

    while (1)
    {   // Test_Valid_ReadChannelGroup( Dio_ChannelGroup[0]);
        // Test_inValid_ReadChannelGroup(NULL);

    }

}

void Test_Valid_WriteChannel(uint8 Channel_ID, uint8 LEVEL)
{
    Dio_WriteChannel(Channel_ID, LEVEL); /* Blue LED will turn on*/

}

void Test_inValid_WriteChannel(uint8 Channel_ID, uint8 LEVEL)
{
    Dio_WriteChannel(Channel_ID, LEVEL); /* Blue LED will not turn on*/

}

void Test_Valid_WritePort(uint8 PORTid, uint8 LEVEL_PORT)
{
    Dio_WritePort(PORTid, LEVEL_PORT); /* White LED will trun */

}
void Test_inValid_WritePort(uint8 PORTid, uint8 LEVEL_PORT)
{

    Dio_WritePort(PORTid, LEVEL_PORT); /* No Led will Turn On */

}

void Test_Valid_ReadChannelGroup(Dio_ChannelGroupType ChannelGroup)
{
    if (Dio_ReadChannelGroup(&ChannelGroup))
    {
        PORTF->DATA = (1 << 1);
        PORTF->DATA = 0U;
    }
    else
    {
        PORTF->DATA = (1 << 2);
        PORTF->DATA = 0U;
    }
}

void Test_inValid_ReadChannelGroup(uint8 DATA)
{
    if (Dio_ReadChannelGroup(DATA))
    {
        PORTF->DATA = (1 << 3);
    }
    else
    {
        PORTF->DATA = (1 << 1);

    }
}
