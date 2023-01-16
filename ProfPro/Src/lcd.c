/*
 * lcd.c
 *
 *  Created on: 9 Oca 2023
 *      Author: metab
 */

#include "lcd.h"

/*
 *PD0 ->RS
 *PD1 ->RW
 *PD2 ->E
 *PD3 ->DB4
 *PD4 ->DB5
 *PD5 ->DB6
 *PD6 ->DB7
 */
void lcd_send_command(uint8_t cmd){
	//RS=0 LCD command
	gpio_writeto_output_pin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_RESET);

	//RW=0 write lcd
	gpio_writeto_output_pin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);
	write_nibble(cmd>>4);
	write_nibble(cmd & 0x0F);
}

void lcd_print_string(const char* message){
	while (*message !='\0'){
		lcd_print_char((uint8_t*)*message++);
	}
}

void lcd_print_char(uint8_t cmd){
	//RS=1 LCD command
	gpio_writeto_output_pin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_SET);

	//RW=0 write lcd
	gpio_writeto_output_pin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);
	write_nibble(cmd>>4);
	write_nibble(cmd & 0x0F);
}

void lcd_init(){
	//1-GPIO pin init
	GPIO_Handle_t lcd_pin = {LCD_GPIO_PORT ,{LCD_GPIO_RS,GPIO_MODE_OUT,GPIO_SPEED_MEDIUM,GPIO_OTYPE_PP,GPIO_NO_PUPD }};
	gpio_init(&lcd_pin);

	//lcd_pin.gPIO_pinConfig.pin_number = LCD_GPIO_RW;
	//gpio_init(&lcd_pin);

	for(int i=0 ; i<=6 ; i++){
		lcd_pin.gPIO_pinConfig.pin_number=i; //all lcd pins init
		gpio_init(&lcd_pin);
	}


	mdelay(80); //40 normal bekleme süresi

	//RS=0 LCD command
	gpio_writeto_output_pin(LCD_GPIO_PORT, LCD_GPIO_RS, GPIO_PIN_RESET);

	//RW=0 write lcd
	gpio_writeto_output_pin(LCD_GPIO_PORT, LCD_GPIO_RW, GPIO_PIN_RESET);

	write_nibble(0x03); //000011
	mdelay(5);
	write_nibble(0x03);
	mdelay(1);//udelay(120); //100 bekletmemiz gerekliydi biraz daha uzun beklettik
	write_nibble(0x03);
	write_nibble(0x02);

	//func set commond 2N lines 4bit data len font 5*8
	write_nibble(LCD_CMD_4DL_2N_F5X8);
	//display on cursor on blinking on
	write_nibble(LCD_CMD_DON_CON_BON);
	//lcd clear
	///////////////////0x01 gönder lcd_send_command ile//lcd_clear_display();
	//enrty mode set
	write_nibble(LCD_CMD_INC_NO_SHIFT);

	lcd_display_on(LCD_CMD_DON_CON_BON);//lcd_display_on ??? oxo decimal 12:0b1100


}

static void write_nibble(uint32_t val){
	gpio_writeto_output_pin(GPIOD, LCD_GPIO_PD4, ((val>>0) & 0x1));
	gpio_writeto_output_pin(GPIOD, LCD_GPIO_PD5, ((val>>1) & 0x1));
	gpio_writeto_output_pin(GPIOD, LCD_GPIO_PD6, ((val>>2) & 0x1));
	gpio_writeto_output_pin(GPIOD, LCD_GPIO_PD7, ((val>>3) & 0x1));
	gpio_writeto_output_pin(GPIOD, LCD_GPIO_EN, GPIO_PIN_SET);
	udelay(60);
	gpio_writeto_output_pin(GPIOD, LCD_GPIO_EN, GPIO_PIN_RESET);
	udelay(60);
}

void lcd_clear_display(){
	lcd_send_command(LCD_CMD_CLEAR);
	mdelay(5);
}

void lcd_display_on(uint8_t mode){
	lcd_send_command(0x08 |mode);
}

void mdelay(uint32_t delay){
	for(uint32_t i=0;i<(delay*1000);i++);
}

void udelay(uint32_t delay){
	for(uint32_t i=0;i<(delay*1);i++);
}


