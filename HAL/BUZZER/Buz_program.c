/*
 * Buz_program.c
 *
 *  Created on: Aug 9, 2022
 *      Author: Mazin
 */



/****************************************Includes****************************************/

#include "Buz_Interface.h"


/****************************************Functions****************************************/


void H_Buzzer_void_BuzInit(void)
{
	M_Dio_pinMode(BUZZER_PIN,OUTPUT);
}
void H_Buzzer_void_BuzOn(void)
{
	M_Dio_pinWrite(BUZZER_PIN,HIGH);
}
void H_Buzzer_void_BuzOff(void)
{
	M_Dio_pinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_void_BuzTogl(void)
{
	M_Dio_PinTogl(BUZZER_PIN);
}
void H_Buzzer_void_BuzOnce(void)
{
	M_Dio_pinWrite(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_Dio_pinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_void_BuzTwice(void)
{
	M_Dio_pinWrite(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_Dio_pinWrite(BUZZER_PIN,LOW);
	_delay_ms(BUZZER_TIME_OFF);
	M_Dio_pinWrite(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_Dio_pinWrite(BUZZER_PIN,LOW);
}
