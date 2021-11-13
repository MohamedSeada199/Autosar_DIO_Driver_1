/*
 * Det.h
 *
 *  Created on: Mar 24, 2019
 *      Author: AVE-LAP-064
 */
#ifdef DET_ENABLE

#ifndef INCLUDES_DET_H_
#define INCLUDES_DET_H_

#define DIO_MODULE  120U
#define INSTANCE     0U


FUNC(void, DIO_MEM_CLASS) Det_ReportError(VAR(uint16,AUTOMATIC) ModuleId,VAR(uint8,AUTOMATIC) InstanceId,VAR(uint8,AUTOMATIC) ApiId,VAR(uint8,AUTOMATIC) ErrorId);




#endif /* INCLUDES_DET_H_ */

#endif
