/*
  * Timer_0_Private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 */

#ifndef MCAL_TIMER_0_TIMER_0_PRIVATE_H_
#define MCAL_TIMER_0_TIMER_0_PRIVATE_H_

#include "StandardType.h"


#define OCR0_REG	(*((volatile u8*)0x5C))
#define TIMSK_REG	(*((volatile u8*)0x59))
#define TCCR0_REG	(*((volatile u8*)0x53))
#define TCNT0_REG	(*((volatile u8*)0x52))




// TCCR0_REG BITS
#define WGM00_BIT		6
#define WGM01_BIT		3
#define CS02_BIT		2
#define CS01_BIT		1
#define CS00_BIT		0

//TIMSK_REG BITS
#define	 TOIE0_BIT		0
#define  OCIE0_BIT		1

/*Timer Mode*/
#define  TIMER_0_NORMAL_MODE				0
#define  TIMER_0_PHASE_CORRECT_PWM_MODE		1
#define  TIMER_0_CTC_MODE					2
#define  TIMER_0_FASTPWM_MODE				3

/*Timer prescaler*/
#define TIMER_0_PRESCALER_1										1
#define TIMER_0_PRESCALER_8										2
#define TIMER_0_PRESCALER_64									3
#define TIMER_0_PRESCALER_256									4
#define TIMER_0_PRESCALER_1024									5
#define TIMER_0_PRESCALER_External_Clock_Source_Falling_Edge	6
#define TIMER_0_PRESCALER_External_Clock_Source_Rising_Edge		7


#define TIMER_0_OC0_MODE_MASK					0b11001111		//	TCCR0_REG		 COM01_BIT: CS00_BIT
#define TIMER_0_PRESCALER_MASK					0b11111000		//	TCCR0_REG		 CS02_BIT: CS00_BIT

#define TIMER_0_OC0_SHIFT					4
#define TIMER_0_PRESCALER_SHIFT				0


#define OC0_REG_MAX							255
#define TCNT0_REG_MaxValue					255
#define OVERFLOW_COUNT			    		256


/*Timer OC0 Mode not PWM */
#define   TIMER0_OC0_DISCONNECTED        0
#define   TIMER0_OC0_TOG                 1
#define   TIMER0_OC0_CLEAR               2
#define   TIMER0_OC0_SET                 3
/*Timer OC0 Mode  PWM */
#define   TIMER0_OC0_PWM_NON_INVERTING       0b00100000  // value (2)is inside mask
#define   TIMER0_OC0_PWM_INVERTING           0b00110000	 // value (3)is inside mask




#endif /* MCAL_TIMER_0_TIMER_0_PRIVATE_H_ */
