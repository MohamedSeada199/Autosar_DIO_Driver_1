/*
 * Det.c
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-064
 */
#include "Std_Types.h"
#include "Dio.h"
#include "Det.h"

FUNC(void, DIO_MEM_CLASS)
Det_ReportError(VAR(uint16,AUTOMATIC) ModuleId,VAR(uint8,AUTOMATIC) InstanceId,VAR(uint8,AUTOMATIC) ApiId,VAR(uint8,AUTOMATIC) ErrorId)
{

    switch(ApiId)
        {
            case Dio_WriteChannel_ID:   if(ErrorId == DIO_E_PARAM_INVALID_CHANNEL_ID) {     while(1){
                                                                                             /* Invalid ChannelId */
                                                                                                }
                                                                                       }
                                        else { }
                                        break;
            case Dio_WritePort_ID :  if( ErrorId == DIO_E_PARAM_INVALID_PORT_ID) {    while(1){
                                                                                            /* invalid PortId */
                                                                                            }
                                                                                  }
                                     else{ }
                                     break;
            case Dio_ReadChannelGroup_ID : if(ErrorId == DIO_E_PARAM_POINTER)   {      while(1) {

                                                                                            /*Null Pointer */
                                                                                                 }

                                                                                    }
                                      else{}
                                      break;
            default: break;
        }

}


