/*
 * Timer_Register.h
 *
 *  Created on: Sep 3, 2025
 *      Author: MG
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define Timer0_TCCR0          *((volatile u8*)(0x53))
#define Timer0_TCCR0_FOC      7
#define Timer0_TCCR0_WGM00    6
#define Timer0_TCCR0_COM01    5
#define Timer0_TCCR0_COM00    4
#define Timer0_TCCR0_WGM01    3
#define Timer0_TCCR0_CS02     2
#define Timer0_TCCR0_CS01     1
#define Timer0_TCCR0_CS00     0


#define Timer0_TCNT0           *((volatile u8*)(0x52))

#define Timer0_OCR0            *((volatile u8*)(0x5C))

#define TIMSK                  *((volatile u8*)(0x59))
#define TIMSK_TOIE0             0
#define TIMSK_OCIE0             1
#define TIMSK_TOIE1             2
#define TIMSK_OCIE1B            3
#define TIMSK_OCIE1A            4
#define TIMSK_TICIE1            5
#define TIMSK_TOIE2             6
#define TIMSk_OCIE2             7

#define TIFR                   *((volatile u8*)(0x58))
#define TIFR_TOV0              0
#define TIFR_OCF0              1
#define TIFR_TOV1              2
#define TIFR_OCF1B             3
#define TIFR_OCF1A             4
#define TIFR_ICF1              5
#define TIFR_TOV2              6
#define TIFR_OCF2              7





#endif /* TIMER_REGISTER_H_ */
