/*
 * ex9.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex9.h"
#define sweep_timer 3
#define sweep_dur 250

uint16_t rows[8] = {ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin,
					ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin};
uint16_t enms[8] = {ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin,
					ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin};
int letterA[8][8]={
		{1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
};
void updateCol(int col){
	for (int i = 0; i < 8; i++){
		HAL_GPIO_WritePin(GPIOB, rows[i], letterA[i][col]);
	}
}
void enableCol(int col){
	for (int i = 0; i < 8; i++){
		if (i == col) HAL_GPIO_WritePin(GPIOA, enms[i], 0);
		else HAL_GPIO_WritePin(GPIOA, enms[i], 1);
	}
}
void updateLEDMatrix(int index){
	switch(index){
		case 0:
			enableCol(0);
			updateCol(0);

			break;
		case 1:
			enableCol(1);
			updateCol(1);

			break;
		case 2:
			enableCol(2);
			updateCol(2);

			break;
		case 3:
			enableCol(3);
			updateCol(3);

			index++;
			break;
		case 4:
			enableCol(4);
			updateCol(4);

			break;
		case 5:
			enableCol(5);
			updateCol(5);

			break;
		case 6:
			enableCol(6);
			updateCol(6);

			break;
		case 7:
			enableCol(7);
			updateCol(7);

			break;
		default:
			break;
	}

}

void ex9_run(){
	static int first = 1;
	static int idx = 0;
	if (first){
		timerSet(sweep_timer, sweep_dur);

		first--;
	}

	if (timerFlag(sweep_timer)){
		timerSet(sweep_timer, sweep_dur);

		updateLEDMatrix(idx++);
	}
	if (idx == 8) idx = 0;

}
