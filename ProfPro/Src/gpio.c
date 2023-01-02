/*
 * gpio.c
 *
 *  Created on: 3 Ara 2022
 *      Author: metab
 */
#include "gpio.h"


PRIVATE void gpio_perip_en(GPIO_RegDef_t * pGpiox){
	if(pGpiox==GPIOA)
		GPIOA_CLOCK_ENABLE();
	else if(pGpiox==GPIOB)
		GPIOB_CLOCK_ENABLE();
	else if(pGpiox==GPIOC)
		GPIOC_CLOCK_ENABLE();
	else if(pGpiox==GPIOD)
		GPIOD_CLOCK_ENABLE();
	else if(pGpiox==GPIOE)
		GPIOE_CLOCK_ENABLE();
	else if(pGpiox==GPIOF)
		GPIOF_CLOCK_ENABLE();
	else if(pGpiox==GPIOG)
		GPIOG_CLOCK_ENABLE();
	else if(pGpiox==GPIOH)
		GPIOH_CLOCK_ENABLE();
	else if(pGpiox==GPIOI)
		GPIOI_CLOCK_ENABLE();
}


void gpio_init(GPIO_Handle_t * pGpio_handle){
	uint32_t temp=0;

	//clock aktif et
	gpio_perip_en(pGpio_handle->pGpioX);
	/*
	volatile uint32_t * p_rcc_ahb1_reg=(uint32_t*)(0x40023800+0x30);
	*p_rcc_ahb1_reg |=(1u<<3);
*/

	//pin mode ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_mode << (2 * pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->MODER &= ~(0b11<<(2*pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->MODER |=temp;

	//speed ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_speed << (2 * pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OSPEEDR &= ~(0b11<<(2*pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OSPEEDR |=temp;

	//pull up pull down ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_pupd << (2 * pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->PUPDR &= ~(0b11<<(2*pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->PUPDR |=temp;

	//otype ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_otype << (pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OTYPER &= ~(0b1<<(pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OTYPER |=temp;

	//alternate func mode --ilerde
	if(pGpio_handle->gPIO_pinConfig.pin_mode==GPIO_MODE_ALTERNATE)
		;

	//bi portun pinine 1 mi 0 mı yazacağız....




}


void  gpio_writeto_output_pin(GPIO_RegDef_t *pGpiox ,uint8_t pin_no, uint8_t val){

	if(val==GPIO_PIN_SET)
		pGpiox->ODR |= (1u<<pin_no);
	else
		pGpiox->ODR &=~ (1u<<pin_no);


}

void gpio_writeto_output_port(){


}


void gpio_toggleto_output_pin(GPIO_RegDef_t *pGpiox ,uint8_t pin_no){
	pGpiox->ODR ^=(1u<<pin_no);

}


