/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "global.h"

extern int LED_flag;
extern int LED_7SEGS_flag;

void set_timer_LED(int duration);
void set_timer_7SEGS_LED(int duration);
void timer_run(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
