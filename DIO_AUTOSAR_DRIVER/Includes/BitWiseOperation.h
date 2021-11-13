/*
 * BitWiseOperation.h
 *
 * Created: 2/13/2019 10:54:47 AM
 *  Author: AVE-LAP-064
 */ 


#ifndef BITWISEOPERATION_H_
#define BITWISEOPERATION_H_

#define Set_bit(Reg,bit)       (Reg|=(uint8)(1<<bit))
#define Clear_bit(Reg,bit)     (Reg&=(uint8)~(1<<bit))
#define Toggle_bit(Reg,bit)    (Reg^=(uint8)(1<<bit))
#define Get_bit(Reg,bit)       ((Reg & (uint8)(1<<bit)) ? (uint8)1 : (uint8)0 )
                         
#endif /* BITWISEOPERATION_H_ */

