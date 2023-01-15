/*
 * Timer_0_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 */
#include "StandardType.h"
#include "BitMath.h"
#include "Timer_0_Private.h"
#include "Timer_0_Interface.h"
#include <avr/interrupt.h>
#include "Timer_0_Configurations.h"
#include <stdlib.h>  // line 223    abs

#define TIMER0_OVF_INT_ID          0
#define TIMER0_COMP_MATCH_INT_ID   1



u32 Timer_0_u32_NumOfOverFlows = 0;
u32 Timer_0_u32_NumOfComMatch  = 0;
u8  Timer_0_u8_rem_Ticks	   = 0;


void (*Timer_0_CallBack[2])(void)={NULL};



void M_Timer_0_void_Init(void)
{
	// step 1 : config timer mode

#if  TIMER_0_MODE == TIMER_0_NORMAL_MODE

	CLR_BIT(TCCR0_REG,WGM01_BIT);
	CLR_BIT(TCCR0_REG,WGM00_BIT);

    #if(TIMER_0_OC0_MODE>=0 && TIMER_0_OC0_MODE<=3)
		// step 1 : apply mask
		TCCR0_REG &=TIMER_0_OC0_MODE_MASK;
		// step 2 : insert value
		TCCR0_REG |=TIMER_0_OC0_MODE<<TIMER_0_OC0_SHIFT;

	#else
	#error	("wrong OC0 mode ")
	#endif

#elif	TIMER_0_MODE ==	TIMER_0_PHASE_CORRECT_PWM_MODE

	CLR_BIT(TCCR0_REG,WGM01_BIT);
	SET_BIT(TCCR0_REG,WGM00_BIT);
	#if(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING ||  TIMER_0_OC0_MODE == TIMER0_OC0_PWM_NON_INVERTING)
		// step 1 : apply mask
		TCCR0_REG &=TIMER_0_OC0_MODE_MASK;
		// step 2 : insert value
		TCCR0_REG |=TIMER_0_OC0_MODE;

	#else
	#error("wrong TIMER_0_MODE ")
	#endif

#elif	TIMER_0_MODE ==	TIMER_0_CTC_MODE

	SET_BIT(TCCR0_REG,WGM01_BIT);
	CLR_BIT(TCCR0_REG,WGM00_BIT);

	#if(TIMER_0_OC0_MODE>=0 && TIMER_0_OC0_MODE<=3)
		// step 1 : apply mask
		TCCR0_REG &=TIMER_0_OC0_MODE_MASK;
		// step 2 : insert value
		TCCR0_REG |=TIMER_0_OC0_MODE<<TIMER_0_OC0_SHIFT;

	#else
	#error	("wrong OC0 mode ")
	#endif

#elif	TIMER_0_MODE ==	TIMER_0_FASTPWM_MODE

	SET_BIT(TCCR0_REG,WGM01_BIT);
	SET_BIT(TCCR0_REG,WGM00_BIT);
	#if(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING ||  TIMER_0_OC0_MODE == TIMER0_OC0_PWM_NON_INVERTING)
		// step 1 : apply mask
		TCCR0_REG &=TIMER_0_OC0_MODE_MASK;
		// step 2 : insert value
		TCCR0_REG |=TIMER_0_OC0_MODE;

	#else
	#error("wrong TIMER_0_MODE ")
	#endif

#else
#error("wrong TIMER_0_MODE ")

#endif


}

void M_Timer_0_void_Start(void)
{

#if (TIMER_0_PRESCALER >=0 &&  TIMER_0_PRESCALER<=7)
	// step 1 : apply mask
	TCCR0_REG &= TIMER_0_PRESCALER_MASK;
	// step 2 : Insert value
	TCCR0_REG |= TIMER_0_PRESCALER<<TIMER_0_PRESCALER_SHIFT;
#else
#error("wrong prescaler")
#endif
	/*
#if TIMER_0_PRESCALER 		==		TIMER_0_PRESCALER_1024
	// to select the clock source clk/1024 (From prescaler)
	SET_BIT(TCCR0_REG,CS02_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	SET_BIT(TCCR0_REG,CS00_BIT);
#elif	 TIMER_0_PRESCALER 		==		TIMER_0_PRESCALER_256
	// to select the clock source clk/256 (From prescaler)
	SET_BIT(TCCR0_REG,CS02_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS00_BIT);

#elif	 TIMER_0_PRESCALER 		==		TIMER_0_PRESCALER_64
	// to select the clock source clk/64 (From prescaler)
	CLR_BIT(TCCR0_REG,CS02_BIT);
	SET_BIT(TCCR0_REG,CS01_BIT);
	SET_BIT(TCCR0_REG,CS00_BIT);

#elif	 TIMER_0_PRESCALER 		==		TIMER_0_PRESCALER_8
	// to select the clock source clk/8 (From prescaler)
	CLR_BIT(TCCR0_REG,CS02_BIT);
	SET_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS00_BIT);
#elif	 TIMER_0_PRESCALER 		==		TIMER_0_PRESCALER_8
	// to select the clock source clk/8 (From prescaler)
	CLR_BIT(TCCR0_REG,CS02_BIT);
	SET_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS00_BIT);
#elif	 TIMER_0_PRESCALER 		==		TIMER_0_PRESCALER_8
	// to select the clock source clk/8 (From prescaler)
	CLR_BIT(TCCR0_REG,CS02_BIT);
	SET_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS00_BIT);
#endif
	 */

}
void M_Timer_0_void_Stop(void)
{
	CLR_BIT(TCCR0_REG,CS02_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS00_BIT);
}


void M_Timer_0_void_EnableInt(u8 copy_u8_IntId)
{
	switch (copy_u8_IntId)
	{
	case TIMER0_OVF_INT_ID:
		//to enable timer 0 overflow interrupt
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case  TIMER0_COMP_MATCH_INT_ID:
		//to enable timer 0 output compare interrupt
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	default:   break;
	}
}
void M_Timer_0_void_DisableInt(u8 copy_u8_IntId)
{
	switch(copy_u8_IntId)
	{
	case TIMER0_OVF_INT_ID:
		CLR_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case  TIMER0_COMP_MATCH_INT_ID:
		CLR_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	default:   break;
	}

}

// after TCNT0_REG over flows  do ISR

void M_Timer_0_void_SetTime(u32 copy_u32_DesiredTime)
{


	u16 Local_u8_Arr_Prescaler[5]={1,8,64,256,1024};

	u32 Local_u32_TickTime = Local_u8_Arr_Prescaler[TIMER_0_PRESCALER-1] /F_OSC ;	// result in micro sec , F_OSC in Mega Hz
	u32 Local_u32_TotalTicks = (copy_u32_DesiredTime * 1000) / Local_u32_TickTime; // copy_u32_DesiredTime in ms *1000 ==> in micro sec

#if(TIMER_0_MODE == TIMER_0_NORMAL_MODE)

	Timer_0_u32_NumOfOverFlows = Local_u32_TotalTicks / (TCNT0_REG_MaxValue+1) ; // over flow happen when TCNT0_REG = TCNT0_REG_MaxValue+1 (overflow count)
	Timer_0_u8_rem_Ticks 	   = Local_u32_TotalTicks % (TCNT0_REG_MaxValue+1) ;
	if (Timer_0_u8_rem_Ticks !=0)
	{
		TCNT0_REG = 256 - Timer_0_u8_rem_Ticks;	// over flow happen when TCNT0_REG = 256
		Timer_0_u32_NumOfOverFlows++;
	}
#elif (TIMER_0_MODE == TIMER_0_CTC_MODE)
	u8 Local_u8_Counter = OC0_REG_MAX;
	while((Local_u32_TotalTicks % Local_u8_Counter))
	{
		Local_u8_Counter--;
	}
	Timer_0_u32_NumOfComMatch = Local_u32_TotalTicks / Local_u8_Counter;	// now Local_u8_Counter = OCR value
	OCR0_REG=Local_u8_Counter;

#endif

}

void M_Timer_0_void_SetFastPWM(u8 copy_u8_DutyCycle)
{
#if(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_NON_INVERTING)
	OCR0_REG = abs(((copy_u8_DutyCycle * 256)/100)-1);
#elif(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING)
	OCR0_REG = abs(255-((copy_u8_DutyCycle * 256)/100));
#else
#error ("wrong OC0 mode")
#endif

}
void M_Timer_0_void_SetPhaseCorrectPWM(u8 copy_u8_DutyCycle)
{
#if(TIMER_0_MODE == TIMER_0_PHASE_CORRECT_PWM_MODE)

	#if(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_NON_INVERTING)
		OCR0_REG = ((copy_u8_DutyCycle * 255)/100);
	#elif(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING)
		OCR0_REG = (255-((copy_u8_DutyCycle * 255)/100));
	#else
	#error ("wrong OC0 mode")
	#endif
#endif
}



void M_Timer_0_INT_void_SetCallback( void (*copy_Ptr) (void),u8 Int_Id )
{
	Timer_0_CallBack[Int_Id]=copy_Ptr;
}


ISR(TIMER0_OVF_vect)
{
	/* if(Timer_0_CallBack[TIMER0_OVF_INT_ID] == NULL)
	 * Timer_0_CallBack[TIMER0_OVF_INT_ID] == startup code address
	*/
	if(Timer_0_CallBack[TIMER0_OVF_INT_ID] != NULL)
	{
		static u32  Local_u32_Counter = 0;
		Local_u32_Counter++;

		if(Local_u32_Counter==Timer_0_u32_NumOfOverFlows)
		{
			Timer_0_CallBack[TIMER0_OVF_INT_ID]();
			Local_u32_Counter = 0;
			TCNT0_REG = OVERFLOW_COUNT - Timer_0_u8_rem_Ticks;// over flow happen when TCNT0_REG = TCNT0_REG_MaxValue + 1 ==> 255+1

		}
	}
	else{}

}

ISR(TIMER0_COMP_vect)
{
	if(Timer_0_CallBack[TIMER0_COMP_MATCH_INT_ID] != NULL)
	{
		static u32  Local_u32_Counter = 0;
		Local_u32_Counter++;

		if(Local_u32_Counter==Timer_0_u32_NumOfComMatch)
		{
			Timer_0_CallBack[TIMER0_COMP_MATCH_INT_ID]();
			Local_u32_Counter = 0;


		}
	}
	else{}
}
