/*
 * main.c
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "FreeRTOS.h"
#include "task.h"

void toggleled1(void *pvparameters);

void toggleled2(void *pvparameters);

void main() {

	DIO_SetPinDirection(_PORTA,PIN0,OUTPUT);
	DIO_SetPinDirection(_PORTA,PIN1,OUTPUT);

	xTaskCreate(toggleled1,"this toggle1",100,NULL,0,NULL);
	xTaskCreate(toggleled2,"this toggle2",100,NULL,1,NULL);

	vTaskStartScheduler();// any thing want to do >> do it before this line.


	while (1) {

	}

}

void toggleled1(void *pvparameters)
{
	while(1)
	{
		DIO_TogglePin(_PORTA,PIN0);
		vTaskDelay(1000);
	}
}

void toggleled2(void *pvparameters)
{
	while(1)
	{
		DIO_TogglePin(_PORTA,PIN1);
		vTaskDelay(3000);
	}
}
