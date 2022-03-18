#include <avr/io.h>

void uart_send(uint8_t byte)
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

char uart_get()
{
    while(!(USART1.STATUS & (USART_RXCIF_bm)));   
            return USART1.RXDATAL;
}

void uart_print(const char* string)
{
    char ch;
    while(1)
    {
        ch = (char)*string++;
        if(ch != '\0')
            uart_send(ch);
        else
            break;
    }
}


void uart1_init(void)//USART folosit pentru comunicarea cu SIM808. Avem nevoie sa transmitem si sa si primim
{
    USART1.CTRLA|=1<<7;//pornim RXCIE
    USART1.BAUD = 1667;  // 9600 @ 4MHz
    USART1.CTRLB = USART_TXEN_bm | USART_RXEN_bm;  PORTC.DIR |= PIN0_bm;
}

