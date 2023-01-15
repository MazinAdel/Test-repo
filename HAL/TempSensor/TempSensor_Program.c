/*
 * TempSensor_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 * this driver is written for LM35 temperature sensor
 *
 */



#include "ADC_Interface.h"

void H_TempSensor_void_Init(void)
{
	M_ADC_void_Init();
}
u16 H_TempSensor_u16_Read(void)
{
	/*
	 * LM35 sensor gives 10.0 mV/˚C
	 *Rated for full −55˚ to +150˚C range
	 *V OUT=+1,500 mV at +150˚C
	 *     = +250 mV at +25˚C
	 *     = −550 mV at −55˚C
	 *
	 *	volt		ADC								Temperature
	 *	0			0
	 *	5			1023
	 *
	 *	v			x
	 *
	 *				x= (v * 1023) / 5
	 *
	 *	10mv		(10mv * 1023) / 5						1˚C
	 *				(1v   * 1023) / 500
	 *				1023 / 500
	 *
	 *
	 *				ADC Reading								T
	 *
	 *														T= (ADC Reading	*  500) / 1023
	 *
	 */
	u16 Local_u16_Temp = (M_ADC_u16_Read() * (u32)500)/1023;

	return Local_u16_Temp;

}

