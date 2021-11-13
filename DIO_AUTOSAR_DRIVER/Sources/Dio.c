/*
 * Dio.c
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-064
 */

/**************************Include Libraries ***************************/
#include "Dio.h"
#include "Dio_MemMap.h"
#include "Det.h"
#include "BitWiseOperation.h"

extern Dio_channel Dio_Channel_ID[MAX_SIZE_OF_CHANNELS];
/*Satisfies_Dio_00001 : The Dio module shall not provide an interface for initialization of the hardware */
/*Satisfies_Dio_00002 : he PORT driver shall provide the reconfiguration of the port pin direction during runtime  (in main stub)*/
/*********************************************************************************************/
/*Service name   :  Dio_ReadChannel                                                          */
/*Service ID     :  0x00                                                                     */
/*Synch/Asynch   :  Synchronous                                                              */
/*Reentrancy     :  Reentrant                                                                */
/*Parameters(IN) :  ChannelId                                                                */
/*Parameters(OUT):  None                                                                     */
/*Return Value   :  Dio_LevelType (STD_HIGH) & (STD_LOW)                                     */
/*Decription     :  Returns the value of the specified DIO channel.                          */
/*********************************************************************************************/
/*Satisfies_Dio_00005*/
/*Satisfies_Dio_00015*/
/*Satisfies_Dio_00012 : The Dio module’s read functions shall work on input and output channels */

FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_ReadChannel(
VAR(Dio_ChannelType,AUTOMATIC) ChannelId)
{
    uint8 i = LOW;
    uint8 Return_Val = NEG;

    for (i = LOW; i < MAX_SIZE_OF_CHANNELS; i += 1U)
    {
        if (Dio_Channel_ID[i].Channel_Id == ChannelId)
        {
            switch (Dio_Channel_ID[i].Port)
            {
            case 'A':
                Return_Val = (uint8) Get_bit((uint8)PORTA->DATA,
                                             (uint8 )Dio_Channel_ID[i].PinNum);
                break;
            case 'B':
                Return_Val = (uint8) Get_bit((uint8)PORTB->DATA,
                                             (uint8 )Dio_Channel_ID[i].PinNum);
                break;
            case 'C':
                Return_Val = (uint8) Get_bit((uint8)PORTC->DATA,
                                             (uint8 )Dio_Channel_ID[i].PinNum);
                break;
            case 'D':
                Return_Val = (uint8) Get_bit((uint8)PORTD->DATA,
                                             (uint8 )Dio_Channel_ID[i].PinNum);
                break;
            case 'E':
                Return_Val = (uint8) Get_bit((uint8)PORTE->DATA,
                                             (uint8 )Dio_Channel_ID[i].PinNum);
                break;
            case 'F':
                Return_Val = (uint8) Get_bit((uint8)PORTF->DATA,
                                             (uint8 )Dio_Channel_ID[i].PinNum);
                break;
            default:
                break;
            }
        }
        if (NEG != Return_Val)
        {
            break;
        }
    }
    if (NEG == Return_Val)
    {
        #ifdef DET_ENABLE  /*if Det is enabled */
        /*Report Error Invalid Channel*/
        /* Satsifies_DIO_00175   with code 0x0A */
        Det_ReportError(DIO_MODULE, INSTANCE, Dio_ReadChannel_ID,
        DIO_E_PARAM_INVALID_CHANNEL_ID);
        #endif
        /*Satisfies_Dio_00118 :If development errors are enabled and an error occurred
           the Dio module’s read functions shall return with the value '0'. */
        return LOW;
    }
    /*Satisfies_Dio_00011 :he Dio_ReadChannel function shall read the level of a single DIO channel */
    else if (LOW == Return_Val)
    {
        return STD_LOW; /*Satisfies_Dio_00027*/
    }
    else
    {
        return STD_HIGH;/*Satisfies_Dio_00027*/
    }
}

/*********************************************************************************************/
/*Service name   : Dio_WriteChannel                                                          */
/*Service ID     : 0x01                                                                      */
/*Synch/Asynch   : Synchronous                                                               */
/*Reentrancy     : Reentrant                                                                 */
/*Parameters(IN) : ChannelId , Level                                                         */
/*Parameters(OUT): None                                                                      */
/*Return Value   : None                                                                      */
/*Description    : Service to set a level of a channel                                       */
/*********************************************************************************************/
/*Satisfies_Dio_00006 :The Dio_WriteChannel function shall set the level of a single DIO channel to STD_HIGH or STD_LOW. */
/*Satisfies_Dio_00064 :The Dio module’s write functions shall work on input and output channels */

FUNC(void,DIO_MEM_CLASS) Dio_WriteChannel(
        VAR(Dio_ChannelType,AUTOMATIC) ChannelId,
        VAR(Dio_LevelType,AUTOMATIC) Level)
{
    uint8 i = LOW;
    uint8 FLAG =LOW ;

    for (i = LOW; i < MAX_SIZE_OF_CHANNELS; i += 1U)
    {
        if (Dio_Channel_ID[i].Channel_Id == ChannelId)
        { /*Satisfies_Dio_00070 :If a Dio write function is used on an input channel,
             it shall have no effect on the physical output level. */
            if (Dio_Channel_ID[i].Direction == OUTPUT)
            {
                switch (Dio_Channel_ID[i].Port)
                {
                case PA:
                    if (STD_HIGH == Level)
                    {
                        Set_bit(PORTA->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else if (STD_LOW == Level)
                    {
                        Clear_bit(PORTA->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else
                    {
                        /* do something else */
                    }
                    break;
                case PB:
                    if (STD_HIGH == Level)
                    {
                        Set_bit(PORTB->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else if (STD_LOW == Level)
                    {
                        Clear_bit(PORTB->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    break;
                case PC:
                    if (STD_HIGH == Level)
                    {
                        Set_bit(PORTC->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else if (STD_LOW == Level)
                    {
                        Clear_bit(PORTC->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    break;
                case PD:
                    if (STD_HIGH == Level)
                    {
                        Set_bit(PORTD->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else if (STD_LOW == Level)
                    {
                        Clear_bit(PORTD->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else
                    {
                        /* do something else */
                    }
                    break;
                case PE:
                    if (STD_HIGH == Level)
                    {
                        Set_bit(PORTE->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else if (STD_LOW == Level)
                    {
                        Clear_bit(PORTE->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else
                    {
                        /* do something else */
                    }
                    break;
                case PF:
                    if (STD_HIGH == Level)
                    {
                        Set_bit(PORTF->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else if (STD_LOW == Level)
                    {
                        Clear_bit(PORTF->DATA, Dio_Channel_ID[i].PinNum);
                        FLAG = HIGH;
                    }
                    else
                    {
                        /* do something else */
                    }
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
           /* Do something */
        }

    }
           #ifdef DET_ENABLE /*if Det is enabled */
           /*Invalid Channel ID */
           /* Satsifies_DIO_00175   with code 0x0A */
           /* Satsifies_Dio_00119 : If development errors are enabled and an error occurred,
              the Dio module’s write functions shall NOT process the write command. */
        if(FLAG==LOW){
           Det_ReportError(DIO_MODULE, INSTANCE, Dio_WriteChannel_ID,
           DIO_E_PARAM_INVALID_CHANNEL_ID);
           }
          #endif


}

/*********************************************************************************************/
/*Service name   : Dio_ReadPort                                                              */
/*Service ID     : 0x02                                                                      */
/*Synch/Asynch   : Synchronous                                                               */
/*Reentrancy     : Reentrant                                                                 */
/*Parameters(IN) : PortId                                                                    */
/*Parameters(OUT): None                                                                      */
/*Return Value   : Dio_PortLevelType                                                         */
/*Description    : Returns the level of all channels of that port.                           */
/*********************************************************************************************/
/*Satisfies_Dio_00013 :The Dio_ReadPort function shall read the levels of all channels of one port */
FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadPort(
VAR(Dio_PortType,AUTOMATIC) PortId)
{ uint8 Port_Val = NEG;

    switch (PortId)
    {
    case PA:
        Port_Val = PORTA->DATA;
        break;
    case PB:
        Port_Val = PORTB->DATA;
        break;
    case PC:
        Port_Val = PORTC->DATA;
        break;
    case PD:
        Port_Val = PORTD->DATA;
        break;
    case PE:
        Port_Val = PORTE->DATA;
        break;
    case PF:
        Port_Val = PORTF->DATA;
        break;
    default:
        /*Satisfies_Dio_00177*/
        /* invalid Portid */
        Det_ReportError(DIO_MODULE, INSTANCE, Dio_ReadPort_ID,
                        DIO_E_PARAM_INVALID_PORT_ID);
        break;

    }

    return Port_Val;
}

/*********************************************************************************************/
/*Service name   : Dio_WritePort                                                             */
/*Service ID     : 0x03                                                                      */
/*Synch/Asynch   : Synchronous                                                               */
/*Reentrancy     : Reentrant                                                                 */
/*Parameters(IN) : PortId,Level                                                              */
/*Parameters(OUT): None                                                                      */
/*Return Value   : None                                                                      */
/*Description    : Service to set a value of the port.                                       */
/*********************************************************************************************/
FUNC(void,DIO_MEM_CLASS) Dio_WritePort(
        VAR(Dio_PortType,AUTOMATIC) PortId,
        VAR(Dio_PortLevelType,AUTOMATIC) Level)
{
    switch (PortId)
    {
    case PA:
        if (STD_HIGH == Level)
        {
            PORTA->DATA = 0xffU;
        }
        else
        {
            PORTA->DATA = 0x00U;
        }
    case PB:
        if (STD_HIGH == Level)
        {
            PORTB->DATA = 0xffU;
        }
        else
        {
            PORTB->DATA = 0x00U;
        }
    case PC:
        if (STD_HIGH == Level)
        {
            PORTC->DATA = 0xffU;
        }
        else
        {
            PORTC->DATA = 0x00U;
        }
    case PD:
        if (STD_HIGH == Level)
        {
            PORTD->DATA = 0xffU;
        }
        else
        {
            PORTD->DATA = 0x00U;
        }
    case PE:
        if (STD_HIGH == Level)
        {
            PORTE->DATA = 0xffU;
        }
        else
        {
            PORTE->DATA = 0x00U;
        }
    case PF:
        if (STD_HIGH == Level)
        {
            PORTF->DATA = 0xffU;
        }
        else
        {
            PORTF->DATA = 0x00U;
        }
    default: /*Satisfies_Dio_00177*/
        /* invalid Portid */
        Det_ReportError(DIO_MODULE, INSTANCE, Dio_WritePort_ID,
                        DIO_E_PARAM_INVALID_PORT_ID);
    }

}

/*********************************************************************************************/
/*Service name   : Dio_ReadChannelGroup                                                      */
/*Service ID     : 0x04                                                                      */
/*Synch/Asynch   : Synchronous                                                               */
/*Reentrancy     : Reentrant                                                                 */
/*Parameters(IN) : ChannelGroupIdPtr                                                         */
/*Parameters(OUT): None                                                                      */
/*Return Value   : Dio_PortLevelType                                                         */
/*Description    : This Service reads a subset of the adjoining bits of a port.              */
/*********************************************************************************************/
/*Satisfies_Dio_00014 :The Dio_ReadChannelGroup function shall read the levels of a DIO channel group ..*/
FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadChannelGroup(
P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr )
{   uint8 Channel_Group_Data = LOW;
    if(NULL ==ChannelGroupIdPtr )
    {
        /*Satisfies_Dio_00177*/
               /* NULL pointer error  */
               Det_ReportError(DIO_MODULE, INSTANCE, Dio_ReadChannelGroup_ID,
                               DIO_E_PARAM_POINTER);
    }
    else
    {
        switch (ChannelGroupIdPtr->port)

        {
            case PA : Channel_Group_Data = ( PORTA->DATA & ChannelGroupIdPtr->mask);
            Channel_Group_Data = Channel_Group_Data >> ChannelGroupIdPtr->offset;
            break;
            case PB : Channel_Group_Data = ( PORTB->DATA & ChannelGroupIdPtr->mask);
            Channel_Group_Data = Channel_Group_Data >> ChannelGroupIdPtr->offset;
            break;
            case PC : Channel_Group_Data = ( PORTC->DATA & ChannelGroupIdPtr->mask);
            Channel_Group_Data = Channel_Group_Data >> ChannelGroupIdPtr->offset;
            break;
            case PD : Channel_Group_Data = ( PORTD->DATA & ChannelGroupIdPtr->mask);
            Channel_Group_Data = Channel_Group_Data >> ChannelGroupIdPtr->offset;
            break;
            case PE : Channel_Group_Data = ( PORTE->DATA & ChannelGroupIdPtr->mask);
            Channel_Group_Data = Channel_Group_Data >> ChannelGroupIdPtr->offset;
            break;
            case PF : Channel_Group_Data = ( PORTF->DATA & ChannelGroupIdPtr->mask);
            Channel_Group_Data = Channel_Group_Data >> ChannelGroupIdPtr->offset;
            break;
        }
    }
    return Channel_Group_Data;

}

/************************************************************************************************/
/*Service name   : Dio_WriteChannelGroup                                                        */
/*Service ID     : 0x05                                                                         */
/*Synch/Asynch   : Synchronous                                                                  */
/*Reentrancy     : Reentrant                                                                    */
/*Parameters(IN) : ChannelGroupIdPtr,Level                                                      */
/*Parameters(OUT): None                                                                         */
/*Return Value   : None                                                                         */
/*Description    : Service to set a subset of the adjoining bits of a port to a specified level */
/************************************************************************************************/
FUNC(void,DIO_MEM_CLASS) Dio_WriteChannelGroup(
P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr, VAR(Dio_PortLevelType,AUTOMATIC) Level )
{
    if(NULL ==ChannelGroupIdPtr )
    {
        /*Satisfies_Dio_00177*/
        /* NULL pointer error  */
        Det_ReportError(DIO_MODULE, INSTANCE, Dio_WriteChannelGroup_ID,
        DIO_E_PARAM_POINTER);
    }
    else
    {
        switch(ChannelGroupIdPtr->port)
        {
            case PA:
            if(STD_HIGH == Level)
            {
                PORTA->DATA = PORTA->DATA | ((0xffU & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }
            else
            {
                PORTA->DATA = PORTA->DATA & ((0x00U & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }

            break;
            case PB: if(STD_HIGH == Level)
            {
                PORTB->DATA = PORTB->DATA | ((0xffU & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }
            else
            {
                PORTB->DATA = PORTB->DATA & ((0x00U & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }

            break;
            case PC: if(STD_HIGH == Level)
            {
                PORTC->DATA = PORTC->DATA | ((0xffU & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }
            else
            {
                PORTC->DATA = PORTC->DATA & ((0x00U & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }

            break;
            case PD: if(STD_HIGH == Level)
            {
                PORTD->DATA = PORTD->DATA | ((0xffU & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }
            else
            {
                PORTD->DATA = PORTD->DATA & ((0x00U & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }

            break;
            case PE: if(STD_HIGH == Level)
            {
                PORTE->DATA = PORTE->DATA | ((0xffU & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }
            else
            {
                PORTE->DATA = PORTE->DATA & ((0x00U & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }

            break;
            case PF: if(STD_HIGH == Level)
            {
                PORTF->DATA = PORTF->DATA | ((0xffU & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }
            else
            {
                PORTF->DATA = PORTF->DATA & ((0x00U & ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
            }

            break;
            default:
            /*Satisfies_Dio_00177*/
            /* invalid Portid */
            Det_ReportError(DIO_MODULE, INSTANCE,Dio_WriteChannelGroup_ID,
            DIO_E_PARAM_INVALID_PORT_ID);
        }

    }

}

/************************************************************************************************/
/*Service name   : Dio_GetVersionInfo                                                           */
/*Service ID     : 0x12                                                                         */
/*Synch/Asynch   : Synchronous                                                                  */
/*Reentrancy     : Reentrant                                                                    */
/*Parameters(IN) : None                                                                         */
/*Parameters(OUT): VersionInfo                                                                  */
/*Return Value   : None                                                                         */
/*Description    : Service to get the version information of this module.                       */
/************************************************************************************************/
FUNC(void,DIO_MEM_CLASS) Dio_GetVersionInfo(
P2VAR(Std_VersionInfoType,AUTOMATIC,PTR_FAR) VersionInfo )
{
    /* code is written here */
}

/************************************************************************************************/
/*Service name   : Dio_FlipChannel                                                              */
/*Service ID     : 0x11                                                                         */
/*Synch/Asynch   : Synchronous                                                                  */
/*Reentrancy     : Reentrant                                                                    */
/*Parameters(IN) : ChannelId                                                                    */
/*Parameters(OUT): Dio_LevelType                                                                */
/*Return Value   : None                                                                         */
/*Description    : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel   */
/*                 and return the level of the channel after flip.                              */
/************************************************************************************************/
FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_FlipChannel(
VAR(Dio_ChannelType,AUTOMATIC) ChannelId)
{
    uint8 i = LOW;
    uint8 Ret_Val = NEG;

    for (i = LOW; i < MAX_SIZE_OF_CHANNELS; i += 1U)
    {
        if (Dio_Channel_ID[i].Channel_Id == ChannelId)
        {
            switch (Dio_Channel_ID[i].Port)
            {
            case 'A':
                Toggle_bit(PORTA->DATA, Dio_Channel_ID[i].PinNum);
                Ret_Val = Get_bit(PORTA->DATA, Dio_Channel_ID[i].PinNum);
                break;
            case 'B':
                Toggle_bit(PORTB->DATA, Dio_Channel_ID[i].PinNum);
                Ret_Val = Get_bit(PORTB->DATA, Dio_Channel_ID[i].PinNum);
                break;
            case 'C':
                Toggle_bit(PORTC->DATA, Dio_Channel_ID[i].PinNum);
                Ret_Val = Get_bit(PORTC->DATA, Dio_Channel_ID[i].PinNum);
                break;
            case 'D':
                Toggle_bit(PORTD->DATA, Dio_Channel_ID[i].PinNum);
                Ret_Val = Get_bit(PORTD->DATA, Dio_Channel_ID[i].PinNum);
                break;
            case 'E':
                Toggle_bit(PORTE->DATA, Dio_Channel_ID[i].PinNum);
                Ret_Val = Get_bit(PORTE->DATA, Dio_Channel_ID[i].PinNum);
                break;
            case 'F':
                Toggle_bit(PORTF->DATA, Dio_Channel_ID[i].PinNum);
                Ret_Val = Get_bit(PORTF->DATA, Dio_Channel_ID[i].PinNum);
                break;
            default:
                break;
            }
        }

    }
    if(NEG == Ret_Val) {
        /*Satisfies_Dio_00177*/
                 /* invalid ChannelId */
                 Det_ReportError(DIO_MODULE, INSTANCE,Dio_FlipChannel_ID,
                                 DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    else {
        return Ret_Val;
    }
}
