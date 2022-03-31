/* 
 * File:   uart_initialization.h
 * Author: Neata Adrian 
 *
 * Created on January 26, 2022, 2:06 PM
 */


#ifndef UART_INITIALIZATION_H
#define	UART_INITIALIZATION_H

extern void Uart_Send(uint8_t byte);
extern void Uart_Print(const char* string);
extern void USART1_INIT(void);
extern char Uart_Get();
#endif	/* UART_INITIALIZATION_H */

