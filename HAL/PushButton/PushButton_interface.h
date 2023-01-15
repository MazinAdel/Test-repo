/*
 * PushButton_interface.h
 *
 *  Created on: Aug 11, 2022
 *      Author: Mazin
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

#if	PUSH_BUTTON_MODE	==	ACTIVE_LOW

#define  PRESSED   	0
#define  RELEASED   1



#elif	PUSH_BUTTON_MODE	==	ACTIVE_HIGH
#define  PRESSED  	1
#define  RELEASED  	0


#endif

#include"PushButton_configuration.h"
#include"PushButton_Private.h"
#include"StandardType.h"
/****************************************Macros****************************************/


#define 	PUSH_BUTTON_1 		1
#define 	PUSH_BUTTON_2 		2
#define 	PUSH_BUTTON_3 		3
#define 	PUSH_BUTTON_4 		4

/****************************************Prototypes************************************/


void H_PushBubtton_void_PushButtonInit(u8);
u8 H_PushBubtton_void_PushButtonRead(u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
