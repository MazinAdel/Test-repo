/*
 * led_program.c
 *
 *  Created on: Aug 9, 2022
 *      Author: Mazin
 */

/****************************************Includes****************************************/

#include "Dio_Interface.h"

#define F_CPU 16000000UL
#include<util/delay.h>
#include"Led_Interface.h"
#include"Led_Private.h"


/****************************************Functions****************************************/

void H_Led_void_LedInit(u8 copy_u8_led)
{
	switch(copy_u8_led)
	{
	case RED_LED:		M_Dio_pinMode(RED_LED_PIN,OUTPUT);							break;
	case GREEN_LED:		M_Dio_pinMode(GRN_LED_PIN,OUTPUT);							break;
	case BLUE_LED:		M_Dio_pinMode(BLU_LED_PIN,OUTPUT);							break;
	default:																		break;


	}

}
void H_Led_void_LedOn(u8 copy_u8_led)
{
	switch(copy_u8_led)
		{
		case RED_LED:		M_Dio_pinWrite(RED_LED_PIN,HIGH);							break;
		case GREEN_LED:		M_Dio_pinWrite(GRN_LED_PIN,HIGH);							break;
		case BLUE_LED:		M_Dio_pinWrite(BLU_LED_PIN,HIGH);							break;
		default:																		break;


		}
}
void H_Led_void_LedOff(u8 copy_u8_led)
{
	switch(copy_u8_led)
			{
			case RED_LED:		M_Dio_pinWrite(RED_LED_PIN,LOW);							break;
			case GREEN_LED:		M_Dio_pinWrite(GRN_LED_PIN,LOW);							break;
			case BLUE_LED:		M_Dio_pinWrite(BLU_LED_PIN,LOW);							break;
			default:																		break;


			}
}
void H_Led_void_LedTogl(u8 copy_u8_led)
{
	switch(copy_u8_led)
				{
				case RED_LED:		M_Dio_PinTogl(RED_LED_PIN);							break;
				case GREEN_LED:		M_Dio_PinTogl(GRN_LED_PIN);							break;
				case BLUE_LED:		M_Dio_PinTogl(BLU_LED_PIN);							break;
				default:																break;

				}
}
void H_Led_void_LedBlinkOnce(u8 copy_u8_led)
{

	switch(copy_u8_led)
					{
					case RED_LED:
						M_Dio_pinWrite(RED_LED_PIN,HIGH);
						_delay_ms(LED_TIME_ON);
						M_Dio_pinWrite(RED_LED_PIN,LOW);
						break;
					case GREEN_LED:
						M_Dio_pinWrite(GRN_LED_PIN,HIGH);
						_delay_ms(LED_TIME_ON);
						M_Dio_pinWrite(GRN_LED_PIN,LOW);
						break;
					case BLUE_LED:
						M_Dio_pinWrite(BLU_LED_PIN,HIGH);
						_delay_ms(LED_TIME_ON);
						M_Dio_pinWrite(BLU_LED_PIN,LOW);
						break;
					default:
						break;

					}


}
void H_Led_void_LedBlinkTwice(u8 copy_u8_led)
{
	H_Led_void_LedBlinkOnce( copy_u8_led);
	_delay_ms(100);
	H_Led_void_LedBlinkOnce( copy_u8_led);
	_delay_ms(100);
}
