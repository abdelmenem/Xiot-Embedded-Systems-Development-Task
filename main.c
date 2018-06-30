/*
 * main.c
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#include "adc.h"
#include "uart.h"
#include "interrupt.h"


int main()
{
	DDRD|=(1<<4);
	DDRD&=~(1<<2);
	PORTD|=(1<<4);
	PORTD|=(1<<2);
	DDRA&=~(1<<0);
	INT0_INIT();
	UART_INIT();
	ADC_INIT();
	int temp;
	char temperature_string[10];
	for(;;)
	{

		temp = ADC_read(0);
		temp = (temp*150*5)/(1023*1.5);
		itoa(temp,temperature_string,10);
		UART_sendString(temperature_string);
		_delay_ms(3000);
	}
}
