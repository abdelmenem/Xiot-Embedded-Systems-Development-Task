/*
 * uart.c
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#include "uart.h"

void UART_INIT()
{
	UCSRA|=(1<<U2X);
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=12;
	UBRRH=0;
}

void UART_sendByte(const unsigned char data)
{

	while(!(UCSRA&(1<<UDRE))){}

	UDR = data;
}

void UART_sendString(const unsigned char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}

}
