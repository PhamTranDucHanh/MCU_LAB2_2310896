/*
 * ex5.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */


#include <ex5_6.h>

void updateClockBuffer(int hour, int minute){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}

void ex5_run(){
	int hour = 15, minute = 8, second = 50;

	while(1){
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
		HAL_Delay(1000);
	}
}
