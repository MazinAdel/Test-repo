/*
 * Lcd_configration.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Mazin
 */

#ifndef HAL_LCD_LCD_CONFIGRATION_H_
#define HAL_LCD_LCD_CONFIGRATION_H_
#include"Dio_Interface.h"


#define	LCD_MODE 		_4_BIT_MODE

/*******************select_MC_PINS**************************/

#define	LCD_D0_PIN	PA0_PIN
#define	LCD_D1_PIN	PA1_PIN
#define	LCD_D2_PIN	PA2_PIN
#define	LCD_D3_PIN	PA3_PIN
/*******************Kit_Connections_4_BIT_MODE**************************/

#define	LCD_D4_PIN	PA3_PIN
#define	LCD_D5_PIN	PA4_PIN
#define	LCD_D6_PIN	PA5_PIN
#define	LCD_D7_PIN	PA6_PIN


#define	LCD_RS_PIN	PA1_PIN
#define	LCD_EN_PIN	PA2_PIN

#endif /* HAL_LCD_LCD_CONFIGRATION_H_ */
