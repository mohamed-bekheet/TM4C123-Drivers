/*
 * RCC_config.h
 *
 *  Created on: Aug 2, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
#include "RCC_interface.h"
//configure things that there is no need to change it at run time

#define SC_SYSCLK_FREQ  8000000  //HZ >>> MAX 80 MHZ



//*1-*****************CLOCK SOURCES*********

//1-main oscillator CONFIGURATION

#define SC_MOSCDIS		1 				//0>>ENABLED,1>>DISABLED //Main Oscillator Disable
//1-precision internal oscillator (16MHz) CONFIGURATION
#define SC_IOSDIS	
//2-Oscillator Source
#define SC_OSCSRC 	  PIOSC      // PIOSC //CHOOSE FRON CLOCK SOURCES IN INTERFACE FILE 
//2-USB AND PLL CONFIGURATION
#define SC_XTAL				0x0E			//(0x06~0x08)only for not using PLL,(0X09~0X1A) REPRESENTS CRYSTAL VALUES OF MAIN OSCILLATOR IN PAGE 256
//4-PLL SOURCE BYPASS (USE PLL OR NOT)
#define SC_PLL_BYBASS 	0				//(0~1) =1>The system clock is derived from the OSC source and divided by the divisor specified by SYSDIV.

#define SC_PLL_PWRDN 		1				//(0~1)PLL Power Down, The PLL is powered down. Care must be taken to ensure thatanother clock source is functioning and that the BYPASS bit isset before setting this bit.

/*Power-Down USB PLL
Value Description
0 The USB PLL operates normally.
1 The USB PLL is powered down.*/
#define SC_USBPWRDN 		1				//RCC2//

//3-PLL DIVISION CONFIGURATION
/*
Divide PLL as 400 MHz versus 200 MHz
This bit, along with the SYSDIV2LSB bit, allows additional frequency
choices.
Value Description
0  >> Use SYSDIV2 as is and apply to 200 MHz predivided PLL
output. See Table 5-5 on page 223 for programming guidelines.
0
1  >> Append the SYSDIV2LSB bit to the SYSDIV2 field to create a
7 bit divisor using the 400 MHz PLL output, see Table
5-6 on page 224.*/
#define SC_DIV400			0					//RCC2//


//5-SYSTEM DIVISION OF CLOCK SOURCE
/*
System Clock Divisor
Specifies which divisor is used to generate the system clock from either
the PLL output or the oscillator source (depending on how the BYPASS
bit in this register is configured). See Table 5-4 on page 223 for bit
encodings.
If the SYSDIV value is less than MINSYSDIV (see page 427), and the
PLL is being used, then the MINSYSDIV value is used as the divisor.
If the PLL is not being used, the SYSDIV value can be less than
MINSYSDIV.
**/
#define SC_SYSDIV  0xF


//6- USE SYSTEM DIVISION
/*
Value Description
0  >The system clock is used undivided.
The system clock divider is the source for the system clock. The
1	 >system clock divider is forced to be used when the PLL is
selected as the source.
If the USERCC2 bit in the RCC2 register is set, then the SYSDIV2
field in the RCC2 register is used as the system clock divider
rather than the SYSDIV field in this register
*/
#define SC_USESYSDIV 				0	  //Enable System Clock Divider
#define SC_USESYSDIV2				0


//6-USE PWM DIVISION
/*
Enable PWM Clock Divisor
Value Description
0 The system clock is the source for the PWM clock.
1 The PWM clock divider is the source for the PWM clock.
Note that when the PWM divisor is used, it is applied to the clock for
both PWM modules.

*/
#define SC_USEPWMDIV		0

/*
PWM Unit Clock Divisor
This field specifies the binary divisor used to predivide the system clock
down for use as the timing reference for the PWM module. The rising
edge of this clock is synchronous with the system clock.
Divisor Value
/2  		0x0
/4  		0x1
/8  		0x2
/16 		0x3
/32 		0x4
/64 		0x5
/64 		0x6
/64 (default) 0x7 	

*/
#define SC_PWMDIV		0x7

//7- CS CLOCK SOURCE


//GPIO PORT BUS (APB or AHB)
#define GPIO_PORTA_BUS 



#endif /* RCC_CONFIG_H_ */
