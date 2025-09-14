/*
 * ex2.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex2.h"

typedef enum{
	INIT,
	EN0,
	EN1,
	EN2,
	EN3
} states;

states presentState2 = INIT;

#define led_timer 0
#define SEG_timer 1
#define led_dur 1000
#define SEG_dur 500

void ex2_run(){
	switch (presentState2){
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, DOT_Pin, GPIO_PIN_RESET);
			enableSEG(0);
			display7SEG(1);

			timerSet(SEG_timer, SEG_dur);
			timerSet(led_timer, led_dur);
			presentState2 = EN0;
			break;
		case EN0:
			enableSEG(0);
			display7SEG(1);

			if (timerFlag(SEG_timer)){
				timerSet(SEG_timer , SEG_dur);
				presentState2 = EN1;
			}
			break;
		case EN1:
			enableSEG(1);
			display7SEG(2);

			if (timerFlag(SEG_timer)){
				timerSet(SEG_timer, SEG_dur);
				presentState2 = EN2;
			}
			break;
		case EN2:
			enableSEG(2);
			display7SEG(3);

			if (timerFlag(SEG_timer)){
				timerSet(SEG_timer, SEG_dur);
				presentState2 = EN3;
			}
			break;
		case EN3:
			enableSEG(3);
			display7SEG(0);

			if (timerFlag(SEG_timer)){
				timerSet(SEG_timer, SEG_dur);
				presentState2 = EN0;
			}
			break;
		default:
			break;
	}
//	static int counter = 0;
//	enableSEG(3);
//	if (timerFlag(SEG_timer)){
//		timerSet(SEG_timer, SEG_dur);
//		if (counter == 10) counter = 0;
//		display7SEG(counter++);
//	}


	if (timerFlag(led_timer)){
		timerSet(led_timer, led_dur);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
	}
}
