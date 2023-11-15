/*
 * input_reading.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS
 */

#include "input_reading.h"

// Buffers
static GPIO_PinState buttonBuffer[NUM_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NUM_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NUM_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NUM_BUTTONS];

// Flag & counter
static uint16_t flagForButtonPress1s[NUM_BUTTONS];
static uint16_t counterForButtonPress1s[NUM_BUTTONS];

void button_reading(void)
{
	unsigned char i;
	for(i = 0; i < NUM_BUTTONS; i++)
	{
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];

		switch(i) {
		case 0:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
			break;
		case 1:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);
			break;
		case 2:
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);
			break;
		}

		if((debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
				&& (debounceButtonBuffer2[i] == debounceButtonBuffer3[i]))
		{
			buttonBuffer[i] = debounceButtonBuffer1[i];

			// Button is pressed
			if(buttonBuffer[i] == BUTTON_IS_PRESSED)
			{
				counterForButtonPress1s[i]++;

				// Button is pressed for >= 1s
				if(counterForButtonPress1s[i] >= DURATION_HOLD)
					flagForButtonPress1s[i] = 1;
			}
			else
			{
				// Button is released
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
	}
}

unsigned char is_button_pressed(unsigned char index) {
	if((index < 0) || (index >= NUM_BUTTONS))
		return 0xff;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);

}

unsigned char is_button_pressed_1s(unsigned char index) {
	if((index < 0) || (index >= NUM_BUTTONS))
		return 0xff;
	return (flagForButtonPress1s[index] == 1);
}

