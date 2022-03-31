#include <avr/io.h>

void Uart_Send(uint8_t byte)
{
    while(!(USART1.STATUS & USART_DREIF_bm));
        USART1.TXDATAL = byte;
}

/*char uart_get()
{
    while(!(USART1.STATUS & (USART_RXCIF_bm)));   
            return USART1.RXDATAL;
}
  */

char Uart_Get()
{
    while(!(USART1.STATUS & (USART_RXCIF_bm)));   
            return USART1.RXDATAL;
}

void Uart_Print(const char* string)
{
    char ch;
    while(1)
    {
        ch = (char)*string++;
        if(ch != '\0')
            Uart_Send(ch);
        else
            break;
    }
}


void USART1_INIT(void)//USART Used for communication with SIM808 through AT commands
{
    USART1.CTRLA|=1<<7;//Turn on  RXCIE (Recieve Interrupt)
    USART1.BAUD = 1667;  // Set Baud Rate=9600 @ 4MHz
    USART1.CTRLB = USART_TXEN_bm | USART_RXEN_bm; //Enable Both Recieve and Transmit
    PORTC.DIR |= PIN0_bm; //TX pin set as output
}

