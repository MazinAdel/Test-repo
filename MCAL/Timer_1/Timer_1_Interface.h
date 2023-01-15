/*
 * Timer_1_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Mazin
 */

#ifndef MCAL_TIMER_1_TIMER_1_INTERFACE_H_
#define MCAL_TIMER_1_TIMER_1_INTERFACE_H_



#define TIMER_1_ICU_RISING_TRIGG		1
#define TIMER_1_ICU_FALLING_TRIGG		0

void M_Timer_1_void_Init(void);
void M_Timer_1_void_ICU_Init(void);
void M_Timer_1_void_ICU_SetCallBack(void (*)(void));
void M_Timer_1_void_ICU_IntEnable(void);
void M_Timer_1_void_ICU_IntDisable(void);
u16 M_Timer_1_u16_ICU_InputRead(void);
void M_Timer_1_void_ICU_SetTrigger(u8 Copy_u8_Trigger);

#endif /* MCAL_TIMER_1_TIMER_1_INTERFACE_H_ */
