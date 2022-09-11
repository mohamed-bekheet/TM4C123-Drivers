/*
 * RCC_interface.h
 *
 *  Created on: Aug 2, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_ /// same exact name

#include "STD_TYPES.h"

/*
* 	System Control :
 *	System control configures the overall operation of the device and provides information about the
 *  device. Configurable features include reset control, NMI operation, power control, clock control, and
 *  low-power modes
 *
 * */
//*****************************RESET CONTROL******************

void SC_SWSysReset(void);

void SC_SWCoreReset(void);

void SC_SWPeripheralReset(void);


//********************ClOCK CONTROL*****************

//********SC_CLKSRC***CLOCK SOURCES page 220 in datasheet
#define		MAINOSC		0X0	//Main oscillator
#define	  PIOSC			0X1	//Precision internal oscillator
#define		PIOSC_4		0X2	//divided by 4
#define	  LFIOSC		0X3	//Low-frequency internal oscillator
#define		HOSC			//FROM RCC2

/*
Init Clock source configurations
*/
void SC_Init(void);




//****************PEROPHERAL ENABLE******************

//GPIO
#define SC_GPIO_PORTA 0
#define SC_GPIO_PORTB 1
#define SC_GPIO_PORTC 2
#define SC_GPIO_PORTD 3
#define SC_GPIO_PORTE 4
#define SC_GPIO_PORTF 5

void SC_EnableGPIOPort(u8 ScGpioPort);


//GPIO BUS
#define SC_GPIO_APB	0
#define SC_GPIO_AHB	1		//Advanced High-Performance Bus

void SC_SelectGPIOBus(u8 ScGpioPort, u8 ScGpioBus);




#endif /* RCC_INTERFACE_H_ */
