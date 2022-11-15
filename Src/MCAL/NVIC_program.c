/**
 * @file NVIC_program.c
 * @author mohamed moustafa (mohamed.bekheet2023@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "NVIC_interface.h"

void NVIC_Init(void)
{
	u8 i;
  u32*RegisterAdd;
  u32 BitNum;
  u32 TotalPriority;
	*((volatile u32*) (0xE000E000 + 0xD0C)) = ((0x05FA<<16) + (NVIC_SUB_GP_Cfg << 8));
	for(i = 0; i < NVIC_NUM_OF_ENABLED_INTERRUPT; i++)
    {
        /* enable the corresponding interrupt */
        RegisterAdd = (u32*)(NVIC_EN0_R + ((NVIC_PCfg[i].InterrNum / 32) * 4));
        BitNum = NVIC_PCfg[i].InterrNum % 32;
        *RegisterAdd |= 1<< BitNum;

        /* set the priority */
        RegisterAdd = (u32*)(NVIC_PRI0_R + ( (NVIC_PCfg[i].InterrNum / 4) * 4 ) );
        BitNum = (NVIC_PCfg[i].InterrNum % 4);
        BitNum = (BitNum * 8) + 5;
        TotalPriority = (NVIC_PCfg[i].PriorityGP << (NVIC_SUB_GP_Cfg - 0x4)) | (NVIC_PCfg[i].PrioritySubGP);
        *RegisterAdd |= TotalPriority << BitNum;
    }
	
}


