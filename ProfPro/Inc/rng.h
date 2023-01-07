/*
 * rng.h
 *
 *  Created on: 7 Oca 2023
 *      Author: metab
 */

#ifndef RNG_H_
#define RNG_H_

#include <stdint.h>
#include "stm32f407xx.h"
#include "coreM4.h"

//RNG CR BITS
#define IE 			(1U<<3)
#define RNGEN 		(1U<<2)

//RNG SR BITS
#define RNG_DRDY		(1U<<0)
#define RNG_CECS		(1U<<1)
#define RNG_SECS		(1U<<2)
#define RNG_CEIS		(1U<<5)
#define RNG_SEIS		(1U<<6)

//sonra taşınacak
//Rng ile alakalı değil
#define PLLON		(1U<<24)
#define PLLREADY	(1U<<25)


void rng_init();

#endif /* RNG_H_ */
