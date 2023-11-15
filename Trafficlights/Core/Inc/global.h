/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

// SOFTWARE_TIMER
#define BLINKY_CYCLE					500
#define TIMER_CYCLE						10

// VARIABLES
#define NUM_BUTTONS 					3
#define DURATION_HOLD					100
#define BUTTON_RELEASED					GPIO_PIN_SET
#define BUTTON_PRESSED					GPIO_PIN_RESET
#define NUM_LEDS						4

#endif /* INC_GLOBAL_H_ */
