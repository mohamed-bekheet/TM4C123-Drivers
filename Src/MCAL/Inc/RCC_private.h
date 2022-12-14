/*
 * RCC_private.h
 *
 *  Created on: Aug 3, 2022
 *      Author: Omar Gamal
 */

#ifndef SC_PRIVATE_H_
#define SC_PRIVATE_H_

//System Control Register Descriptions
#define SC_BASE_ADDRESS	0x400FE000

#define SC_RCC1				*((volatile u32*) (SC_BASE_ADDRESS+0x060))  // This register configure the system clock and oscillators
#define SC_GPIOHBCT		*((volatile u32*) (SC_BASE_ADDRESS+0x06C))  // GPIO High-Performance Bus Control (GPIOHBCTL), This register controls which internal bus is used to access each GPIO port 
#define SC_RCC2			  *((volatile u32*) (SC_BASE_ADDRESS+0x070))


#define SC_SCGCGPIO  *((volatile u32*) (SC_BASE_ADDRESS+0x708))  //General-Purpose Input/Output Sleep Mode Clock Gating Control
#define SC_RCGCGPIO	 *((volatile u32*) (SC_BASE_ADDRESS+0x608))	 //General-Purpose Input/Output Run Mode Clock Gating Control
#define SC_RCGC2	   *((volatile u32*) (SC_BASE_ADDRESS+0x108))	 //This register controls the clock gating logic in normal Run mode
#define SC_UARTCC		 *((volatile u32*) (SC_BASE_ADDRESS+0x708))
#define SC_SSICC		 *((volatile u32*) (SC_BASE_ADDRESS+0x708))
#define SC_ADCCC		 *((volatile u32*) (SC_BASE_ADDRESS+0x708))

#endif /* RCC_PRIVATE_H_ */
