/*
 * Led_Interface.h
 *
 *  Created on: Aug 9, 2034
 *      Author: Mazin
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_



/****************************************Macros****************************************/

#define BLU_LED_PIN			PC2_PIN
#define GRN_LED_PIN			PC1_PIN
#define RED_LED_PIN			PC0_PIN

#define RED_LED					0
#define GREEN_LED				1
#define BLUE_LED				2

#define LED_TIME_ON				100
#define LED_TIME_OFF			100

/****************************************Includes****************************************/
#include"Led_Configuration.h"
#include "Dio_Interface.h"
#define F_CPU 16000000UL
#include<util/delay.h>
/****************************************Prototypes****************************************/

void H_Led_void_LedInit(u8);
void H_Led_void_LedOn(u8);
void H_Led_void_LedOff(u8);
void H_Led_void_LedOff(u8 );
void H_Led_void_LedBlinkOnce(u8);
void H_Led_void_LedBlinkTwice(u8);
void H_Led_void_LedTogl(u8);

#endif /* HAL_LED_LED_INTERFACE_H_ */
