/*
 * EXTI_program.c
 *
 *  Created on: Sep 1, 2025
 *      Author: MG
 */

//LIB: Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//MCAL: Microcontroller_upstruction_Layer
#include "EXTI_private.h"
#include "EXTI_interface.h"

static void (*_Int0_ISR_Func)(void) = NULL;
static void (*_Int1_ISR_Func)(void) = NULL;
static void (*_Int2_ISR_Func)(void) = NULL;



void EXTI_voidEnableDisable(INTNUM_e Copy_eIntNum,MODE_e Copy_eMode)
{
	switch (Copy_eIntNum) {
	case INT0:
		if(INT_ENABLED == Copy_eMode)
		{
			SET_BIT(GICR,GICR_INT0);
		}
		else
		{
			CLR_BIT(GICR,GICR_INT0);
		}
		break;
	case INT1:
		if(INT_ENABLED == Copy_eMode)
		{
			SET_BIT(GICR,GICR_INT1);
		}
		else
		{
			CLR_BIT(GICR,GICR_INT1);
		}
		break;
	case INT2:
		if(INT_ENABLED == Copy_eMode)
		{
			SET_BIT(GICR,GICR_INT2);
		}
		else
		{
			CLR_BIT(GICR,GICR_INT2);
		}
		break;

	default:
		break;
	}
}
void EXTI_voidSetSenseCtrl(INTNUM_e Copy_eIntNum,SENSTIVITY_e Copy_eSenseCtrl)
{
	switch (Copy_eIntNum) {
	case INT0:
		switch (Copy_eSenseCtrl) {

		case INT_LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case INT_ON_CHENGE://01
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INT_FALLING_EDGE://10
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case INT_RISING_EDGE://11
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		}
		break;
		case INT1:
			switch (Copy_eSenseCtrl) {

			case INT_LOW_LEVEL://00
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case INT_ON_CHENGE://01
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case INT_FALLING_EDGE://10
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			case INT_RISING_EDGE://11
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			}
			break;
			case INT2:
				switch (Copy_eSenseCtrl) {
				case INT_FALLING_EDGE:
					CLR_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				case INT_RISING_EDGE:
					SET_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				}
				break;

				default:
					break;
	}
}
void EXTI_voidSetCallBack(INTNUM_e Copy_eIntNum, void (*LocalPtrFunc)(void)	)
{
	switch (Copy_eIntNum) {
	case INT0:
		_Int0_ISR_Func = LocalPtrFunc;
		break;
	case INT1:
		_Int1_ISR_Func = LocalPtrFunc;
		break;
	case INT2:
		_Int2_ISR_Func = LocalPtrFunc;
		break;
	default:
		break;
	}
}



void __vector_1(void)  __attribute__((signal));  //ISR  INT 0
void __vector_1(void)
{

     _Int0_ISR_Func();
}


void __vector_2(void)  __attribute__((signal));  // ISR  INT 1
void __vector_2(void)
{

     _Int1_ISR_Func();
}


void __vector_3(void)  __attribute__((signal));  //ISR  INT 2
void __vector_3(void)
{

     _Int2_ISR_Func();
}
