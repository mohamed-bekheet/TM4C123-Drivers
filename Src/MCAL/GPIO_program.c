/*
 * GPIO_program.c
 *
 *  Created on: Aug 4, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"


//   GPIO_REG_PORTA_APB
// Public functions
void GPIO_InitPort(const GPIO_PIN_CONFIG_t *GPIO_PIN_CONFIG_ptr)
{
	if (GPIO_PIN_CONFIG_ptr->portBus == BUS_APB)
	{
		switch (GPIO_PIN_CONFIG_ptr->pinPort)
		{
		case GPIO_PORTA:
			/* code */
			//MODE
			if (GPIO_PIN_CONFIG_ptr->pinMode == MODE_DIO)
			{
				CLR_BIT(GPIO_REG_PORTA_P1_APB->GPIOAFSEL, GPIO_PIN_CONFIG_ptr->pin);
				SET_BIT(GPIO_REG_PORTA_P2_APB->GPIODEN, GPIO_PIN_CONFIG_ptr->pin);
			}
			if (GPIO_PIN_CONFIG_ptr->pinMode == MODE_ALTER)
			{
				SET_BIT(GPIO_REG_PORTA_P1_APB->GPIOAFSEL, GPIO_PIN_CONFIG_ptr->pin);
				CLR_BIT(GPIO_REG_PORTA_P2_APB->GPIODEN, GPIO_PIN_CONFIG_ptr->pin);
			}
			//DIR
			if (GPIO_PIN_CONFIG_ptr->pinDir == DIR_INPUT)
			{
				CLR_BIT(GPIO_REG_PORTA_P1_APB->GPIODIR, GPIO_PIN_CONFIG_ptr->pin);
			}
			if (GPIO_PIN_CONFIG_ptr->pinDir == DIR_OUTPUT)
			{
				SET_BIT(GPIO_REG_PORTA_P1_APB->GPIODIR, GPIO_PIN_CONFIG_ptr->pin);
			}
			//INTERNAL ATTACH
			if (GPIO_PIN_CONFIG_ptr->pinAttach == GPIO_OPENDRAIN)
			{
				SET_BIT( GPIO_REG_PORTA_P2_APB->GPIOODR , GPIO_PIN_CONFIG_ptr->pin);
			}
			if (GPIO_PIN_CONFIG_ptr->pinAttach == GPIO_PULLUP)
			{
				SET_BIT(GPIO_REG_PORTA_P2_APB->GPIOPUR, GPIO_PIN_CONFIG_ptr->pin);
			}
			if (GPIO_PIN_CONFIG_ptr->pinAttach == GPIO_PULLDOWN)
			{
				SET_BIT(GPIO_REG_PORTA_P2_APB->GPIOPDR, GPIO_PIN_CONFIG_ptr->pin);
			}
			//PIN CURRENT
			if (GPIO_PIN_CONFIG_ptr->pinCurr == GPIO_2mA)
			{
				SET_BIT(GPIO_REG_PORTA_P2_APB->GPIODR2R, GPIO_PIN_CONFIG_ptr->pin);
			}
			if (GPIO_PIN_CONFIG_ptr->pinCurr == GPIO_4mA)
			{
				SET_BIT(GPIO_REG_PORTA_P2_APB->GPIODR4R, GPIO_PIN_CONFIG_ptr->pin);
			}
			if (GPIO_PIN_CONFIG_ptr->pinCurr == GPIO_8mA)
			{
				SET_BIT(GPIO_REG_PORTA_P2_APB->GPIODR8R, GPIO_PIN_CONFIG_ptr->pin);
			}
			//PIN VALUE USE DATA REGISTER (LIKE ATOMIC ACCESS)
			GPIO_REG_PORTA_DATA	= (GPIO_PIN_CONFIG_ptr->pinLevel<<(GPIO_PIN_CONFIG_ptr->pin));

			break;
		case GPIO_PORTB:
			/* code */
			break;
		case GPIO_PORTC:
			/* code */
			break;
		case GPIO_PORTD:
			/* code */
			break;
		case GPIO_PORTE:
			/* code */
			break;
		case GPIO_PORTF:
			/* code */
			break;
		}
	}
	else
		; // for AHB bus
}

void GPIO_SetPinMode(GPOIO_PORT_e port, GPOIO_PIN_e pin, GPOIO_PIN_MODE_e PinMod);
void GPIO_SetPinDir(GPOIO_PORT_e port, GPOIO_PIN_e pin, GPOIO_PIN_DIRECTION_e pinDir);
void GPIO_SetPinInternalAttach(GPOIO_PORT_e port, GPOIO_PIN_e pin, GPOIO_PIN_INTERNAL_ATTACH_e pinAttach);

// DIO control functions
void GPIO_SetPinLevel(GPOIO_PORT_e port, GPOIO_PIN_e pin, GPOIO_PIN_LEVEL_e pinLevel){
//USE DATA REGISTER
	GPIO_REG_PORTA_DATA	= (pinLevel<<(pin));

}
