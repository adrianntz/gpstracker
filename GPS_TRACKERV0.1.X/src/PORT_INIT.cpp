#include <avr/io.h>

#include <stdint.h>

#define HIGH 1
#define LOW 0

void SET_DTR(bool setting) //functie de a da set sau pull down la DTR
{
  if (setting == true)
    PORTB.OUT |= PIN2_bm; //SET DTR HIGH
  if (setting == false)
    PORTB.OUT &= !PIN2_bm; //SET DTR LOW
}

void port_init() {
  PORTC.DIR |= PIN6_bm | PIN7_bm | PIN2_bm | PIN3_bm; //PIN7=RST PIN3=PWKEY PIN2=DTR
  PORTB.DIR|=PIN2_bm|PIN3_bm;
  PORTD.PIN6CTRL = PORT_ISC1_bm; //ISC[2:0] setat la 0x2=0b010 pt interrupt pe rising edge
  PORTC.OUTSET = PIN6_bm;
}