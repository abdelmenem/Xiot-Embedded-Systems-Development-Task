/*
 * adc.h
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#ifndef ADC_H_
#define ADC_H_

#include "common_lib.h"

//decleration of functions that will defined in adc.c

void ADC_INIT();
unsigned short ADC_read(unsigned char channel_num);



#endif /* ADC_H_ */
