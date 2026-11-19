/*
 * USART_Program.c
 *
 *  Created on: Sep 8, 2025
 *      Author: MG
 */

//LIB: Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//MCAL: Microcontroller_upstruction_Layer
#include"USART_register.h"
#include"USART_private.h"
#include"USART_config.h"
#include"USART_interface.h"


void USART_Init(void)
{
    u8 UCSRC_Value = 0b10000000;

    //Choose Data Frame Size ( 8 bit)
	SET_BIT(UCSRC_Value,UCSRC_UCSZ0);
	//0b10000010
	SET_BIT(UCSRC_Value,UCSRC_UCSZ1);
	//0b10000110
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	//Choose Parity Bit (Even Parity)
	CLR_BIT(UCSRC_Value,UCSRC_UPM0);
	//0b10000010
	SET_BIT(UCSRC_Value,UCSRC_UPM1);
	//0b10100010
	//Choose Stop Bits ( 1 Stop Bit)
	CLR_BIT(UCSRC_Value,UCSRC_USBS);
	//0b10100010

	//Choose Mode of Operation
	CLR_BIT(UCSRC_Value,UCSRC_UMSEL);

	// UCSRC_Value = 0b10100010

	//Must Be set Value one time not allow to set or clear each bit
    UCSRC =  UCSRC_Value;


    //Enable Receive
    SET_BIT(UCSRB,UCSRB_RXEN);

    //Enable Transmit
    SET_BIT(UCSRB,UCSRB_TXEN);

   // Baud Rate 9600
    UBRRL = 51;


}


void USART_Poll_voidSendData(u8 Data)
{
  while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
  UDR = Data;

}

u8 USART_Poll_u8RecieveData(void)
{
  while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
  return UDR;

}

