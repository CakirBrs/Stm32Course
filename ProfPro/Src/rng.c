/*
 * rng.c
 *
 *  Created on: 7 Oca 2023
 *      Author: metab
 */


#include "rng.h"




void rng_init(){

	//PLL on
	RCC->CR=PLLON;
	//PLL ready flag
	while(!(RCC->CR & PLLREADY)); //PLLREADY hazır olana kadar bekle demek bu.

	//clock
	RNG_CLOCK_ENABLE();

	//1-enable interrupt
	RNG->CR |= IE;

	//2 Rngen bit in the rng_cr
	RNG->CR |= RNGEN;

	//3 seis ve ceis oku
	nvic_irqno_enable(IRQ_HASH_RNG);

}







int64_t get_random_number(){
	rng_init();
	//if(RNG->CR & RNGEN)
	return RNG->DR;
	//return RNG_ERROR;
}
