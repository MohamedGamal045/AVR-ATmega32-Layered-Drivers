/*
 * EXTI_interface.h
 *
 *  Created on: Sep 1, 2025
 *      Author: MG
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	INT0=0,
	INT1,
	INT2
}INTNUM_e;

typedef enum
{
	INT_DISANLED=0,
	INT_ENABLED
}MODE_e;

typedef enum
{
	INT_FALLING_EDGE=0,
	INT_RISING_EDGE,
	INT_LOW_LEVEL,
	INT_ON_CHENGE
}SENSTIVITY_e;



void EXTI_voidEnableDisable(INTNUM_e Copy_eIntNum,MODE_e Copy_eMode);
void EXTI_voidSetSenseCtrl(INTNUM_e Copy_eIntNum,SENSTIVITY_e Copy_eSenseCtrl);
void EXTI_voidSetCallBack(INTNUM_e Copy_eIntNum, void (*LocalPtrFunc)(void)	);

#endif /* EXTI_INTERFACE_H_ */
