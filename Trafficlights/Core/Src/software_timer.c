/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS
 */

#include "software_timer.h"

// Flags & counters
int LED_counter = 0;
int LED_7SEG_counter = 0;

int LED_flag = 0;
int LED_7SEGS_flag = 0;

void set_timer_LED(int duration) {
	LED_counter = duration / TIMER_CYCLE;
	LED_flag = 0;
}

void set_timer_7SEGS_LED(int duration) {
	LED_7SEG_counter = duration / TIMER_CYCLE;
	LED_7SEGS_flag = 0;
}

void timer_run() {
	if(LED_counter > 0)
		LED_counter--;
	LED_flag = (LED_counter <= 0);

	if(LED_7SEG_counter > 0)
		LED_7SEG_counter--;
	LED_7SEGS_flag = (LED_7SEG_counter <= 0);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim->Instance == TIM2)
		timer_run();
}


