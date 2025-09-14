/*
 * ex3_4.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex3_4.h"
#define led_timer 0
#define ex3_timer 1
#define led_dur 1000
#define ex3_dur 250

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
	switch (index){
		case 0:
			enableSEG(0);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			enableSEG(1);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			enableSEG(2);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			enableSEG(3);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}
void ex3_4_run(){
	static int idx = 0;
	static int first = 1;
	if (first){
		timerSet(ex3_timer, ex3_dur);
		timerSet(led_timer, led_dur);

		first--;
	}

	if (timerFlag(ex3_timer)){
		timerSet(ex3_timer, ex3_dur);
		update7SEG(idx++);
	}
	if (idx >= 4) idx = 0;

	if (timerFlag(led_timer)){
		timerSet(led_timer, led_dur);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	}
}
