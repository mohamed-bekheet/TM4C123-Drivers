/*
 * GPIO_interface.h
 *
 *  Created on: Aug 4, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
#include"STD_TYPES.h"


typedef enum{
	BUS_APB,
	BUS_AHB,
}GPOIO_PORT_BUS_e;

typedef enum{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE,
	GPIO_PORTF,
}GPOIO_PORT_e;

typedef enum{
	PORT_PIN0,
	PORT_PIN1,
	PORT_PIN2,
	PORT_PIN3,
	PORT_PIN4,
	PORT_PIN5,
	PORT_PIN6,
	PORT_PIN7,
}GPOIO_PIN_e;

typedef enum{
	MODE_DIO,
	MODE_AIO,//ANALOG INPUT OUTPUT
	MODE_ALTER,//ALTERNATIVE INPUT OUTPUT
	MODE_INTERRUPT,
}GPOIO_PIN_MODE_e;


typedef enum{
	DIR_INPUT,
	DIR_OUTPUT,
}GPOIO_PIN_DIRECTION_e;
//input
typedef enum{
	GPIO_OPENDRAIN,
	GPIO_PULLUP,
	GPIO_PULLDOWN,
}GPOIO_PIN_INTERNAL_ATTACH_e;

//output
typedef enum{
	OUTPUT_LOW,
	OUTPUT_HIGH,
}GPOIO_PIN_LEVEL_e;

typedef enum{
	GPIO_2mA,
	GPIO_4mA,
	GPIO_8mA,
}GPOIO_PIN_OUTCURRENT_e;


typedef struct{
	GPOIO_PORT_BUS_e portBus;
	GPOIO_PORT_e pinPort;
	GPOIO_PIN_e pin;
	GPOIO_PIN_MODE_e pinMode;
	GPOIO_PIN_DIRECTION_e pinDir;
	GPOIO_PIN_INTERNAL_ATTACH_e pinAttach;
	GPOIO_PIN_LEVEL_e pinLevel;
	GPOIO_PIN_OUTCURRENT_e pinCurr;
}GPIO_PIN_CONFIG_t;


// Public functions
void GPIO_InitPort(const GPIO_PIN_CONFIG_t *GPIO_PIN_CONFIG_ptr);
void GPIO_SetPinMode( GPOIO_PORT_e port, GPOIO_PIN_e pin, GPOIO_PIN_MODE_e PinMod);
void GPIO_SetPinDir(GPOIO_PORT_e port, GPOIO_PIN_e pin,GPOIO_PIN_DIRECTION_e pinDir);
void GPIO_SetPinInternalAttach(GPOIO_PORT_e port, GPOIO_PIN_e pin,GPOIO_PIN_INTERNAL_ATTACH_e pinAttach);

//DIO control functions
void GPIO_SetPinLevel(GPOIO_PORT_e port, GPOIO_PIN_e pin, GPOIO_PIN_LEVEL_e pinLevel);


#endif /* GPIO_INTERFACE_H_ */
