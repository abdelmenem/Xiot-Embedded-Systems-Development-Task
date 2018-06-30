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
	DDRD|=(1<<4);     // adjust led pin as output
	DDRD&=~(1<<2);	  // adjust interrupt0 pin as input
	PORTD|=(1<<4);    // led pin initial value ON
	PORTD|=(1<<2);    // interrupt pin internal pull up res activate
	DDRA&=~(1<<0);    // adjust ADC channel 0 as input
	INT0_INIT();	  // initiate interrupt 0
	UART_INIT();      // initiate uart with baudrate 9600
	ADC_INIT();       // initiate ADC
	int temp;
	char temperature_string[10];
	for(;;)
	{

		temp = ADC_read(0);					// read value of temperature and store it in temp variable
		temp = (temp*150*5)/(1023*1.5);     //convert received value into temperature value ,the mathimatics operation depend on the temp. sensor 
						    // in that case in represent the temp sensor by lm35 to generate analog signal.	
		itoa(temp,temperature_string,10);   // convert value to string to send it using uart
		UART_sendString(temperature_string); // send using uart
		_delay_ms(3000); 					// delay 3 seconds
	}
}
