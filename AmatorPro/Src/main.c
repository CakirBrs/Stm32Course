/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
*/
int main(void)
{

    //PD13 Clock hattını aç
	//AHB1 Clock
	//uint32_t * p_rcc_base_address= (uint32_t*)0x40023800;
	//uint32_t * p_gpio_base_address= (uint32_t*)0x40020C00;

	volatile uint32_t* p_rcc_ahb1_reg=(uint32_t*)(0x40023800+0x30);
	*p_rcc_ahb1_reg |= (1u<<3); //D portu clock enable
	volatile uint32_t * p_gpio_moder_reg = (uint32_t*) (0x40020C00);
	* p_gpio_moder_reg=(1u<<26);

	volatile uint32_t *p_gpio_otype_reg= (uint32_t*) (0x40020C00+0x04);
	*p_gpio_otype_reg &= ~(1<<13);

	volatile uint32_t *p_gpio_odr_reg= (uint32_t*) (0x40020C00+0x14);
	*p_gpio_odr_reg |= (1<<13);

	while(1)
	{

	}
}
