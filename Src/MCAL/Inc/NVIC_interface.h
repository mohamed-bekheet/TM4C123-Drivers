/**
 * @file NVIC_interface.h
 * @author mohamed moustafa (mohamed.bekheet2023@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NVIC_interface_H
#define NVIC_interface_H

#include "NVIC_config.h"



const NVIC_Cfg NVIC_PCfg[NVIC_NUM_OF_ENABLED_INTERRUPT] = {

   /* InterruptNum, PriorityGroup, PrioritySubGroup */
   {NVIC_GPIO_PORTA,  0, 7},
   {NVIC_GPIO_PORTF,  0, 6},
   {NVIC_SYSTICK,     1, 5},

};

const u8 NVIC_SUB_GP_Cfg = NVIC_PRIORITY_GROUP_8_SUBGROUP_1;


void NVIC_Init(void);



#endif