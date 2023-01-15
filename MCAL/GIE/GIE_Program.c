/*
 * GIE_Program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Mazin
 */

#include "GIE_Interface.h"
#include "GIE_Private.h"




void M_GIE_void_Enable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}
void M_GIE_void_Disable(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
