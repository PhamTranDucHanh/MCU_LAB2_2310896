/*
 * ex7_8.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex7_8.h"
#define SEG_timer 0
#define ex7_timer 1
#define ex7_dur 1000
#define SEG_dur 250

void ex7_run(){
	static int hour = 15, minute = 59, second = 55;
	static int idx = 0, first = 1;

	if (first){
		timerSet(SEG_timer, SEG_dur);
		timerSet(ex7_timer, ex7_dur);
		updateClockBuffer(hour, minute);


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

		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	}
	if (timerFlag(SEG_timer)){
		timerSet(SEG_timer, SEG_dur);

		update7SEG(idx++);
		if (idx == 4) idx = 0;
	}
}
