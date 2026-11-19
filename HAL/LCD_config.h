/*
 * LCD_config.h
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*
 * VSS: GND => GROUND
 * VCC: +5V
 * VEE: Contrast adjust
 */

#define DATA_PORT		_PORTC //D0,D1,D2,D3,D4,D5,D6,D7
#define CONTROL_PORT	_PORTD //RS,RW,E

/*
 * DATA_PORT : D0,D1,D2,D3,D4,D5,D6,D7
 * D0: Data bus line 0 the Least Significant Bit (LSB)
 * D1: Data bus line 1
 * D2: Data bus line 2
 * D3: Data bus line 3
 * D4: Data bus line 4
 * D5: Data bus line 5
 * D6: Data bus line 6
 * D7: Data bus line 0 the Most Significant Bit (MSB)
 */

#define  RS_PIN 	PIN0 // In the Control PORT
#define  RW_PIN 	PIN1 // In the Control PORT
#define  E_PIN 	    PIN2 // In the Control PORT
/*
 * CONTROL_PORT : RS,RW,E
 * 
 * RS: Register_Select
 * RW: Read&Write ---> Read => 1 , Write => 0
 * E: Enable
 * 
 */




#endif /* LCD_CONFIG_H_ */
