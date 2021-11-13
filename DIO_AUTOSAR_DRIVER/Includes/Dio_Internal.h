/*
 * Dio_Internal.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-064
 */

#ifndef INCLUDES_DIO_INTERNAL_H_
#define INCLUDES_DIO_INTERNAL_H_





typedef  struct{
    uint8 Channel_Id;
    uint8 PinNum;
    uint8 Port;
    uint8 Direction;  /* input or output */
}Dio_channel;


typedef enum{
    PA=0,
    PB,
    PC,
    PD,
    PE,
    PF
}PORT_ID;




#endif /* INCLUDES_DIO_INTERNAL_H_ */
