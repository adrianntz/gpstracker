/* 
 * File:   uart_initialization.h
 * Author: adyco
 *
 * Created on January 26, 2022, 2:06 PM
 */


#ifndef UART_INITIALIZATION_H
#define	UART_INITIALIZATION_H

extern void uart_send(uint8_t byte);
extern void uart_print(const char* string);
extern void uart1_init(void);
extern char uart_get();
#endif	/* UART_INITIALIZATION_H */

