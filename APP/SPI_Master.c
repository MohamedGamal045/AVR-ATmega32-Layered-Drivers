/*
 * main.c
 *
 * Created on: Sep 12, 2025
 * Author: MG
 */

//LIB: Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

//MCAL: Microcontroller_upstruction_Layer
#include "DIO_interface.h"
#include "SPI_Interface.h"

void main()
{
	//Code for MASTER
	DIO_SetPinDirection(_PORTB,PIN5,OUTPUT);   //MOSI for Master
    DIO_SetPinDirection(_PORTB,PIN6,INPUT);    //MISO for Master
    DIO_SetPinDirection(_PORTB,PIN7,OUTPUT);   //SCK for  Master
    DIO_SetPinDirection(_PORTB,PIN4,OUTPUT);  //SS for   SLAVE
    DIO_SetPinValue(_PORTB,PIN4,LOW);
    SPI_Init();

	while(1)
	{
		SPI_Transieve('a');
		_delay_ms(1000);

		SPI_Transieve('b');
		_delay_ms(1000);

	}

}
