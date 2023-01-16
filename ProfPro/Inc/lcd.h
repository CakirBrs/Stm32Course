/*
 * lcd.h
 *
 *  Created on: 9 Oca 2023
 *      Author: metab
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f407xx.h"
#include "gpio.h"

#define LCD_GPIO_PORT 			GPIOD

enum{
	LCD_GPIO_RS,
	LCD_GPIO_RW,
	LCD_GPIO_EN,
	LCD_GPIO_PD4,
	LCD_GPIO_PD5,
	LCD_GPIO_PD6,
	LCD_GPIO_PD7
};

#define LCD_CMD_4DL_2N_F5X8		0x28
#define LCD_CMD_DON_CON_BON		0x0F
#define LCD_CMD_INC_NO_SHIFT	0x06
#define LCD_CMD_CLEAR			0x01
void lcd_init();
static void write_nibble(uint32_t val);
void lcd_clear_display();
void lcd_display_on(uint8_t mode);
//taşınabilir
void mdelay(uint32_t delay);
void udelay(uint32_t delay);
void lcd_send_command(uint8_t cmd);

#endif /* LCD_H_ */
