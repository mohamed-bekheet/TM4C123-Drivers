/**
 * @file NVIC_config.h
 * @author mohamed moustafa (mohamed.bekheet2023@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef NVIC_config_H
#define NVIC_config_H

#include "STD_TYPES.h"
#include "NVIC_private.h"


#define NVIC_NUM_OF_ENABLED_INTERRUPT                       (3)

#define NVIC_GPIO_PORTA     (0U)
#define NVIC_GPIO_PORTF     (1U)
#define NVIC_SYSTICK        (2U)

typedef struct
{
    u8 InterrNum;
    u8 PriorityGP;
    u8 PrioritySubGP;
}NVIC_Cfg;

extern const NVIC_Cfg NVIC_PCfg[NVIC_NUM_OF_ENABLED_INTERRUPT];

extern const u8 NVIC_SUB_GP_Cfg;
 
#endif

