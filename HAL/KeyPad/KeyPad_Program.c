/*
 * KeyPad_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 */

#include"KeyPad_Interface.h"

#define F_CPU 16000000UL
#include<util/delay.h>

void H_KeyPad_void_KeyPadInit(void)
{

	M_Dio_pinMode(KEYPAD_ROW_0_PIN,OUTPUT);
	M_Dio_pinMode(KEYPAD_ROW_1_PIN,OUTPUT);
	M_Dio_pinMode(KEYPAD_ROW_2_PIN,OUTPUT);
	M_Dio_pinMode(KEYPAD_ROW_3_PIN,OUTPUT);

	M_Dio_pinWrite(KEYPAD_ROW_0_PIN,HIGH);
	M_Dio_pinWrite(KEYPAD_ROW_1_PIN,HIGH);
	M_Dio_pinWrite(KEYPAD_ROW_2_PIN,HIGH);
	M_Dio_pinWrite(KEYPAD_ROW_3_PIN,HIGH);



	M_Dio_pinMode(KEYPAD_COL_0_PIN,INPUT);
	M_Dio_pinMode(KEYPAD_COL_1_PIN,INPUT);
	M_Dio_pinMode(KEYPAD_COL_2_PIN,INPUT);
	M_Dio_pinMode(KEYPAD_COL_3_PIN,INPUT);

}
u8 H_KeyPad_void_KeyPadRead(void)
{
	u8 local_u8_Reading = 0;
	u8 local_u8_Col = 0;
	u8 local_u8_Row = 0;
	u8 local_u8_Arr[4][4]={
			{ '1' , '2' , '3' , 'A' },
			{ '4' , '5' , '6' , 'B' },
			{ '7' , '8' , '9' , 'C' },
			{ '*' , '0' , '#' , 'D' }
						  };

	for(local_u8_Row =KEYPAD_ROW_0_PIN;local_u8_Row <=KEYPAD_ROW_3_PIN;local_u8_Row ++)
	{
		M_Dio_pinWrite(local_u8_Row,LOW);

		for(local_u8_Col = KEYPAD_COL_0_PIN;local_u8_Col<=KEYPAD_COL_3_PIN;local_u8_Col++)	// in case the col pins are connected is sequence
		{

			if(M_Dio_pinRead(local_u8_Col) == 0)	// debouncing of switch
			{
				_delay_ms(100);
				if(M_Dio_pinRead(local_u8_Col) == 0)
				{
					local_u8_Reading = local_u8_Arr[local_u8_Row - KEYPAD_ROW_0_PIN][local_u8_Col - KEYPAD_COL_0_PIN];
					while(M_Dio_pinRead(local_u8_Col) == 0);	// while pressed

				}
			}

		}

		M_Dio_pinWrite(local_u8_Row,HIGH);

	}
	return local_u8_Reading;
}








