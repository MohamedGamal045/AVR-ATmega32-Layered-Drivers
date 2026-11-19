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
#include "GIE_interface.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"


void ToggleLed(void)
{

   static u8 counter = 0;
   if(counter == 31)
   {
      DIO_TogglePin(_PORTB,PIN0);
      counter = 0;
   }
   counter++;


}


void main()
{

    DIO_SetPinDirection(_PORTB,PIN0,OUTPUT); //Define LED

    Timer0_Init(Normal_Mode,TIMER0_OVF,TIMER_CLK_1024);  //overflow time = 32.6 MS

    Timer0_SetCallBackOverFlow(ToggleLed);

    GIE_voidEnable();

	while(1)
	{



	}


}

