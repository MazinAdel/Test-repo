/*
 * Dio_Program.c
 *
 *  Created on: Aug 8, 2022
 *      Author: Mazin
 */
/****************************************Includes****************************************/

#include"BitMath.h"
#include"StandardType.h"
#include"Dio_Interface.h"
#include"Dio_Private.h"

/****************************************Functions****************************************/
void M_Dio_pinMode(u8 copy_u8_value,u8 copy_u8_pinMode)
{
	u8 local_u8_PinNum = copy_u8_value % 10;
	u8 local_u8_PortNum = copy_u8_value / 10;
	switch(copy_u8_pinMode)
	{
	case INPUT:
		switch(local_u8_PortNum)
		{
		case PORTA_PINS : CLR_BIT(DDRA_REG,local_u8_PinNum); break;
		case PORTB_PINS : CLR_BIT(DDRB_REG,local_u8_PinNum); break;
		case PORTC_PINS : CLR_BIT(DDRC_REG,local_u8_PinNum); break;
		case PORTD_PINS : CLR_BIT(DDRD_REG,local_u8_PinNum); break;
		default:
			break;
		}
		break;
		case OUTPUT :
			switch(local_u8_PortNum)
			{
			case PORTA_PINS : SET_BIT(DDRA_REG,local_u8_PinNum); break;
			case PORTB_PINS : SET_BIT(DDRB_REG,local_u8_PinNum); break;
			case PORTC_PINS : SET_BIT(DDRC_REG,local_u8_PinNum); break;
			case PORTD_PINS : SET_BIT(DDRD_REG,local_u8_PinNum); break;
			default:
				break;
			}
			break;
			default :
				break;
	}

}

void M_Dio_pinWrite(u8 copy_u8_value,u8 copy_u8_pinMode)
{
	u8 local_u8_pinNum = copy_u8_value % 10;
	u8 local_u8_portNum = copy_u8_value / 10;
	switch(copy_u8_pinMode)
	{
	case LOW:
		switch(local_u8_portNum)
		{
		case PORTA_PINS : CLR_BIT(PORTA_REG,local_u8_pinNum); break;
		case PORTB_PINS : CLR_BIT(PORTB_REG,local_u8_pinNum); break;
		case PORTC_PINS : CLR_BIT(PORTC_REG,local_u8_pinNum); break;
		case PORTD_PINS : CLR_BIT(PORTD_REG,local_u8_pinNum); break;
		default:
			break;
		}
		break;
		case HIGH :
			switch(local_u8_portNum)
			{
			case PORTA_PINS : SET_BIT(PORTA_REG,local_u8_pinNum); break;
			case PORTB_PINS : SET_BIT(PORTB_REG,local_u8_pinNum); break;
			case PORTC_PINS : SET_BIT(PORTC_REG,local_u8_pinNum); break;
			case PORTD_PINS : SET_BIT(PORTD_REG,local_u8_pinNum); break;
			default:
				break;
			}
			break;
			default :
				break;
	}

}



u8 M_Dio_pinRead(u8 copy_u8_value)
{

	u8 local_u8_pinNum = copy_u8_value % 10;
	u8 local_u8_portNum = copy_u8_value / 10;
	u8 local_u8_Reading=0;
	switch(local_u8_portNum)
	{
	case PORTA_PINS : local_u8_Reading= GET_BIT(PINA_REG,local_u8_pinNum); break;
	case PORTB_PINS : local_u8_Reading =GET_BIT(PINB_REG,local_u8_pinNum); break;
	case PORTC_PINS :local_u8_Reading = GET_BIT(PINC_REG,local_u8_pinNum); break;
	case PORTD_PINS : local_u8_Reading=GET_BIT(PIND_REG,local_u8_pinNum); break;
	default:
		break;
	}
	return local_u8_Reading;

}




void M_Dio_PinTogl(u8 copy_u8_value)
{
	u8 local_u8_pinNum = copy_u8_value % 10;
	u8 local_u8_portNum = copy_u8_value / 10;

	switch(local_u8_portNum)
	{
	case PORTA_PINS : TOGL_BIT(PORTA_REG,local_u8_pinNum); break;
	case PORTB_PINS : TOGL_BIT(PORTB_REG,local_u8_pinNum); break;
	case PORTC_PINS : TOGL_BIT(PORTC_REG,local_u8_pinNum); break;
	case PORTD_PINS : TOGL_BIT(PORTD_REG,local_u8_pinNum); break;
	default:
		break;
	}

}




