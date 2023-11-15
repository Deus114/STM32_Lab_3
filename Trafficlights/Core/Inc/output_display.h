/*
 * output_display.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"

extern int durationRED;
extern int durationAMBER;
extern int durationGREEN;

void update_buffer(unsigned char num, unsigned char num1);
void display_7SEG(unsigned char num);
void update_7SEG(void);
void LED_RED_Blinking(void);

#endif /* INC_OUTPUT_DISPLAY_H_ */
