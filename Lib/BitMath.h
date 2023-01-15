/*
 * BitMath.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Mazin
 */

#ifndef BITMATH_H_
#define BITMATH_H_

//BitMath
#define SET_BIT(reg,bit)	reg|=(1<<bit)
#define CLR_BIT(reg,bit)	reg&=~(1<<bit)
#define TOGL_BIT(reg,bit)	reg^=(1<<bit)
#define GET_BIT(reg,bit)    ((reg>>bit) & 1)


#define CLR_REG(reg)	    reg&=~(0b00000000)
#define SET_REG(reg,bit)	reg|=(0b11111111)
#endif /* BITMATH_H_ */
