 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include <string.h>
#include "mcc_generated_files/system/system.h"
#include "headers/BMI160_INIT.h"
/*
    Main application
*/
//GPRMC FIELDS DEFINITIONS
#define GPRMC_FIELD_TIME 1
#define GPRMC_FIELD_VALIDITY 2
#define GPRMC_FIELD_LAT 3
#define GPRMC_FIELD_LAT_DIR 4
#define GPRMC_FIELD_LONG 5
#define GPRMC_FIELD_LONG_DIR 6
#define GPRMC_FIELD_SPEED_KNOTS 7
#define GPRMC_FIELD_TRUECOURSE 8
#define GPRMC_FIELD_DATE 9
#define GPRMC_FIELD_MAG_VAR 10
#define GPRMC_FIELD_MAG_VAR_DIR 11
#define GPRMC_FIELD_CHECKSUM 12



#define OUTPUT_BUFFER_SIZE 100
#define NMEA_NO_OF_FIELDS 12
#define GPS_NUMBER_OF_TRANSMISSIONS 5
//SYSTEM STATES DEFINITIONS 
#define HIGH 1
#define LOW 0
#define GET_GPS 0xA
#define SLEEP 0xB

//GLOBAL VARIABLES

char                   USART_DummyBuffer, 
                         GPS_USART0_Buffer[200],
                         Get_GPS_Cnt_String[5],
                         *GPRMC_Fields[12],
                         GPS_Data[OUTPUT_BUFFER_SIZE];

unsigned volatile int
                         GPS_Buffer_Index = 0;

volatile bool           Delay_Flag = false, 
                        GPS_Info_Flag = false, 
                        Movement_Sensor_Status = false;

bool                    do_once_flag = false;
volatile uint8_t        Timer_Cnt= 0;
uint8_t                 receiveData;
uint8_t                 Get_GPS_Cnt = GPS_NUMBER_OF_TRANSMISSIONS;
 
void SET_DTR(bool setting) //Function to set DTR pin HIGH or LOW 
{
  if (setting == 1)
    PORTC.OUTSET= PIN5_bm; //SET DTR HIGH
  if (setting == 0)
    PORTC.OUTCLR=PIN5_bm; //SET DTR LOW
}

void SET_PWKEY(bool setting) //Function to set PWKEY pin HIGH or LOW 
{
  if (setting == 1)
    PORTC.OUTSET= PIN4_bm; //SET PWKEY HIGH
  if (setting == 0)
     PORTC.OUTCLR=PIN4_bm; //SET PWKEY LOW
}


void USART0_Print(const char* string)
{
    char ch;
    while(1)
    {
        ch = (char)*string++;
        if(ch != '\0')
            USART0_Write(ch);
        else
            break;
    }
}


void SIM808_RECIEVE()
{
    if(USART0.RXDATAL=='$')
                GPS_Info_Flag = true;   
    //We signal in the Recieve Interrupt Vector to store the data 
    if (GPS_Info_Flag == true)                               // GPS_Info_Flag atentioneaza sa se stocheze datele in buffer
     {
         GPS_USART0_Buffer[GPS_Buffer_Index++] = USART0.RXDATAL; 
                                                                //buffer pt coordonate GPS
        if (USART0.RXDATAL == '*') //We stop storing the GPS data at the checksum 
        {
          GPS_Info_Flag = false;
          GPS_Buffer_Index = 0;
        }
    } 
    else
        USART_DummyBuffer = USART0.RXDATAL;       //The RXC interrupt flag is cleard only when RXDATAL is read.
     
    USART1_Write(USART0.RXDATAL);
    
    
}
void Motion_Detected()
{
    Movement_Sensor_Status=true;
    PORTC.OUTTGL=PIN6_bm;
}

void GPS_ACQUIRE_TIMESTAMP()
{
    Delay_Flag=true;
}

void CDC_TX()
{
        USART0_Write(USART1.RXDATAL); //CDC_TX este conectat la USART1_RX. Astfel, cand scriem pe terminal,
                                      //o sa fie primit in rxbuffer.
   
                                      
}

char * NMEA_Parse(char *NMEA_Sentence,char *output);
int parse_comma_delimited_str(char* string, char** fields, int max_fields);
void send_sms_message_AT(char * msg) ;
void Sleep_Mode_Init();
void GPS_Coordonates_Send();


int main(void)
{
    SYSTEM_Initialize();
    BMI_160_INIT();
    RTC_SetOVFIsrCallback(GPS_ACQUIRE_TIMESTAMP);
    PD6_SetInterruptHandler(Motion_Detected);
    USART0_RxCompleteCallbackRegister(SIM808_RECIEVE);
    USART1_RxCompleteCallbackRegister(CDC_TX);
    
    uint8_t STATE = SLEEP;
    
    printf(" [CONSOLE] Module Initialized\r\n");
     while (true) 
    {
         
        switch (STATE) 
        {
            case GET_GPS:       GPS_Coordonates_Send();             PORTC.OUTCLR=PIN6_bm;
                break;

            case SLEEP:          Sleep_Mode_Init();               PORTC.OUTSET=PIN6_bm;
                break;

            default:               Sleep_Mode_Init();           PORTC.OUTSET=PIN6_bm;
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
  
  USART0_Print("AT+CMGF=1\r\n");                                                     
  DELAY_milliseconds(300);
  USART0_Print("AT+CMGS=\"+40769297780\"\r\n");
  DELAY_milliseconds(1000);
  
  USART0_Print(msg);
  USART0_Write('\n');
  USART0_Write((char) 26);                          //ASCII code 26 means the CTRL+Z Character which is used to signal the end of the SMS message
}


void Sleep_Mode_Init()
{
     if (do_once_flag == false)                 //These commands need to be sent only once
      {
        USART0_Print("AT+CGPSPWR=0\r\n");
        DELAY_milliseconds(300);
        USART0_Print("AT+CFUN=0\r\n");
        DELAY_milliseconds(300);
        USART0_Print("AT+CSCLK=1\r\n");
        DELAY_milliseconds(300);
        SET_DTR(HIGH);
        do_once_flag = true;
        snprintf(GPS_USART0_Buffer,1,"\0");//clear the gps buffer
      }
      
}

/* Function used to send GPS Coordonates read by the SIM808 Module */
void GPS_Coordonates_Send()
{
    if (Delay_Flag == true)                     //Delay_Flag is toggled once every 30s
      {
        Delay_Flag = false;
        SET_DTR(LOW);
        
        USART0_Print("AT+CFUN=1\r\n");        //Enables Full GSM Functionality
        DELAY_milliseconds(300);
        USART0_Print("AT+CGPSPWR=1\r\n"); //Turn on GPS power
        DELAY_milliseconds(300);
        USART0_Print("AT+CGPSOUT=32\r\n"); // CGPSOUT=2 enables the SIM808 to send GPS data in GPGGA format once every second
        
        DELAY_milliseconds(900);         //We use a 2s delay to recieve at least one full string of data to parse
                                                            
        
        USART0_Print("AT+CGPSOUT=0\r\n");
        //parse_comma_delimited_str(GPS_USART1_Buffer,GPRMC_Fields,NMEA_NO_OF_FIELDS);
       // send_sms_message_AT(SMS_STRING);
        DELAY_milliseconds(100);
        if(strcmp( NMEA_Parse(GPS_USART0_Buffer,GPS_Data),"Invalid\n")!=0)
            send_sms_message_AT(   GPS_Data   );
        /* For Debugging reasons, we print out the GPS counter*/
        printf("\n [CONSOLE] GPS COUNT: %d\n",--Get_GPS_Cnt);
    }
}

int parse_comma_delimited_str(char* string, char** fields, int max_fields)
{
    int i = 0;
    fields[i++] = string;
    while ((i < max_fields) && NULL != (strchr(string, ',')))
    {
        string += strlen(string)-strlen((strchr(string, ',')));
        //string = (strchr(string, ','));   error: assignment from pointer to non-enclosed address space
        *string = '\0';
        fields[i++] = ++string;
    }
    return --i;
}

char * NMEA_Parse(char *NMEA_Sentence,char *output)
{
     
    parse_comma_delimited_str(NMEA_Sentence,GPRMC_Fields,NMEA_NO_OF_FIELDS);
      if (strcmp(GPRMC_Fields[GPRMC_FIELD_VALIDITY], "A") == 0)
    {

        snprintf(output, OUTPUT_BUFFER_SIZE, GPRMC_Fields[GPRMC_FIELD_TIME]);
        strncat(output, ";", 1);
        strncat(output, GPRMC_Fields[GPRMC_FIELD_LAT], strlen(GPRMC_Fields[GPRMC_FIELD_LAT]));
        strncat(output, ";", 1);
        strncat(output, GPRMC_Fields[GPRMC_FIELD_LAT_DIR], strlen(GPRMC_Fields[GPRMC_FIELD_LAT_DIR]));
        strncat(output, ";", 1);
        strncat(output, GPRMC_Fields[GPRMC_FIELD_LONG], strlen(GPRMC_Fields[GPRMC_FIELD_LONG]));
        strncat(output, ";", 1);
        strncat(output, GPRMC_Fields[GPRMC_FIELD_LONG_DIR], strlen(GPRMC_Fields[GPRMC_FIELD_LONG_DIR]));
    }

    else
    {
        snprintf(output, OUTPUT_BUFFER_SIZE, "Invalid\n");
        printf("\n[CONSOLE] INVALID\n");
    }

    return output;
}