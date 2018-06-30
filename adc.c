/*
 * adc.c
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#include "adc.h"

void ADC_INIT()
{
	ADMUX=0;
	ADCSRA|=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);

}

unsigned short ADC_read(unsigned char channel_num)
{
	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* choose the correct channel by setting the channel number in MUX4:0 bits */
	ADCSRA|=(1<<ADSC); /* start conversion write '1' to ADSC */
	while(!(ADCSRA&(1<<ADIF))); /* wait for conversion to complete ADIF becomes '1' */
	ADCSRA|=(1<<ADIF); /* clear ADIF by write '1' to it :) */
	return ADC; /* return the data register */
}
