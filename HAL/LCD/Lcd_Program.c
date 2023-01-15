/*
 * Lcd_Program.c
 *
 *  Created on: Aug 9, 2022
 *      Author: Mazin
 */


/****************************************Includes****************************************/
#include"Led_Configuration.h"
#include"Lcd_interface.h"
#include"Lcd_private.h"
#include"Dio_Interface.h"
#include"StandardType.h"
#include"BitMath.h"





/****************************************Functions****************************************/



void H_Lcd_void_LcdInit(void)
{


#if			LCD_MODE	==	_8_BIT_MODE
	M_Dio_pinMode(LCD_D0_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D1_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D2_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D3_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D7_PIN,OUTPUT);

	_delay_ms(200);

	M_Dio_pinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_pinMode(LCD_EN_PIN,OUTPUT);

	H_Lcd_void_LcdSendCommand(LCD_8_BIT_MODE_COMMAND);

	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);

	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);

#elif			LCD_MODE  == _4_BIT_MODE


	M_Dio_pinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_pinMode(LCD_D7_PIN,OUTPUT);

	M_Dio_pinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_pinMode(LCD_EN_PIN,OUTPUT);


	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_3);

	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);

	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);


#endif


}
void H_Lcd_void_LcdSendCommand(u8 copy_u8_command)
{
	M_Dio_pinWrite(LCD_RS_PIN,LOW);		//send command

#if		LCD_MODE	==	_8_BIT_MODE


	/*********************send_8_bits_command_bit_by_bit*************/

	M_Dio_pinWrite(LCD_D0_PIN,copy_u8_command >> 0 & 0x01);
	M_Dio_pinWrite(LCD_D1_PIN,copy_u8_command >> 1 & 0x01);
	M_Dio_pinWrite(LCD_D2_PIN,copy_u8_command >> 2 & 0x01);
	M_Dio_pinWrite(LCD_D3_PIN,copy_u8_command >> 3 & 0x01);
	M_Dio_pinWrite(LCD_D4_PIN,copy_u8_command >> 4 & 0x01);
	M_Dio_pinWrite(LCD_D5_PIN,copy_u8_command >> 5 & 0x01);
	M_Dio_pinWrite(LCD_D6_PIN,copy_u8_command >> 6 & 0x01);
	M_Dio_pinWrite(LCD_D7_PIN,copy_u8_command >> 7 & 0x01);

	M_Dio_pinWrite(LCD_EN_PIN,HIGH);	//LCD_EN_PIN_HIGH_to_MAKE_LCD_MC_READ_FROM_REGISTERS
	_delay_ms(5);						//UNTILL_LCD_MC_READ_FROM_REGISTERS
	M_Dio_pinWrite(LCD_EN_PIN,LOW);		//LCD_EN_PIN_LOW_to_MAKE_LCD_MC_STOP_READING_FROM_REGISTERS


#elif			LCD_MODE  == _4_BIT_MODE



	M_Dio_pinWrite(LCD_D4_PIN,copy_u8_command >> 4 & 0x01);
	M_Dio_pinWrite(LCD_D5_PIN,copy_u8_command >> 5 & 0x01);
	M_Dio_pinWrite(LCD_D6_PIN,copy_u8_command >> 6 & 0x01);
	M_Dio_pinWrite(LCD_D7_PIN,copy_u8_command >> 7 & 0x01);

	M_Dio_pinWrite(LCD_EN_PIN,HIGH);	//LCD_EN_PIN_HIGH_to_MAKE_LCD_MC_READ_FROM_REGISTERS
	_delay_ms(5);						//UNTILL_LCD_MC_READ_FROM_REGISTERS
	M_Dio_pinWrite(LCD_EN_PIN,LOW);		//LCD_EN_PIN_LOW_to_MAKE_LCD_MC_STOP_READING_FROM_REGISTERS
	_delay_ms(5);
	copy_u8_command = copy_u8_command	<<	4;		//shift the 1st 4 bits to be the the last4
	M_Dio_pinWrite(LCD_D4_PIN,copy_u8_command >> 4 & 0x01);
	M_Dio_pinWrite(LCD_D5_PIN,copy_u8_command >> 5 & 0x01);
	M_Dio_pinWrite(LCD_D6_PIN,copy_u8_command >> 6 & 0x01);
	M_Dio_pinWrite(LCD_D7_PIN,copy_u8_command >> 7 & 0x01);

	M_Dio_pinWrite(LCD_EN_PIN,HIGH);	//LCD_EN_PIN_HIGH_to_MAKE_LCD_MC_READ_FROM_REGISTERS
	_delay_ms(5);						//UNTILL_LCD_MC_READ_FROM_REGISTERS
	M_Dio_pinWrite(LCD_EN_PIN,LOW);		//LCD_EN_PIN_LOW_to_MAKE_LCD_MC_STOP_READING_FROM_REGISTERS


#endif
}
void H_Lcd_void_LcdSendCharacter(u8 copy_u8_Data)
{
	M_Dio_pinWrite(LCD_RS_PIN,HIGH);		//send data

#if		LCD_MODE	==	_8_BIT_MODE


	/*********************send_8_bits_command_bit_by_bit*************/

	M_Dio_pinWrite(LCD_D0_PIN,copy_u8_Data >> 0 & 0x01);
	M_Dio_pinWrite(LCD_D1_PIN,copy_u8_Data >> 1 & 0x01);
	M_Dio_pinWrite(LCD_D2_PIN,copy_u8_Data >> 2 & 0x01);
	M_Dio_pinWrite(LCD_D3_PIN,copy_u8_Data >> 3 & 0x01);
	M_Dio_pinWrite(LCD_D4_PIN,copy_u8_Data >> 4 & 0x01);
	M_Dio_pinWrite(LCD_D5_PIN,copy_u8_Data >> 5 & 0x01);
	M_Dio_pinWrite(LCD_D6_PIN,copy_u8_Data >> 6 & 0x01);
	M_Dio_pinWrite(LCD_D7_PIN,copy_u8_Data >> 7 & 0x01);

	M_Dio_pinWrite(LCD_EN_PIN,HIGH);	//LCD_EN_PIN_HIGH_to_MAKE_LCD_MC_READ_FROM_REGISTERS
	_delay_ms(5);						//UNTILL_LCD_MC_READ_FROM_REGISTERS
	M_Dio_pinWrite(LCD_EN_PIN,LOW);		//LCD_EN_PIN_LOW_to_MAKE_LCD_MC_STOP_READING_FROM_REGISTERS


#elif			LCD_MODE  == _4_BIT_MODE


	//sending the last 4 bits first
	M_Dio_pinWrite(LCD_D4_PIN,copy_u8_Data >> 4 & 0x01);
	M_Dio_pinWrite(LCD_D5_PIN,copy_u8_Data >> 5 & 0x01);
	M_Dio_pinWrite(LCD_D6_PIN,copy_u8_Data >> 6 & 0x01);
	M_Dio_pinWrite(LCD_D7_PIN,copy_u8_Data >> 7 & 0x01);

	M_Dio_pinWrite(LCD_EN_PIN,HIGH);	//LCD_EN_PIN_HIGH_to_MAKE_LCD_MC_READ_FROM_REGISTERS
	_delay_ms(5);						//UNTILL_LCD_MC_READ_FROM_REGISTERS
	M_Dio_pinWrite(LCD_EN_PIN,LOW);		//LCD_EN_PIN_LOW_to_MAKE_LCD_MC_STOP_READING_FROM_REGISTERS
	_delay_ms(5);
	//then sending the first 4 bits
	copy_u8_Data = copy_u8_Data	<<	4;		//shift the 1st 4 bits to be the the last4
	M_Dio_pinWrite(LCD_D4_PIN,copy_u8_Data >> 4 & 0x01);
	M_Dio_pinWrite(LCD_D5_PIN,copy_u8_Data >> 5 & 0x01);
	M_Dio_pinWrite(LCD_D6_PIN,copy_u8_Data >> 6 & 0x01);
	M_Dio_pinWrite(LCD_D7_PIN,copy_u8_Data >> 7 & 0x01);

	M_Dio_pinWrite(LCD_EN_PIN,HIGH);	//LCD_EN_PIN_HIGH_to_MAKE_LCD_MC_READ_FROM_REGISTERS
	_delay_ms(5);						//UNTILL_LCD_MC_READ_FROM_REGISTERS
	M_Dio_pinWrite(LCD_EN_PIN,LOW);		//LCD_EN_PIN_LOW_to_MAKE_LCD_MC_STOP_READING_FROM_REGISTERS


#endif
}
void H_Lcd_void_LcdSendString(char *copy_u8_ptr)
{
	u8 local_u8_counter=0;
	while(copy_u8_ptr[local_u8_counter] != '\0')
	{
		H_Lcd_void_LcdSendCharacter(copy_u8_ptr[local_u8_counter]);
		local_u8_counter++;
	}
}
void H_Lcd_void_LcdSendNumber(s32 copy_s32_Number)
{
	u8 local_u8_Arr[20];
	s8 local_s8_counter=0;
	if(copy_s32_Number < 0)
	{
		copy_s32_Number = copy_s32_Number * (-1);
		H_Lcd_void_LcdSendCharacter('-');
	}
	do
	{
		local_u8_Arr[local_s8_counter] = copy_s32_Number % 10;
		copy_s32_Number = copy_s32_Number/10;
		local_s8_counter++;

	}while(copy_s32_Number!=0);
	local_s8_counter--;
	while(local_s8_counter>=0)
	{
		H_Lcd_void_LcdSendCharacter(local_u8_Arr[local_s8_counter]+48);
		local_s8_counter--;
	}

}

void H_Lcd_void_LcdClear(void)
{
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);

}

void H_Lcd_void_LcdGoTo(u8 copy_u8_Row,u8 copy_u8_Col)
{
		u8 Local_u8_Arr[2]={ROW_0,ROW_1};
		H_Lcd_void_LcdSendCommand(Local_u8_Arr[copy_u8_Row] + copy_u8_Col);


}



