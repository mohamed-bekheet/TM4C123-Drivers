/*
 * RCC_program.c
 *
 *  Created on: Aug 3, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"


void SC_Init(void){
		
		WRITE_BITS(SC_RCC1 ,SC_XTAL    ,6);
		WRITE_BITS(SC_RCC1 ,SC_MOSCDIS ,0);
		
		WRITE_BITS(SC_RCC1 ,SC_OSCSRC  ,4);
		WRITE_BITS(SC_RCC1 ,SC_PLL_BYBASS ,11);
		WRITE_BITS(SC_RCC1 ,SC_PLL_PWRDN  ,13);
		WRITE_BITS(SC_RCC1 ,SC_PWMDIV ,17);
		WRITE_BITS(SC_RCC1 ,SC_SYSDIV ,23);
		
		WRITE_BITS(SC_RCC2 ,SC_USBPWRDN ,30);
		WRITE_BITS(SC_RCC2 ,SC_DIV400 ,14);		
		
}

void SC_EnableGPIOPort(u8 ScGpioPort){
		WRITE_BITS(SC_RCGC2 ,1 ,ScGpioPort);
		WRITE_BITS(SC_RCGCGPIO ,1 ,ScGpioPort);
  }
