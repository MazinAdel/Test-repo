/*
 * Lcd_interface.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Mazin
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/****************************************Includes****************************************/
#include"Lcd_configration.h"
#include"Dio_Interface.h"
#include"StandardType.h"
#define F_CPU 16000000UL
#include<util/delay.h>

/****************************************Prototypes****************************************/

void H_Lcd_void_LcdInit(void);
void H_Lcd_void_LcdSendCommand(u8);
void H_Lcd_void_LcdSendCharacter(u8);
void H_Lcd_void_LcdSendString(char*);
void H_Lcd_void_LcdSendNumber(s32 copy_s32_Number);
void H_Lcd_void_LcdClear(void);
void H_Lcd_void_LcdGoTo(u8 copy_u8_Row,u8 copy_u8_Col);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
