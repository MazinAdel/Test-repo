/*
 * Timer_0_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 */

#ifndef MCAL_TIMER_0_TIMER_0_INTERFACE_H_
#define MCAL_TIMER_0_TIMER_0_INTERFACE_H_
#include "StandardType.h"

#define TIMER_0_OVF_INT_ID				0
#define TIMER_0_COMP_MATCH_INT_ID		1

#define PWM_PIN			PB3_PIN

void M_Timer_0_void_Init(void);
void M_Timer_0_void_SetTime(u32);
void M_Timer_0_INT_void_SetCallback(void(*)(void),u8);
void M_Timer_0_void_Start(void);
void M_Timer_0_void_EnableInt(u8);
void M_Timer_0_void_DisableInt(u8);
void M_Timer_0_void_Stop(void);
void M_Timer_0_void_SetFastPWM(u8);
void M_Timer_0_void_SetPhaseCorrectPWM(u8);


#endif /* MCAL_TIMER_0_TIMER_0_INTERFACE_H_ */
