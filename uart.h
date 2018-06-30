/*
 * uart.h
 *
 *  Created on: Jun 30, 2018
 *      Author: men3em
 */

#ifndef UART_H_
#define UART_H_

#include "common_lib.h"

void UART_INIT();
void UART_sendByte(const unsigned char data);
void UART_sendString(const unsigned char *Str);





#endif /* UART_H_ */
