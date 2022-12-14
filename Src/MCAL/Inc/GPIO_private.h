/*
 * GPIO_private.h
 *
 *  Created on: Aug 4, 2022
 *      Author:mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#include "STD_TYPES.h"

typedef struct
{
	// 0x400
	volatile u32 GPIODIR;
	volatile u32 GPIOIS;
	volatile u32 GPIOIBE;
	volatile u32 GPIOIEV;
	volatile u32 GPIOIM;
	volatile u32 GPIORIS;
	volatile u32 GPIOMIS;
	volatile u32 GPIOICR;
	volatile u32 GPIOAFSEL; // GPIO Alternate Function Select
} GPIO_PortP1_t;//gpio registers port part 1

typedef struct
{
	// 0x500
	volatile u32 GPIODR2R;	 // GPIO 2-mA Drive Select
	volatile u32 GPIODR4R;	 // GPIO 4-mA Drive Select
	volatile u32 GPIODR8R;	 // GPIO 8-mA Drive Select
	volatile u32 GPIOODR;	 // GPIO Open Drain Select
	volatile u32 GPIOPUR;	 // GPIO Pull-Up Select
	volatile u32 GPIOPDR;	 // GPIO Pull-Down Select
	volatile u32 GPIOSLR;	 // GPIO Slew Rate Control Select
	volatile u32 GPIODEN;	 // Register 18: GPIO Digital Enable
	volatile u32 GPIOLOCK;	 // Register 19: GPIO Lock (GPIOLOCK),
	volatile u32 GPIOCR;	 // Register 20: GPIO Commit (GPIOCR)
	volatile u32 GPIOAMSEL;	 // Register 21: GPIO Analog Mode Select (GPIOAMSEL)
	volatile u32 GPIOPCTL;	 // Register 22: GPIO Port Control (GPIOPCTL)
	volatile u32 GPIOADCCTL; // Register 23: GPIO ADC Control (GPIOADCCTL)
	volatile u32 GPIODMACTL; // Register 24: GPIO DMA Control (GPIODMACTL)
} GPIO_PortP2_t;//gpio registers port part 2

typedef struct
{
	volatile u32 GPIOPeriphID4; // Register 25: GPIO Peripheral Identification 4 (GPIOPeriphID4)
	volatile u32 GPIOPeriphID5; // Register 26: GPIO Peripheral Identification 5 (GPIOPeriphID5)
	volatile u32 GPIOPeriphID6; // Register 27: GPIO Peripheral Identification 6 (GPIOPeriphID6)
	/// CONTIUED...........

} GPIO_PortP3_t;//gpio registers port part 3

// 400,500,fd0

// defualt bus
#define GPIO_REG_PORTA_P1_APB ((volatile GPIO_PortP1_t *)(0x40004000+0x400))
#define GPIO_REG_PORTB_P1_APB ((volatile GPIO_PortP1_t *)(0x40005000+0x400))
#define GPIO_REG_PORTC_P1_APB ((volatile GPIO_PortP1_t *)(0x40006000+0x400))
#define GPIO_REG_PORTD_P1_APB ((volatile GPIO_PortP1_t *)(0x40007000+0x400))
#define GPIO_REG_PORTE_P1_APB ((volatile GPIO_PortP1_t *)(0x40024000+0x400))
#define GPIO_REG_PORTF_P1_APB ((volatile GPIO_PortP1_t *)(0x40025000+0x400))

// defualt bus
#define GPIO_REG_PORTA_P2_APB ((volatile GPIO_PortP2_t *)(0x40004000+0x500))
#define GPIO_REG_PORTB_P2_APB ((volatile GPIO_PortP2_t *)(0x40005000+0x500))
#define GPIO_REG_PORTC_P2_APB ((volatile GPIO_PortP2_t *)(0x40006000+0x500))
#define GPIO_REG_PORTD_P2_APB ((volatile GPIO_PortP2_t *)(0x40007000+0x500))
#define GPIO_REG_PORTE_P2_APB ((volatile GPIO_PortP2_t *)(0x40024000+0x500))
#define GPIO_REG_PORTF_P2_APB ((volatile GPIO_PortP2_t *)(0x40025000+0x500))

// defualt bus
#define GPIO_REG_PORTA_P3_APB ((volatile GPIO_PortP3_t *)(0x40004000+0xFD0))
#define GPIO_REG_PORTB_P3_APB ((volatile GPIO_PortP3_t *)(0x40005000+0xFD0))
#define GPIO_REG_PORTC_P3_APB ((volatile GPIO_PortP3_t *)(0x40006000+0xFD0))
#define GPIO_REG_PORTD_P3_APB ((volatile GPIO_PortP3_t *)(0x40007000+0xFD0))
#define GPIO_REG_PORTE_P3_APB ((volatile GPIO_PortP3_t *)(0x40024000+0xFD0))
#define GPIO_REG_PORTF_P3_APB ((volatile GPIO_PortP3_t *)(0x40025000+0xFD0))

// have to change bus in rcc driver
#define GPIO_REG_PORTA_AHB ((volatile GPIO_Port_t *)0x40059000)
#define GPIO_REG_PORTB_AHB ((volatile GPIO_Port_t *)0x40059000)
#define GPIO_REG_PORTC_AHB ((volatile GPIO_Port_t *)0x4005A000)
#define GPIO_REG_PORTD_AHB ((volatile GPIO_Port_t *)0x4005B000)
#define GPIO_REG_PORTE_AHB ((volatile GPIO_Port_t *)0x4005C000)
#define GPIO_REG_PORTF_AHB ((volatile GPIO_Port_t *)0x4005D000)
//0b00000000000000000000001111111100
#define GPIO_REG_PORTA_DATA (*(volatile u32 *)(0x40004000+0X3FC))
#define GPIO_REG_PORTF_DATA (*(volatile u32 *)(0x40025000+0X3FC))
//#define GPIO_REG_PORTA_DATA (*(volatile u32 *)(0x40004000+255))

#endif /* GPIO_PRIVATE_H_ */
