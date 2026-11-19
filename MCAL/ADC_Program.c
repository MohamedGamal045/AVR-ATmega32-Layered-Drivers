/*
 * ADC_Program.c
 *
 *  Created on: Sep 1, 2025
 *      Author: MG
 */

//Include LIBRARY FIRST
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//Include ADC FILES
#include "ADC_Private.h"
#include "ADC_Register.h"
#include "ADC_Interface.h"


static u16 *ISR_Read = 0;


void ADC_Init()
{
   //SET Reference Voltage for ADC
   CLR_BIT(ADMUX,ADMUX_REFS1);
   SET_BIT(ADMUX,ADMUX_REFS0);

   //SET Clock Division 128
   ADCSRA |= ADC_CLK_128;


   //Enable ADC
   SET_BIT(ADCSRA,ADCSRA_ADEN);

}


u16 ADC_reading_Poll(u8 ADC_Channel)
{
	 //Clear 5 Bits of Channel to be able to set new channel
     ADMUX &= ADC_CLEAR_Channel_Bits;
     //SET Channel
     ADMUX |= ADC_Channel;

     //Start Conversion
     SET_BIT(ADCSRA,ADCSRA_ADSC);

     //Check for flag
     while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
     //Clear Flag
     SET_BIT(ADCSRA,ADCSRA_ADIF);


     return ADCLH;

}


void ADC_reading_INT(u8 ADC_Channel, u16* reading)
{
     ADMUX &=  ADC_CLEAR_Channel_Bits;
     ADMUX |= ADC_Channel;

     ISR_Read = reading;

     SET_BIT(ADCSRA,ADCSRA_ADSC);

     SET_BIT(ADCSRA,ADCSRA_ADIE);

}



//ISR for ADC when complete conversion done
void __vector_16(void)   __attribute__((signal));
void __vector_16(void)
{

        *ISR_Read = ADCLH;

}

