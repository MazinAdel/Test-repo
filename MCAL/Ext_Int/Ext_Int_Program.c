/*
 * Ext_Int_Program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Mazin
 */

#include "Ext_Int_Private.h"
#include "Ext_Int_Interface.h"
#include "Ext_Int_Configuration.h"
#include "GIE_Interface.h"
#include "GIE_Configrations.h"

#define SWITCH_DEUNCING_TIME_IN_CLK_CYCLES	400000

void (*Ext_Int_Callback)(void);		// EXT_INT_Callback is pointer to function

void M_Ext_Int_void_Init(u8 copy_u8_Int)
{


	switch(copy_u8_Int)
	{
	case EXT_INT0:
		//to adjust sense control to falling edge on INT0
#if EXT_INT0_SENSE_CONTROL	==	FALLING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);
#elif	EXT_INT0_SENSE_CONTROL	==	RISING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);

#elif	EXT_INT0_SENSE_CONTROL	==	LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);


#elif	EXT_INT0_SENSE_CONTROL	==	LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);

#endif
		//to enable INT0 Interrupt
		SET_BIT(GICR_REG,INT0_BIT);

		break;

	case EXT_INT1:
		//to adjust sense control to falling edge on INT1
#if EXT_INT1_SENSE_CONTROL	==	FALLING_EDGE
		SET_BIT(MCUCR_REG,ISC11_BIT);
		CLR_BIT(MCUCR_REG,ISC10_BIT);
#elif	EXT_INT0_SENSE_CONTROL	==	RISING_EDGE
		SET_BIT(MCUCR_REG,ISC11_BIT);
		SET_BIT(MCUCR_REG,ISC10_BIT);

#elif	EXT_INT0_SENSE_CONTROL	==	LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC11_BIT);
		CLR_BIT(MCUCR_REG,ISC10_BIT);


#elif	EXT_INT0_SENSE_CONTROL	==	LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC11_BIT);
		SET_BIT(MCUCR_REG,ISC10_BIT);

#endif
		//to enable INT1 Interrupt
		SET_BIT(GICR_REG,INT1_BIT);

		break;

	case EXT_INT2:
		//to adjust sense control to falling edge on INT2
#if EXT_INT0_SENSE_CONTROL	==	FALLING_EDGE
		CLR_BIT(MCUCSR_REG,ISC2_BIT);
#elif	EXT_INT0_SENSE_CONTROL	==	RISING_EDGE
		SET_BIT(MCUCSR_REG,ISC2_BIT);
#endif
		//to enable INT2 Interrupt
		SET_BIT(GICR_REG,INT2_BIT);
		break;

	}



	M_GIE_void_Enable();	// to enable global INT

}

void M_Ext_Int_void_SetCallBack(void (*Copy_Ptr) (void))
{
	Ext_Int_Callback = Copy_Ptr;
}


ISR(INT1_vect)		// from Interrupt Vectors table page 44 ATMEGA32 data sheet
{
	Ext_Int_Callback();		// Ext_Int_Callback is pointer to function
	// Ext_Int_Callback(); means call the function which Ext_Int_Callback
	// points to
	u32 Local_u32_Counter = 0;
		do{
			Local_u32_Counter++;
		}while (Local_u32_Counter<SWITCH_DEUNCING_TIME_IN_CLK_CYCLES);


}

