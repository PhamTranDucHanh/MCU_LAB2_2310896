/*
 * display7SEG.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "display7SEG.h"

uint16_t enablePins[4] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};
uint16_t segPins[7] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};

	  // Bảng mã cho từng số (0-9), 0 = sáng (common anode)
	  const uint8_t digitCode[10][7] = {
	    {0,0,0,0,0,0,1}, // 0
	    {1,0,0,1,1,1,1}, // 1
	    {0,0,1,0,0,1,0}, // 2
	    {0,0,0,0,1,1,0}, // 3
	    {1,0,0,1,1,0,0}, // 4
	    {0,1,0,0,1,0,0}, // 5
	    {0,1,0,0,0,0,0}, // 6
	    {0,0,0,1,1,1,1}, // 7
	    {0,0,0,0,0,0,0}, // 8
	    {0,0,0,0,1,0,0}  // 9
	  };

void display7SEG(int num) {
	if (num > 9 || num < 0 ) return;
	switch (num){
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}
void enableSEG(int idx)	{
	for (int i = 0; i < 4; i++){
		if(i == idx) HAL_GPIO_WritePin(GPIOA, enablePins[i], GPIO_PIN_RESET);
		else HAL_GPIO_WritePin(GPIOA, enablePins[i], GPIO_PIN_SET);
	}
}
