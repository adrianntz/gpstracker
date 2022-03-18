#include <avr/io.h>

#include <avr/interrupt.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include "NMEAParser.h"

#include "uart_initialization.h"

#include "ConvertToString.h"

#include "GPGGA_Parser.h"

#include "timer_init.h"

#include "PORT_INIT.h"

#include "accelerometer.h"

#define GET_GPS 1
#define SLEEP 0

char buffer_AT, msg[200], msg2[200] = "$GPGGA,";
unsigned int i = 0;
volatile bool delay_flag = false, gpsinfo_flag = false, MVT_SENSOR_STATUS = false;
volatile uint8_t timer_cnt = 0;
uint8_t j = 0;
uint8_t receiveData;

ISR(USART1_RXC_vect) //GPS module
{
  // rxc_flg=true => oprim prin citire RXDATAL
  if (gpsinfo_flag == true) {
    msg[i++] = USART1.RXDATAL; //buffer pt coordonate GPS
    if (USART1.RXDATAL == '\r') {
      gpsinfo_flag = false;
      i = 0;
    }
  } else
    buffer_AT = USART1.RXDATAL; //necesar pt a da clear la flag
}

ISR(PORTD_PORT_vect) {
  PORTD.INTFLAGS |= PIN6_bm; //clear int_flag for pin6 by writing 1 into 6th bit
  MVT_SENSOR_STATUS = true;

}

ISR(TCA0_OVF_vect) {
  TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm; // clear flag
  if (timer_cnt++ == 3) //facem overflow de 3 ori pt a avea 30 de secunde delay
  {
    delay_flag = true;
    timer_cnt = 0;
  }
  PORTC.OUTTGL = PIN6_bm;
}

void send_message_AT(char * msg) {
  /*    for(char m=0;m<3;m++)
                {
                   uart_print("AT\r");
                   delay_timer(arg_ms(200));
                }
   */
  delay_timer(arg_ms(100));
  uart_print("AT+CMGF=1\r\n");
  delay_timer(arg_ms(500));
  uart_print("AT+CMGS=\"+40769297780\"\r\n");
  delay_timer(arg_ms(500));
  uart_print(msg);
  uart_send('\n');
  uart_send((char) 26); //ASCII code 26 inseamna CTRL+Z character, ce este necesar pt semnalarea sfarsitul mesajului
}

int main() {
  port_init();
  uart1_init();
  timer_init();
  BMI_160_INIT();
  sei();
  bool do_once_flg = false;
  uint8_t GET_GPS_CNT = 10;
  uint8_t STATE = SLEEP;
  char cnt[5];
  uart_print("Module Initialized\r\n");
  while (true) {
    switch (STATE) {
    case GET_GPS:

      if (delay_flag == true) //cod care se ruleaza o data la 30 secunde
      {
        delay_flag = false;
        PORTC.OUTTGL = PIN6_bm;
        SET_DTR(LOW);
        uart_print("AT+CFUN=1\r\n");
        delay_timer(arg_ms(30));
        uart_print("AT+CGPSPWR=1\r\n");
        delay_timer(arg_ms(500));
        uart_print("AT+CGPSINF=2\r\n");
        delay_timer(arg_ms(33.5)); // delay 33 ms pentru a nu stoca in msg[] echo-ul de la sim808 cand trimitem  "AT+CGPSINF=2"
        gpsinfo_flag = true; //in intrerruptul RX semnalam sa stocheze urmatoarele date in string-ul msg
        parse(msg2);
        send_message_AT(SMS_STRING);
        intToStr(GET_GPS_CNT--, cnt,1);
        uart_print("GPS_CNT: ");
        uart_print(cnt);
        uart_print("\n");
      }
      break;

    case SLEEP:
      if (do_once_flg == false) //aceste cinebzu trebuie trimise doar o data
      {
        uart_print("AT+CGPSPWR=0\r\n");
        delay_timer(arg_ms(50));
        uart_print("AT+CFUN=0\r\n");
        delay_timer(arg_ms(50));
        uart_print("AT+CSCLK=1\r\n");
        delay_timer(arg_ms(50));
        SET_DTR(HIGH);
        do_once_flg = true;
      }
      else
          if (delay_flag == true) 
            {
              delay_flag = false;
              uart_print("Sleep...\n");
            }
      break;

    }

    if (MVT_SENSOR_STATUS == true) //Daca detectam miscare, trimitem de 10 ori informatie
    { //Cum sa trimitem un mesaj avem delay de 30s => trimitem informatie pt 300s=5min
      
      STATE = GET_GPS;
      MVT_SENSOR_STATUS = false;
    }

    if (GET_GPS_CNT == 0) //dupa cele 5 min de transmitere de informatie, intram in sleep
    {
      GET_GPS_CNT = 10;  
      STATE = SLEEP;
      do_once_flg = false;
    }

  }

  return 0;
}