/*
 * Ssd_Program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Mazin
 */


#include "Ssd_Interface.h"
#include "Ssd_Private.h"


void Hal_Ssd_void_SsdInit(void)
{
	M_Dio_pinMode(SSD_LED_A,OUTPUT);
	M_Dio_pinMode(SSD_LED_B,OUTPUT);
	M_Dio_pinMode(SSD_LED_C,OUTPUT);
	M_Dio_pinMode(SSD_LED_D,OUTPUT);
	M_Dio_pinMode(SSD_LED_E,OUTPUT);
	M_Dio_pinMode(SSD_LED_F,OUTPUT);
	M_Dio_pinMode(SSD_LED_G,OUTPUT);

	M_Dio_pinMode(SSD_1_EN,OUTPUT);
	M_Dio_pinMode(SSD_2_EN,OUTPUT);


}
void Hal_Ssd_void_SsdDisplay(u8 copy_u8_Number)
{
	u8 Local_u8_Units = copy_u8_Number % 10;
	u8 Local_u8_Tens  = copy_u8_Number / 10;
	u16 Local_u16_Counter = 0;



	for(Local_u16_Counter = 0;Local_u16_Counter<400;Local_u16_Counter++)
	{
		Hal_Ssd_void_SsdDigitDisplay(Local_u8_Units);

		M_Dio_pinWrite(SSD_1_EN,HIGH);
		_delay_ms(1);
		M_Dio_pinWrite(SSD_1_EN,LOW);

		Hal_Ssd_void_SsdDigitDisplay(Local_u8_Tens);

		M_Dio_pinWrite(SSD_2_EN,HIGH);
		_delay_ms(1);
		M_Dio_pinWrite(SSD_2_EN,LOW);
	}


}


static void Hal_Ssd_void_SsdDigitDisplay(u8 copy_u8_Number)
{


	switch(copy_u8_Number)
	{
	case 0:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,HIGH);
		M_Dio_pinWrite(SSD_LED_F,HIGH);
		M_Dio_pinWrite(SSD_LED_G,LOW);
		break;

	case 1:
		M_Dio_pinWrite(SSD_LED_A,LOW);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,LOW);
		M_Dio_pinWrite(SSD_LED_E,LOW);
		M_Dio_pinWrite(SSD_LED_F,LOW);
		M_Dio_pinWrite(SSD_LED_G,LOW);
		break;
	case 2:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,LOW);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,HIGH);
		M_Dio_pinWrite(SSD_LED_F,LOW);
		M_Dio_pinWrite(SSD_LED_G,HIGH);

		break;
	case 3:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,LOW);
		M_Dio_pinWrite(SSD_LED_F,LOW);
		M_Dio_pinWrite(SSD_LED_G,HIGH);
		break;
	case 4:
		M_Dio_pinWrite(SSD_LED_A,LOW);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,LOW);
		M_Dio_pinWrite(SSD_LED_E,LOW);
		M_Dio_pinWrite(SSD_LED_F,HIGH);
		M_Dio_pinWrite(SSD_LED_G,HIGH);
		break;
	case 5:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,LOW);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,LOW);
		M_Dio_pinWrite(SSD_LED_F,HIGH);
		M_Dio_pinWrite(SSD_LED_G,HIGH);
		break;
	case 6:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,LOW);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,HIGH);
		M_Dio_pinWrite(SSD_LED_F,HIGH);
		M_Dio_pinWrite(SSD_LED_G,HIGH);
		break;
	case 7:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,LOW);
		M_Dio_pinWrite(SSD_LED_E,LOW);
		M_Dio_pinWrite(SSD_LED_F,LOW);
		M_Dio_pinWrite(SSD_LED_G,LOW);
		break;
	case 8:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,HIGH);
		M_Dio_pinWrite(SSD_LED_F,HIGH);
		M_Dio_pinWrite(SSD_LED_G,HIGH);
		break;
	case 9:
		M_Dio_pinWrite(SSD_LED_A,HIGH);
		M_Dio_pinWrite(SSD_LED_B,HIGH);
		M_Dio_pinWrite(SSD_LED_C,HIGH);
		M_Dio_pinWrite(SSD_LED_D,HIGH);
		M_Dio_pinWrite(SSD_LED_E,LOW);
		M_Dio_pinWrite(SSD_LED_F,HIGH);
		M_Dio_pinWrite(SSD_LED_G,HIGH);
		break;
	default:				break;
	}
}



void Hal_Ssd_void_SsdCountUp(u8 copy_u8_Number)
{
	u8 Local_u8_Counter = 0;

	for(Local_u8_Counter = 0;Local_u8_Counter<=copy_u8_Number;Local_u8_Counter++)
	{
		Hal_Ssd_void_SsdDisplay(Local_u8_Counter);

	}
}
void Hal_Ssd_void_SsdCountDown(u8 copy_u8_Number)
{
	s8 Local_s8_Counter;

	for(Local_s8_Counter=copy_u8_Number;Local_s8_Counter>=0;Local_s8_Counter--)
	{
		Hal_Ssd_void_SsdDisplay(Local_s8_Counter);
	}
}



