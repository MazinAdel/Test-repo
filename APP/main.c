/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Mazin
 */

#define F_CPU 16000000UL
#include<util/delay.h>
#include"StandardType.h"
#include "BitMath.h"
#include"Dio_Interface.h"
#include"Led_Interface.h"
#include"Buz_Interface.h"
#include"Lcd_interface.h"
#include"PushButton_interface.h"
#include"Ext_Int_Interface.h"
#include"Ssd_Interface.h"
#include "ADC_Interface.h"
#include "TempSensor_Interface.h"
#include "GIE_Interface.h"
#include "KeyPad_Interface.h"
#include "Timer_1_Interface.h"
#include "Timer_0_Interface.h"

/*****************************prototypes**********************************/

void A_Ext_Int_Excution(void);

void A_ICU_HW(void);

/*****************************main**********************************/


#if 	0
int main()

{

	H_Lcd_void_LcdInit();

	H_Lcd_void_LcdSendString("HELLO Ahmed");
	H_Lcd_void_LcdGoTo(1,0);
	H_Lcd_void_LcdSendString("HELLO MAzin");
	H_Lcd_void_LcdGoTo(1,20);
	H_Lcd_void_LcdSendString("HELLO MAzin");


	while (1)
	{

	}

	return 0;
}

#endif

#if 	0

//check ICU in Timer 1
void A_ICU_HW(void);

static u16 Reading1 = 0;
static u16 Reading2 = 0;
static u16 Reading3 = 0;
static volatile u8 StateCounter = 0;

int main()
{

	u32 PeriodTicks=0;
	u32 ONTicks=0;
	u8 DutyCycle=0;

	// Timer 1 initialization
	// step 1 : intit Timer 1 mode and prescaler
	M_Timer_1_void_Init();
	// step 2 : intit ICU
	M_Timer_1_void_ICU_Init();
	// step 3 : set callback fun
	M_Timer_1_void_ICU_SetCallBack(A_ICU_HW);
	// step 4 : enable ICU interrupt
	M_Timer_1_void_ICU_IntEnable();
	// step 5 : config ICP1 pin as input
	M_Dio_pinMode(PD6_PIN,INPUT);

	// Timer0 initialization
	// step 1 : intit Timer 0 mode as FastPWM
	M_Timer_0_void_Init();
	// step 2 : set Duty cycle as 70 %
	M_Timer_0_void_SetFastPWM(50);
	// step 3 : config OC01 pin as output
	M_Dio_pinMode(PB3_PIN,OUTPUT);
	// step 4 : Start timer
	M_Timer_0_void_Start();

	H_Lcd_void_LcdInit();

	M_GIE_void_Enable();
	//sei();


	while(StateCounter !=3);// busy waiting
	PeriodTicks = Reading2 - Reading1;
	ONTicks = Reading3 - Reading2;
	DutyCycle = (u8)((ONTicks * 100 )/ PeriodTicks);

	while(1)
	{

		H_Lcd_void_LcdSendString("PeriodTicks = ");
		H_Lcd_void_LcdGoTo(1,0);
		H_Lcd_void_LcdSendNumber(PeriodTicks);
		_delay_ms(1000);
		H_Lcd_void_LcdClear();

		H_Lcd_void_LcdSendString("ONTicks = ");
		H_Lcd_void_LcdGoTo(1,0);
		H_Lcd_void_LcdSendNumber(ONTicks);
		_delay_ms(1000);
		H_Lcd_void_LcdClear();

		H_Lcd_void_LcdSendString("DutyCycle = ");
		H_Lcd_void_LcdGoTo(1,0);
		H_Lcd_void_LcdSendNumber(DutyCycle);
		_delay_ms(1000);
		H_Lcd_void_LcdClear();


	}

	return 0;
}

void A_ICU_HW(void)
{
	if(StateCounter == 0)
	{
		// to detect 1st rising edge
		Reading1= M_Timer_1_u16_ICU_InputRead();
	}
	else if(StateCounter == 1)
	{
		// program will enter her after 2nd trigger (2nd TIMER_1_ICU_RISING_TRIGG)  2nd ICU Interrupt
		M_Timer_1_void_ICU_SetTrigger(TIMER_1_ICU_FALLING_TRIGG);
		// to detect 2nd rising edge
		Reading2= M_Timer_1_u16_ICU_InputRead();

	}
	else if(StateCounter == 2)
	{
		// to detect 2nd rising edge
		Reading3= M_Timer_1_u16_ICU_InputRead();
		M_Timer_1_void_ICU_IntDisable();
	}
	StateCounter++;
}
#endif



#if 0

int main()

{

	H_Lcd_void_LcdInit();

	H_Lcd_void_LcdSendString("HELLO Ahmed Hamdy");

	while (1)
	{


	}
	/* select what will happen when interrupt occur*/
	//M_Ext_Int_void_SetCallBack(A_Ext_Int_Excution);
	/* initialize interrupt */
	//M_Ext_Int_void_Init(EXT_INT1);


	/*
	M_Timer_0_INT_void_SetCallback(A_Timer_0_IntExcution);
	M_GIE_void_Enable(); 	// global interrupt enable
	M_Timer_0_void_Init();
	M_Timer_0_void_SetTime(100);
	M_Timer_0_void_Start();
	 */
	//H_KeyPad_void_KeyPadInit();

	//H_PushBubtton_void_PushButtonInit(PUSH_BUTTON_1);


	// 7 segment initialization
	//Hal_Ssd_void_SsdInit();


	//H_TempSensor_void_Init();
	//H_Lcd_void_LcdInit();
	//H_Lcd_void_LcdClear();
/*PWM check*/
	/*
	M_Timer_0_void_Init();
	M_Dio_pinMode(PB3_PIN,OUTPUT);
	M_Dio_pinMode(PC5_PIN,INPUT);
	M_Timer_0_void_Start();
	while(1)
		{
		M_Timer_0_void_SetPhaseCorrectPWM(10);
			_delay_ms(500);
			M_Timer_0_void_SetPhaseCorrectPWM(20);
			_delay_ms(500);
			M_Timer_0_void_SetPhaseCorrectPWM(40);
			_delay_ms(500);
			M_Timer_0_void_SetPhaseCorrectPWM(80);
			_delay_ms(500);
			M_Timer_0_void_SetPhaseCorrectPWM(100);



		}

*/

/*
	H_Led_void_LedInit(GREEN_LED);
	M_Timer_0_void_Init();

	M_Timer_0_void_SetTime(200);
	//M_Timer_0_INT_void_SetCallback(A_Timer_0_IntExcution,TIMER_0_COMP_MATCH_INT_ID);
	M_Timer_0_INT_void_SetCallback(A_Timer_0_IntExcution,TIMER_0_OVF_INT_ID);
//	M_Timer_0_void_EnableInt(TIMER_0_COMP_MATCH_INT_ID);
	M_Timer_0_void_EnableInt(TIMER_0_OVF_INT_ID);
	M_GIE_void_Enable();
	M_Timer_0_void_Start();
	while(1)
	{



	}
*/



	return 0;
}
#endif



// Timer 0 Start

void A_Timer_0_IntExcution(void);
int main()

{


	M_Timer_0_INT_void_SetCallback(A_Timer_0_IntExcution,TIMER_0_OVF_INT_ID);
	M_GIE_void_Enable(); 	// global interrupt enable
	M_Timer_0_void_Init();
	H_Led_void_LedInit(GREEN_LED);
	M_Timer_0_void_SetTime(1000);
	M_Timer_0_void_Start();

	while (1)
	{


	}


	return 0;
}

void A_Timer_0_IntExcution(void)
{
	H_Led_void_LedTogl(GREEN_LED);

}


// Timer 0 END
void A_Ext_Int_Excution(void)
{
	H_Led_void_LedTogl(GREEN_LED);


}





