/*
 * ex10.c
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#include "ex10.h"
#define matrix_timer 2
#define matrix_dur 25

void movingLEDMatrix(int index, int frame){
	switch(index){
		case 0:
			enableCol(0);
			updateCol((0 + frame) % 8);

			break;
		case 1:
			enableCol(1);
			updateCol((1 + frame) % 8);

			break;
		case 2:
			enableCol(2);
			updateCol((2 + frame) % 8);

			break;
		case 3:
			enableCol(3);
			updateCol((3 + frame) % 8);

			break;
		case 4:
			enableCol(4);
			updateCol((4 + frame) % 8);

			break;
		case 5:
			enableCol(5);
			updateCol((5 + frame) % 8);

			break;
		case 6:
			enableCol(6);
			updateCol((6 + frame) % 8);

			break;
		case 7:
			enableCol(7);
			updateCol((7 + frame) % 8);

			break;
		default:
			break;
	}
}

void ex10_run(){
	static int idx = 0;
	static int frame = 0;
	static int first = 1;
	if (first){
		timerSet(matrix_timer, matrix_dur);

		first--;
	}

	if (timerFlag(matrix_timer)){
		timerSet(matrix_timer, matrix_dur);

		movingLEDMatrix(idx++, frame);
	}
	if (idx == 8) {
		idx = 0;
		frame++;
	}
	if (frame == 8){
		frame = 0;
	}

	ex7_run();
}
