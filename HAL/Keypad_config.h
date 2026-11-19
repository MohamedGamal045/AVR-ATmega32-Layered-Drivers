/*
 * Keypad_config.h
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*Options
 *_PORTA
 *_PORTB
 *_PORTC
 *_PORTD
 */

#define KPD_PORT	_PORTC

/*
 * PIN0
 * PIN1
 * PIN2
 * PIN3
 * PIN4
 * PIN5
 * PIN6
 * PIN7
 */
 
//ROWs
#define R0			PIN0
#define R1			PIN1
#define R2			PIN2
#define R3			PIN3
//Columns
#define C0			PIN4
#define C1			PIN5
#define C2			PIN6
#define C3			PIN7

#define KPD_VALUES		{{1,2,3,4},\
						 {5,6,7,8},\
						 {9,10,11,12},\
						 {13,14,15,16}}

#define MAX_ROW_NUM			4
#define MAX_COL_NUM			4








#endif /* KEYPAD_CONFIG_H_ */
