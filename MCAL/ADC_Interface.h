/*
 * ADC_Interface.h
 *
 *  Created on: Sep 1, 2025
 *      Author: MG
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


void ADC_Init();

u16 ADC_reading_Poll(u8 ADC_Channel);


void ADC_reading_INT(u8 ADC_Channel, u16* reading);



// --------------->task<-------------
/**
 *
 * void ADC_Disable()
 * void ADC_Enable();
 * void ADC_DisableInterrupt()
 * void ADC_EnableInterrupt()
 * void ADC_ChangeClock(u8 Clock);
 *
 */

#endif /* ADC_INTERFACE_H_ */
