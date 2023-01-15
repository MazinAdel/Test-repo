/*
 * Ext_Int_Interface.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Mazin
 */

#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

/****************************************Includes****************************************/

#include "BitMath.h"
#include "StandardType.h"
#include <avr/interrupt.h>

/****************************************Macros****************************************/


#define EXT_INT0	0
#define EXT_INT1	1
#define EXT_INT2	2



void M_Ext_Int_void_Init(u8 copy_u8_Int);
// function takes pointer to function
void M_Ext_Int_void_SetCallBack(void (*) (void));


#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
