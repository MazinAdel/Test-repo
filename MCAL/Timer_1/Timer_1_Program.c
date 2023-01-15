/*
 * Timer_1_Program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Mazin
 */

#include "StandardType.h"
#include "BitMath.h"
#include <avr/interrupt.h>
#include "Timer_1_Configurations.h"
#include "Timer_1_Interface.h"
#include "Timer_1_Private.h"

static void (*Timer_1_ICU_CallBack) (void)=NULL;

void M_Timer_1_void_Init(void)
{
	//step 1: config Timer in normal mode
	CLR_BIT(TCCR1A_REG,WGM11_BIT);
	CLR_BIT(TCCR1A_REG,WGM10_BIT);
	CLR_BIT(TCCR1B_REG,WGM13_BIT);
	CLR_BIT(TCCR1B_REG,WGM12_BIT);

	//step 2: config Timer prescaler

	SET_BIT(TCCR1B_REG,CS12_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	CLR_BIT(TCCR1B_REG,CS10_BIT);
}
void M_Timer_1_void_ICU_Init(void)
{
	// set trigger as rising edge
	M_Timer_1_void_ICU_SetTrigger(TIMER_1_ICU_RISING_TRIGG);
	//SET_BIT(TCCR1B_REG,ICES1_BIT);

}
void M_Timer_1_void_ICU_SetCallBack( void (*Copy_Ptr) (void) )
{
	Timer_1_ICU_CallBack = Copy_Ptr;

}
void M_Timer_1_void_ICU_IntEnable(void)
{
	SET_BIT(TIMSK_REG,TICIE1_BIT);
}
void M_Timer_1_void_ICU_IntDisable(void)
{
	CLR_BIT(TIMSK_REG,TICIE1_BIT);
}
u16 M_Timer_1_u16_ICU_InputRead(void)
{

	return ICR1_REG;
}


void M_Timer_1_void_ICU_SetTrigger(u8 Copy_u8_Trigger)
{
	switch(Copy_u8_Trigger)
	{
	case TIMER_1_ICU_RISING_TRIGG:
		SET_BIT(TCCR1B_REG,ICES1_BIT);
	break;
	case TIMER_1_ICU_FALLING_TRIGG:
		CLR_BIT(TCCR1B_REG,ICES1_BIT);
		break;
	default:	break;
	}
	/*
	// method 2
	TCCR1B_REG &= 0b01111111
	TCCR1B_REG |= Copy_u8_Trigger <<6
	*/
}


ISR(TIMER1_CAPT_vect)
{
	Timer_1_ICU_CallBack();
}





