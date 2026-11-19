/*
 * USART_Interface.h
 *
 *  Created on: Sep 8, 2025
 *      Author: MG
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_Init(void);
void USART_Poll_voidSendData(u8 Data);
u8 USART_Poll_u8RecieveData(void);


/*
 * void USART_SendString(const char* name);
 * void USART_INT_voidSendData(void);
 * void USART_INT_voidRecieveData(void);
 */

#endif /* USART_INTERFACE_H_ */
