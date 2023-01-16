/*
 * timer.h
 *
 *  Created on: 12 Oca 2023
 *      Author: metab
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f407xx.h"


typedef enum TIMNO{
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4,
	TIMER_5,
	TIMER_6,
	TIMER_7,
	TIMER_8
}TIMNO;

#define TIMER_STOP		0
#define TIMER_START		1

void timer_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned repeat);
void timer_start(TIMNO e_timer_no, int bstart_stop);
void timer_reset(TIMNO e_timer_no);
void timer_interrupt_config();

#endif /* TIMER_H_ */
