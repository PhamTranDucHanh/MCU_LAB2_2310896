/*
 * ex9.h
 *
 *  Created on: Sep 9, 2025
 *      Author: HANH
 */

#ifndef INC_EX9_H_
#define INC_EX9_H_

#include "main.h"
extern uint16_t rows[8];
extern uint16_t enms[8];
extern int letterA[8][8];

void updateCol(int col);
void enableCol(int col);
void updateLEDMatrix(int index);

void ex9_run();

#endif /* INC_EX9_H_ */
