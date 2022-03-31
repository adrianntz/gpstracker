#include <avr/io.h>

#include <stdint.h>

#define HIGH 1
#define LOW 0

void SET_DTR(bool setting) //Function to set DTR pin HIGH or LOW 
{
  if (setting == true)
    PORTC.OUTSET= PIN5_bm; //SET DTR HIGH
  if (setting == false)
    PORTC.OUTCLR=PIN5_bm; //SET DTR LOW
}

void SET_PWKEY(bool setting) //Function to set PWKEY pin HIGH or LOW 
{
  if (setting == true)
    PORTC.OUTSET= PIN4_bm; //SET PWKEY HIGH
  if (setting == false)
    PORTC.OUTCLR=PIN4_bm; //SET PWKEY LOW
}

void PORT_INIT() 
{
  PORTC.DIR |= PIN6_bm | PIN7_bm | PIN4_bm | PIN5_bm; //PIN7=RST PIN4=PWKEY PIN5=DTR
  PORTD.PIN6CTRL = PORT_ISC1_bm; //ISC[2:0] PIN6CTRL REG Set to 0x02 = 0b010 for enabling rising edge interrupt
  PORTC.OUTSET = PIN6_bm;
}