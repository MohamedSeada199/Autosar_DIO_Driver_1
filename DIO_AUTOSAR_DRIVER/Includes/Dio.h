/*
 * Dio.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-064
 */

#ifndef INCLUDES_DIO_H_
#define INCLUDES_DIO_H_

/***********************************Include Libraries ****************************/
#include "Dio_Cfg.h"
#include "Std_Types.h"
#include "Dio_Registers.h"
#include "Dio_Internal.h"

/**********************************Data Types************************************/

/*Satisfies_Dio_00182*/
typedef uint8 Dio_ChannelType;
/*Satisfies_Dio_00183*/
typedef uint8 Dio_PortType;
/*Satisfies_Dio_00184*/
typedef struct {
         uint8 mask;      /*This element mask which defines the positions of the channel group.*/
         uint8 offset;    /*This element shall be the position of the Channel Group on the port, counted from the LSB.*/
         Dio_PortType port; /*This shall be the port on which the Channel group is defined.*/
}Dio_ChannelGroupType;
/*Satisfies_Dio_00185*/
/*Takes only Two levels STD_LOW & STD_HIGH */
typedef uint8 Dio_LevelType;
/*Satisfies_Dio_00186*/
/*Takes the largest port size */
typedef uint8 Dio_PortLevelType;




/****************************************APIs Prototypes********************************/
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
/*Satisfies_Dio_00133*/
extern FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_ReadChannel(VAR(Dio_ChannelType,AUTOMATIC)ChannelId );

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
/*Satisfies_Dio_00134*/
extern FUNC(void,DIO_MEM_CLASS) Dio_WriteChannel( VAR(Dio_ChannelType,AUTOMATIC) ChannelId,VAR(Dio_LevelType,AUTOMATIC)Level );
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
/*Satisfies_Dio_00135*/
extern FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadPort( VAR(Dio_PortType,AUTOMATIC) PortId );
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
/*Satisfies_Dio_00136*/
extern FUNC(void,DIO_MEM_CLASS) Dio_WritePort( VAR(Dio_PortType,AUTOMATIC) PortId, VAR(Dio_PortLevelType,AUTOMATIC) Level );
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
/*Satisfies [SWS_Dio_00137]*/
extern FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadChannelGroup( P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr );
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
/*Satisfies [SWS_Dio_00138]*/
extern FUNC(void,DIO_MEM_CLASS) Dio_WriteChannelGroup( P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr, VAR(Dio_PortLevelType,AUTOMATIC) Level );
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
/*Satisfies [SWS_Dio_00139]*/
extern FUNC(void,DIO_MEM_CLASS) Dio_GetVersionInfo( P2VAR(Std_VersionInfoType,AUTOMATIC,PTR_FAR) VersionInfo );
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
/*Satisfies [SWS_Dio_00190]*/
extern FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_FlipChannel( VAR(Dio_ChannelType,AUTOMATIC) ChannelId );



/***************************************************APIs ID************************************************************/
enum API_ID{
    Dio_ReadChannel_ID=0U,
    Dio_WriteChannel_ID=1U,
    Dio_ReadPort_ID=2U,
    Dio_WritePort_ID=3U,
    Dio_ReadChannelGroup_ID=4U,
    Dio_WriteChannelGroup_ID=5U,
    Dio_FlipChannel_ID=11U
}API_IDs;

/**************************************************ERROR ID************************************************************/

#define DIO_E_PARAM_INVALID_CHANNEL_ID   0x0AU
#define DIO_E_PARAM_INVALID_PORT_ID      0x14U
#define DIO_E_PARAM_POINTER              0x20U
/**************************************************MACROS USED**********************************************************/
#define INPUT                            0U
#define OUTPUT                           1U
#define NEG                              10U
#define NULL                             0U
#define Initialized                      1U
#define Unintizalized                    0U


extern  Dio_ChannelGroupType   Dio_ChannelGroup[MAX_SIZE_OF_PORT];


#endif /* INCLUDES_DIO_H_ */
