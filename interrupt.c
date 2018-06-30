/*
 * interrupt.c
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#include "interrupt.h"

void INT0_INIT()
{
	SREG|=(1<<7);				// enable interrupts
	MCUCR|=(1<<ISC00);			//Any logical change on INT0 generates an interrupt request.
	GICR|=(1<<INT0);			//External Interrupt Request 0 Enable
	
}
ISR(INT0_vect)					// interrupt service routine of interrupt 0 
{
	PORTD^=(1<<4);				// when interrupt occur togle PD4
	if(PORTD&(1<<4))			// if PD4 on send using uart "ON"
	UART_sendString("ON");
	else					// else send using uart "OFF"
	UART_sendString("OFF");

}
