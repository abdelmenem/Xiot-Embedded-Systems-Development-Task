/*
 * interrupt.c
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#include "interrupt.h"

void INT0_INIT()
{
	SREG|=(1<<7);
	MCUCR|=(1<<ISC00);
	//MCUCSR
	GICR|=(1<<INT0);
	//GIFR

}
ISR(INT0_vect)
{
	PORTD^=(1<<4);
	if(PORTD&(1<<4))
	UART_sendString("ON");
	else
	UART_sendString("OFF");

}
