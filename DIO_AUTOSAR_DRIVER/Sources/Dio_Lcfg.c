/*
 * Dio_Lcfg.c
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-064
 */

/*************************** Include Libraries *******************************/
#include "Dio.h"
#include "Dio_MemMap.h"
#include "Dio_Internal.h"

/*Declaration of DIO CHANNEL PINS */
 Dio_channel Dio_Channel_ID[MAX_SIZE_OF_CHANNELS]= {{0,4,PF,INPUT},{1,2,PF,OUTPUT},{2,2,PC,INPUT}};
 Dio_ChannelGroupType   Dio_ChannelGroup[MAX_SIZE_OF_PORT]= {{16,4,PF},{16,0,PF}};



