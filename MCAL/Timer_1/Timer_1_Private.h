/*
 * Timer_1_Private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Mazin
 */

#ifndef MCAL_TIMER_1_TIMER_1_PRIVATE_H_
#define MCAL_TIMER_1_TIMER_1_PRIVATE_H_

#define TIMSK_REG	(*((volatile u8*)0x59))
#define TCCR1A_REG	(*((volatile u8*)0x4F))
#define TCCR1B_REG	(*((volatile u8*)0x4E))
//#define ICR1H_REG	(*((volatile u8*)0x47))
//#define ICR1L_REG	(*((volatile u8*)0x46))
#define ICR1_REG	(*((volatile u16*)0x46))

// TIMSK_REG Bits

#define TICIE1_BIT			5

#define CS12_BIT			2
#define CS11_BIT			1
#define CS10_BIT			0

// TCCR1A_REG Bits
// Compare Output Mode for Compare unit A
#define COM1A1_BIT			7
#define COM1A0_BIT			6
//Compare Output Mode for Compare unit B
#define COM1B1_BIT			5
#define COM1B0_BIT			4
// Force Output Compare for Compare unit A
#define FOC1A_BIT			3
//Force Output Compare for Compare unit B
#define FOC1B_BIT			2
//Waveform Generation Mode
#define WGM11_BIT			1
#define WGM10_BIT			0

// TCCR1B_REG Bits
// Input Capture Noise Canceler
#define ICNC1_BIT			7
 // TCCR1B_REG Input Capture Edge Select bit 0 ==> falling edge 	1==>rising edge
#define ICES1_BIT			6
//Waveform Generation Mode
#define WGM13_BIT			4
#define WGM12_BIT			3
//Clock Select
#define CS12_BIT			2
#define CS11_BIT			1
#define CS10_BIT			0




#endif /* MCAL_TIMER_1_TIMER_1_PRIVATE_H_ */
