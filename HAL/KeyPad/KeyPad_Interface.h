/*
 * KeyPad_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_



#include "StandardType.h"
#include "Dio_Interface.h"
#include "KeyPad_Configrations.h"


void H_KeyPad_void_KeyPadInit(void);
u8 H_KeyPad_void_KeyPadRead(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
