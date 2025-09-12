/*
 * ex1.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex1.h"

typedef enum{
	INIT,
	EN0,
	EN1,
} states;

states presentState1 = INIT;

#define led_timer 0
#define SEG_timer 1
#define led_dur 100
#define SEG_dur 50

void ex1_run(){
	switch (presentState1){
		case INIT:
			timerSet(SEG_timer, SEG_dur);
			timerSet(led_timer, led_dur);
			presentState1 = EN0;
			break;
		case EN0:
			enableSEG(0);
			display7SEG(1);

			if (timerFlag(SEG_timer)){
				timerSet(SEG_timer , SEG_dur);
				presentState1 = EN1;
			}
			break;
		case EN1:
			enableSEG(1);
			display7SEG(2);

			if (timerFlag(SEG_timer)){
				timerSet(SEG_timer, SEG_dur);
				presentState1 = EN0;
			}
			break;
		default:
			break;
	}

	if (timerFlag(led_timer)){
		timerSet(led_timer, led_dur);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	}
}
