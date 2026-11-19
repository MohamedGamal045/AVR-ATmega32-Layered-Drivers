/*
 * GIE_program.c
 *
 *  Created on: Sep 1, 2025
 *      Author: MG
 */
 
//LIB: Libraries
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//MCAL: Microcontroller_upstruction_Layer
#include "GIE_private.h"
#include "GIE_interface.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
