/*
 * coreM4.c
 *
 *  Created on: 7 Oca 2023
 *      Author: metab
 */
#include "coreM4.h"

void nvic_irqno_enable(uint8_t irq_num){
	if(irq_num < 32)
		NVIC_ISERx->NVIC_ISER0 |= (1U<<irq_num );
	else if( irq_num < 64)
		NVIC_ISERx->NVIC_ISER1 |= (1U<<(irq_num%32));
	else if(irq_num <= 81)
		NVIC_ISERx->NVIC_ISER2 |= (1U<<(irq_num%32));

}

void nvic_irqno_disable(uint8_t irq_num){
	if(irq_num < 32)
		NVIC_ICERx->NVIC_ICER0 |= ((1U<<irq_num ));
	else if( irq_num < 64)
		NVIC_ICERx->NVIC_ICER1 |= (1U<<(irq_num%32));
	else if(irq_num <= 81)
		NVIC_ICERx->NVIC_ICER2 |= (1U<<(irq_num%32));
}