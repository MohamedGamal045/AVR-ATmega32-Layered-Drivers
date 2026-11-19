/*
 * main.c
 *
 * Created on: Sep 12, 2025
 *      Author: MG
 */

//LIB: Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

//MCAL: Microcontroller_upstruction_Layer
#include "DIO_interface.h"
#include "SPI_Interface.h"

//HAL: Hardware_Upstruction_Layer
#include "LCD_Interface.h"

void main()

{
	//Code for MASTER
	DIO_SetPinDirection(_PORTB, PIN5, INPUT);   //MOSI for SLAVE
	DIO_SetPinDirection(_PORTB, PIN6, OUTPUT);  //MISO for SLAVE
	DIO_SetPinDirection(_PORTB, PIN7, INPUT);   //SCK for  SLAVE
	DIO_SetPinDirection(_PORTB,PIN4,INPUT);  //SS for   SLAVE
	SPI_Init();
	LCD_voidInit();
	u8 read;

	while (1)

	{

		read = SPI_Transieve(0);
		LCD_voidGotoXY(0, 0);
		LCD_voidSendString("MASTER DATA: ");
		LCD_voidSendCharacter(read);

	}

}

