/**
 * @file NVIC_private.h
 * @author mohamed moustafa (mohamed.bekheet2023@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef NVIC_private_H
#define NVIC_private_H


#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI0_R             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI3_R             (*((volatile unsigned long *)0xE000E40C))

#define NVIC_PRIORITY_GROUP_8_SUBGROUP_1                     0x4
#define NVIC_PRIORITY_GROUP_1_SUBGROUP_8                     0x7
#define NVIC_PRIORITY_GROUP_4_SUBGROUP_2                     0x5
#define NVIC_PRIORITY_GROUP_2_SUBGROUP_4                     0x6


#endif
