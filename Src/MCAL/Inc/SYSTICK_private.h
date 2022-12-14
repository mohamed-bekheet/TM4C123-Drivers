/*
 * SYSTICK_private.h
 *
 *  Created on: Aug 10, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#include "STD_TYPES.h"
//Macros
#define SYSTICK_PERIODIC_INTERVAL 	0
#define SYSTICK_SINGLE_INTERVAL 	1


typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	//volatile u32 CALIB;
}SYSTICK_t;

#define SYSTICK_BASE_ADDRESS		0xE000E000

#define SYSTICK			((volatile SYSTICK_t *)(SYSTICK_BASE_ADDRESS+0x10))


#endif /* SYSTICK_PRIVATE_H_ */
