/*
 * main.c
 *
 *  Created on: Aug 8, 2022
 *      Author: mohamed moustafa aly ::: mohamed.bekheet2023@gmail.com
 */
#define STM_BLUEBILL


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#include "SYSTICK_interface.h"

#include "NVIC_interface.h"

u32 SYSFREQ ;//from rcc
u32 STK_FREQ = 0;//from systick handler
unsigned long long STK_COUNTS=0;//from systick handler


/////////////////////////// - PWM APPLICATION - //////////////////////////
#define LED_PORT GPIO_PORTA
#define LED_PIN 2

 u32 OnTime = 100;//in ms
 u32 OffTime = 100;//in ms

void LED_PWM_RUN(void){
	
	u32 currT_ms = STK_COUNTS;//*1000/SYSFREQ;
 	if(currT_ms <= OnTime) GPIO_SetPinLevel(LED_PORT, LED_PIN, OUTPUT_HIGH);
 	else if (currT_ms < OnTime+OffTime) GPIO_SetPinLevel(LED_PORT, LED_PIN, OUTPUT_LOW);
 	else if (currT_ms >= OnTime+OffTime) STK_COUNTS = 0;

 }


void LED_PWM_INIT(u32 OnTime_ms, u32 OffTime_ms){

	//(SC_SYSCLK_FREQ/8)/1000
	STK_voidSetPeriodicInterval( 10000 ,LED_PWM_RUN) ;//1000 >>1ms every count is 1microsecond
	OnTime = OnTime_ms ;
	OffTime = OffTime_ms ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GPIO_PIN_CONFIG_t PINF0 = {
	.portBus = BUS_APB,
	.pinPort = GPIO_PORTF,
	.pin = PORT_PIN2,
	.pinMode = MODE_DIO,
	.pinDir = DIR_OUTPUT,
	.pinAttach = GPIO_PULLUP,
	.pinLevel = OUTPUT_HIGH,
	.pinCurr = GPIO_4mA,
};

#define Enable_Exceptions()    __asm("CPSIE I")

int main(void) {
	
	
//////////////////////////////////////////INITIALIZATION/////////////////////////////////////
	SC_Init();
	SC_EnableGPIOPort(SC_GPIO_PORTF);

	Enable_Exceptions();
	NVIC_Init();
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	GPIO_InitPort(&PINF0);

	STK_voidInit(STK_FREQ,SYSTICK_AHB_8);
	

////////////////////////////////////APPLICATION//////////////////////////////////////////////
	LED_PWM_INIT(100,100);
  
	while (1) {
	
	}
	return 0;
}
