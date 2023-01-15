/*
 * Buz_Interface.h
 *
 *  Created on: Aug 9, 2034
 *      Author: Mazin
 */

#ifndef HAL_BUZZER_BUZ_INTERFACE_H_
#define HAL_BUZZER_BUZ_INTERFACE_H_



/****************************************Includes****************************************/
#include"Buz_Configuration.h"
#include"Dio_Interface.h"

#define F_CPU 16000000UL
#include<util/delay.h>

/****************************************Prototypes****************************************/

void H_Buzzer_void_BuzInit(void);
void H_Buzzer_void_BuzOn(void);
void H_Buzzer_void_BuzOff(void);
void H_Buzzer_void_BuzTogl(void);
void H_Buzzer_void_BuzOnce(void);
void H_Buzzer_void_BuzTwice(void);

#endif /* HAL_BUZZER_BUZ_INTERFACE_H_ */
