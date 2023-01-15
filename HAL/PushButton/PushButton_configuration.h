/*
 * PushButton_configuration.h
 *
 *  Created on: Aug 11, 2022
 *      Author: Mazin
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_CONFIGURATION_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_CONFIGURATION_H_

/****************************************Macros***************************************************************/


#define		PUSH_BUTTON_1_PIN 						 PD2_PIN
#define		PUSH_BUTTON_2_PIN 						 PD3_PIN
#define		PUSH_BUTTON_3_PIN			   		     PD4_PIN
#define		PUSH_BUTTON_4_PIN 						 PD5_PIN
#define		PUSH_BUTTON_DEBOUNCING_TIME				 80//use _delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);

/****************************************Select_PUSH_BUTTON_MODE : ACTIVE_LOW ,ACTIVE_HIGH *********************/

#define 	PUSH_BUTTON_MODE						ACTIVE_LOW

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_CONFIGURATION_H_ */


