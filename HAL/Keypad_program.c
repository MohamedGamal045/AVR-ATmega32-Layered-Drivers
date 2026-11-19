/*
 * Keypad_program.c
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */
 
//LIB: Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

//MCAL: Microcontroller_upstruction_Layer
#include "DIO_interface.h"

//HAL: Hardware_Upstruction_Layer
#include "Keypad_config.h"
#include "Keypad_interface.h"

void Keypad_voidInit(void)
{
	///SET columns as output
	DIO_SetPinDirection(KPD_PORT,C0,PIN_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,C1,PIN_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,C2,PIN_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,C3,PIN_OUTPUT);
	///Columns init value as high
	DIO_SetPinValue(KPD_PORT,C0,PIN_HIGH);
	DIO_SetPinValue(KPD_PORT,C1,PIN_HIGH);
	DIO_SetPinValue(KPD_PORT,C2,PIN_HIGH);
	DIO_SetPinValue(KPD_PORT,C3,PIN_HIGH);

	///SET rows as input
	DIO_SetPinDirection(KPD_PORT,R0,PIN_INPUT);
	DIO_SetPinDirection(KPD_PORT,R1,PIN_INPUT);
	DIO_SetPinDirection(KPD_PORT,R2,PIN_INPUT);
	DIO_SetPinDirection(KPD_PORT,R3,PIN_INPUT);

	// input pull up
	DIO_SetPinValue(KPD_PORT,R0,PIN_HIGH);
	DIO_SetPinValue(KPD_PORT,R1,PIN_HIGH);
	DIO_SetPinValue(KPD_PORT,R2,PIN_HIGH);
	DIO_SetPinValue(KPD_PORT,R3,PIN_HIGH);
}

u8 Keypad_u8GetPressedKey(void)
{
	u8 Local_u8PinValue,Local_u8Button = NO_PRESSED_KEY;
	u8 KPD_ARR[MAX_ROW_NUM][MAX_COL_NUM]=KPD_VALUES;
	u8 Local_u8ColArr[MAX_COL_NUM]={C0,C1,C2,C3};
	u8 Local_u8RowArr[MAX_ROW_NUM]={R0,R1,R2,R3};

	for(u8 i=0;i<MAX_COL_NUM;i++)
	{
		DIO_SetPinValue(KPD_PORT,Local_u8ColArr[i],PIN_LOW);
		for(u8 j=0;j<MAX_ROW_NUM;j++)
		{
			Local_u8PinValue = DIO_GetPinValue(KPD_PORT,Local_u8RowArr[j]);
			if(Local_u8PinValue == PIN_LOW)
			{
				_delay_ms(50);
				Local_u8PinValue = DIO_GetPinValue(KPD_PORT,Local_u8RowArr[j]);
				if(Local_u8PinValue == PIN_LOW)
				{
					Local_u8Button = KPD_ARR[j][i];
					while(Local_u8PinValue == PIN_LOW)
					{
						Local_u8PinValue = DIO_GetPinValue(KPD_PORT,Local_u8RowArr[j]);
					}
					DIO_SetPinValue(KPD_PORT,Local_u8ColArr[i],PIN_HIGH);
					return Local_u8Button;
				}

			}
		}
		DIO_SetPinValue(KPD_PORT,Local_u8ColArr[i],PIN_HIGH);
	}
	return Local_u8Button;

}
