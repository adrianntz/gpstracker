
// INCLUDED SYSTEM HEADERS//
#include <avr/io.h>

#include <avr/interrupt.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

//INCLUDED  INTERNAL HEADERS
#include "NMEAParser.h"

#include "UART_INIT.h"

#include "ConvertToString.h"

#include "GPGGA_Parser.h"

#include "TIMER_INIT.h"

#include "PORT_INIT.h"

#include "ACCEL_BMI160.h"

//Configurable settings

#define GPS_NUMBER_OF_TRANSMISSIONS 3

//SYSTEM STATES DEFINITIONS 
#define GET_GPS 0xA
#define SLEEP 0xB

//GLOBAL VARIABLES

char                  USART_Buffer, 
                         GPS_USART1_Buffer[200],
                         Get_GPS_Cnt_String[5];

unsigned volatile int
                         GPS_Buffer_Index = 0;

volatile bool       Delay_Flag = false, 
                         GPS_Info_Flag = false, 
                         Movement_Sensor_Status = false;

bool                   do_once_flag = false;
volatile uint8_t  Timer_Cnt= 0;
uint8_t              receiveData;
uint8_t              Get_GPS_Cnt = GPS_NUMBER_OF_TRANSMISSIONS;
 



/* USART1 Recieve Interrupt Vector    */
ISR(USART1_RXC_vect)                              
{
                                                               
  if (GPS_Info_Flag == true)                        // GPS_Info_Flag atentioneaza sa se stocheze datele in buffer
  {
    GPS_USART1_Buffer[GPS_Buffer_Index++] = USART1.RXDATAL; 
                                                                //buffer pt coordonate GPS
    if (USART1.RXDATAL == '\r') 
    {
      GPS_Info_Flag = false;
      GPS_Buffer_Index = 0;
    }
  } 
  else
    USART_Buffer = USART1.RXDATAL;       //The RXC interrupt flag is cleard only when RXDATAL is read.
                                                                // We Read this into a dummy buffer to reset the interrupt flag 
}

/* Rising Edge Interrupt on PIN6 on PORTD used for AnyMotion Interrupt INT1 pin for the BMI160*/
ISR(PORTD_PORT_vect) 
{
  PORTD.INTFLAGS |= PIN6_bm;                //clear int_flag for pin6 by writing 1 into 6th bit
  Movement_Sensor_Status = true;
}


/* Timer Interrupt Vector Which will flag whenever 30 seconds have passed.
 We will send GPS coordinates every 30 seconds in order to save battery power */
ISR(TCA0_OVF_vect)
{
  TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm; // clear flag
  if (Timer_Cnt++ == 3)                             //After three overflows of the timer, we have 30 seconds 
  {
    Delay_Flag = true;
    Timer_Cnt= 0;
  }
}




void send_sms_message_AT(char * msg) ;

void SYSTEM_INIT();

void Sleep_Mode_Init();

void GPS_Coordonates_Send();



int main() 
{
  SYSTEM_INIT();
  sei();                                                    //Enable Global Interrupts
  uint8_t STATE = SLEEP;
  Uart_Print("Module Initialized\r\n");
  
  while (true) 
  {
    switch (STATE) 
    {
    case GET_GPS:     GPS_Coordonates_Send();   PORTC.OUTCLR=PIN6_bm;
        break;
      
    case SLEEP:          Sleep_Mode_Init();              PORTC.OUTSET=PIN6_bm;
        break;
      
    default:                 Sleep_Mode_Init();              PORTC.OUTSET=PIN6_bm;
        break;
    }

    /*
     * If the BMI160 sensor detects motion, we send GPS information 10 times, once every 30 seconds
     * We change the functioning state to GET_GPS.
     */
    if (Movement_Sensor_Status == true) 
    {
      STATE = GET_GPS;
      Movement_Sensor_Status = false;
    }

    /*
     * After we send the GPS information 10 times, we initiate sleep mode, thus changing the functioning state
     */
    if (Get_GPS_Cnt == 0)                      
    {
      Get_GPS_Cnt = GPS_NUMBER_OF_TRANSMISSIONS;                         //Reset the GPS counter
      STATE = SLEEP;
      do_once_flag = false;                     //The Sleep Commands must be used now
    }

  }

  return 0;
}


/* Function to send any string through the SIM808 SMS Functionality using AT Commands*/
void send_sms_message_AT(char * msg) 
{
  
  Uart_Print("AT+CMGF=1\r\n");
  Delay_Timer(arg_ms(100));
  Uart_Print("AT+CMGS=\"+40769297780\"\r\n");
  Delay_Timer(arg_ms(100));
  
  Uart_Print(msg);
  Uart_Send('\n');
  Uart_Send((char) 26);                          //ASCII code 26 means the CTRL+Z Character which is used to signal the end of the SMS message
}

void SYSTEM_INIT()
{
    PORT_INIT();
    USART1_INIT();
    TIMER_INIT();
    BMI_160_INIT();
}

void Sleep_Mode_Init()
{
     if (do_once_flag == false)                 //These commands need to be sent only once
      {
        Uart_Print("AT+CGPSPWR=0\r\n");
        Delay_Timer(arg_ms(50));
      //Uart_Print("AT+CFUN=0\r\n");
        Delay_Timer(arg_ms(50));
        //Uart_Print("AT+CSCLK=1\r\n");
        Delay_Timer(arg_ms(50));
        SET_DTR(HIGH);
        do_once_flag = true;
      }
      
}

/* Function used to send GPS Coordonates read by the SIM808 Module */
void GPS_Coordonates_Send()
{
    if (Delay_Flag == true)                     //Delay_Flag is toggled once every 30s
      {
        Delay_Flag = false;
        SET_DTR(LOW);
        
        Uart_Print("AT+CFUN=1\r\n");        //Enables Full GSM Functionality
        Delay_Timer(arg_ms(30));
        Uart_Print("AT+CGPSPWR=1\r\n"); //Turn on GPS power
        Delay_Timer(arg_ms(500));
        Uart_Print("AT+CGPSOUT=2\r\n"); // CGPSOUT=2 enables the SIM808 to send GPS data in GPGGA format once every second
        
        GPS_Info_Flag = true;                    //We signal in the Recieve Interrupt Vector to store the data 
        Delay_Timer(arg_ms(2000));          //We use a 2s delay to recieve at least one full string of data to parse
                                                            
        
        Uart_Print("AT+CGPSOUT=0\r\n");
        parse(GPS_USART1_Buffer);
        send_sms_message_AT(SMS_STRING);
        
        /* For Debugging reasons, we print out the GPS counter*/
        intToStr(Get_GPS_Cnt--, Get_GPS_Cnt_String,1);
        Uart_Print("GPS_CNT: ");
        Uart_Print(Get_GPS_Cnt_String);
        Uart_Print("\n");
    }
}