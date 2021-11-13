/*
 * Std_Types.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-064
 */

#ifndef INCLUDES_STD_TYPES_H_
#define INCLUDES_STD_TYPES_H_

/****************************Including Libraries***********************/
#include "Compiler.h"
#include "Platform_Types.h"

#define LOW         0U
#define HIGH        1U
/*Satisfies_Dio_00023*/
/*Satisfies_Std_00007*/
#define STD_LOW     0x00U    /* Physical state 0V */
#define STD_HIGH    0x01U    /* Physical state 5V or 3.3V */
/*Satisfies_Std_00015*/
/*This type shall be used to request the version of a BSW module */
typedef struct{
    uint16 vendorID;
    uint16 moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;

}Std_VersionInfoType;

/*Satisfies_Std_00006*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u
/*Satisfies_Std_00013*/
#define STD_ACTIVE 0x01u /* Logical state active */
#define STD_IDLE 0x00u /* Logical state idle */
/*Satisfies_Std_00010 */
#define STD_ON 0x01u
#define STD_OFF 0x00u



#endif /* INCLUDES_STD_TYPES_H_ */
