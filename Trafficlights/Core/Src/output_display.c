/*
 * output_display.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ASUS
 */
#include "output_display.h"

unsigned char LED_Buffer[NUM_LEDS];
unsigned char index_led = 0;
int durationRED = 5;
int durationAMBER = 3;
int durationGREEN = 2;

void update_buffer(unsigned char num, unsigned char num1)
{
	LED_Buffer[0] = num / 10;
	LED_Buffer[1] = num % 10;
	LED_Buffer[2] = num1 / 10;
	LED_Buffer[3] = num1 % 10;
}

void display_7SEG(unsigned char num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
				|SEG4_Pin|SEG5_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
				|SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin|SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin
				|SEG4_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin
				|SEG3_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG5_Pin
				|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin
				|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin
				|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin
				|SEG6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
				|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
				|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		break;
	}
}



