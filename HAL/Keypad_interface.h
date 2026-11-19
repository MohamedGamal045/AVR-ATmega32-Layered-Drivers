/*
 * Keypad_interface.h
 *
 *  Created on: Sep 14, 2025
 *      Author: MG
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define NO_PRESSED_KEY			255


void Keypad_voidInit(void);
u8 Keypad_u8GetPressedKey(void);

#endif /* KEYPAD_INTERFACE_H_ */
