/*
 * ex7_8.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex7_8.h"
#define led_timer 		0
#define SEG_timer 		2
#define ex7_timer 		3
#define dot_timer		4
#define ex7_dur 		1000 //**
#define SEG_dur 		250
#define led_dur			1000

#define RATIO			5	//**
#define START_HOUR		23
#define START_MINUTE	59
#define START_SECOND	55

void ex7_run(){
	static int hour = START_HOUR, minute = START_MINUTE, second = START_SECOND;
	static int idx = 0, first = 1, first_second = 1;

	if (first){
		timerSet(SEG_timer, SEG_dur);
		timerSet(ex7_timer, ex7_dur);
		timerSet(led_timer, led_dur);
		updateClockBuffer(hour, minute);
		HAL_GPIO_WritePin(GPIOA, DOT_Pin , GPIO_PIN_SET);

		first--;
	}

	if (timerFlag(ex7_timer)){
		timerSet(ex7_timer, ex7_dur);

		second++;
		if(second >= 60){
			second = 0;
			minute++;
		}
		if(minute >= 60){
			minute = 0;
			hour++;
		}
		if(hour >= 24){
			hour = 0;
		}
		updateClockBuffer(hour, minute);

		HAL_GPIO_WritePin(GPIOA, DOT_Pin , GPIO_PIN_RESET);
		if (first_second) {
			timerSet(dot_timer, ex7_dur / RATIO);
			first_second--;
		}
	}

	if (timerFlag(dot_timer)){
		timerSet (dot_timer, ex7_dur);
		HAL_GPIO_WritePin(GPIOA, DOT_Pin , GPIO_PIN_SET);
	}

	if (timerFlag(SEG_timer)){
		timerSet(SEG_timer, SEG_dur);

		update7SEG(idx++);
		if (idx == 4) idx = 0;
	}

	if (timerFlag(led_timer)){
		timerSet(led_timer, led_dur);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	}
}
