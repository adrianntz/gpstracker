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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mcc_generated_files/system/system.h"
#include "headers/BMI160_INIT.h"
#include "headers/i2c.h"
#include "avr/sleep.h"
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
#define GPS_NUMBER_OF_TRANSMISSIONS 20   
//SYSTEM STATES DEFINITIONS 
#define HIGH 1
#define LOW 0
#define GET_GPS 0xA
#define SLEEP 0xB
#define VBUS (PORTD.IN & PIN2_bm)

//GLOBAL VARIABLES

char                     USART_DummyBuffer, 
                         GPS_USART0_Buffer[200],
                         GPS_USART0_Buffer_Bat_Lvl[50],
                         Get_GPS_Cnt_String[5],
                         *GPRMC_Fields[NMEA_NO_OF_FIELDS],
                         *Bat_Check_Fields[3],
                         GPS_Validity[OUTPUT_BUFFER_SIZE],
                         BAT_LVL_STR[3];
 const char              Website_URL[]="http://35.159.50.103/dashboard/gpsdata.php?";

unsigned volatile int
                            GPS_Buffer_Index = 0,
                            GPS_Buffer_Bat_Index=0;

volatile bool               Delay_Flag = false, 
                            GPS_Info_Flag = false, 
                            Movement_Sensor_Status = false,
                            VBUS_Flag=false,
                            USART_Control_Print_once=false,
                            VBUS_Change_Flag=true,
                            GPS_SMS_SENT=false,
                            PWR_UP_FLG=false,
                            BAT_LVL_Begin_Flg=false,
                            BAT_LVL_Check_Flag=false,
                            BAT_LVL_Check_Flag_Is_Done=false;

bool                        do_once_flag = false,
                            charge_do_once=false;
volatile uint8_t            Timer_Cnt= 0,
                            Bat_Lvl_Prct=0;


uint8_t                     receiveData;
uint8_t                     Get_GPS_Cnt = GPS_NUMBER_OF_TRANSMISSIONS;

 struct DecimalCoordinates
 {
    char Lng_DecMin[10];
    char Lat_DecMin[10];
    char Lng_Dir_DecMin[2];
    char Lat_Dir_DecMin[2];
}DecimalDegrees_and_Minutes;

volatile struct DecimalCoordinates Coordinates;

void SIM808_POWER_ONOFF();
void Led_Blink();
void SET_DTR(bool setting);
void SET_PWKEY(bool setting);
void SET_RST(bool setting);
void USART0_Print(const char* string);
void SIM808_RECIEVE();
void Motion_Detected();
void GPS_ACQUIRE_TIMESTAMP();
void CDC_TX();
void VBUS_Detect();
void VBUS_Check();
char * NMEA_Parse(char *NMEA_Sentence,char *output);
int parse_comma_delimited_str(char* string, char** fields, int max_fields);
void send_sms_message_AT(char * msg) ;
void Sleep_Mode_Init();
void GPS_Coordonates_Send();
char *Battery_Check(char* string, char** fields);
void send_lat_and_long_gprs(char lat_param[],
                            char lat_dir_param[], 
                            char lng_param[],
                            char lng_dir_param[],
                            char bat_lvl[]);

int main(void)
{
    SYSTEM_Initialize();
    BMI_160_INIT();
    RTC_SetOVFIsrCallback(GPS_ACQUIRE_TIMESTAMP);
    TCA0_OverflowCallbackRegister(Led_Blink);
    PD6_SetInterruptHandler(Motion_Detected);
    PD2_SetInterruptHandler(VBUS_Detect);
    USART0_RxCompleteCallbackRegister(SIM808_RECIEVE);
    USART1_RxCompleteCallbackRegister(CDC_TX);
    I2C_0_Disable();
    SET_RST(true);
    SET_DTR(false);
    SIM808_POWER_ONOFF();
    TCA0.SINGLE.CTRLA &= ~0x1; //shut off TCA0
    
    uint8_t STATE = GET_GPS;
    
    printf("[CONSOLE] Module Initialized\r\n");
    
                              
    if(VBUS==PIN2_bm)        //We check for the first time when the device turns on 
        VBUS_Flag=true;      //if the USB is plugged in or not. After that, everytime there is a change
    else                    //(rising or falling) on the VBUS connected pin, we change the state
        VBUS_Flag=false;
    
    
     while (true) 
    {
         if(VBUS_Change_Flag==true)
         {
             VBUS_Check();
             VBUS_Change_Flag=false;
         }
         
         
        switch (STATE) 
        {
            case GET_GPS:     
                
                TCA0.SINGLE.CTRLA |= 0x01; //turn on TCA0
                TCA0.SINGLE.CNT=0; //reset counter
                GPS_Coordonates_Send();             
                PORTD.OUTCLR=PIN7_bm;
                TCA0.SINGLE.CTRLA &=  ~0x01; //turn off TCA0
                break;

            case SLEEP:          
                
                PORTD.OUTCLR=PIN7_bm;
                Sleep_Mode_Init();
                break;

            default:        
                
                PORTD.OUTCLR=PIN7_bm;
                Sleep_Mode_Init();
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
          
          if(VBUS_Flag==true)
            printf("[CONSOLE] Movement Detected\r\n");
        }

        /*
         * After we send the GPS information 10 times, we initiate sleep mode, thus changing the functioning state
         */
        if (Get_GPS_Cnt == 0)                      
        {
          Get_GPS_Cnt = GPS_NUMBER_OF_TRANSMISSIONS;                         //Reset the GPS counter
          STATE=SLEEP;
          do_once_flag = false;                                              //The Sleep Commands must be used now
        }
       
       
    }

  return 0;
}

void Led_Blink()
{
    PORTD.OUTTGL=PIN7_bm;
}

void SET_DTR(bool setting) //Function to set DTR pin HIGH or LOW 
{
  if (setting == true)
    PORTD.OUTSET= PIN5_bm; //SET DTR HIGH
  if (setting == false)
    PORTD.OUTCLR=PIN5_bm; //SET DTR LOW
}

void SET_PWKEY(bool setting) //Function to set PWKEY pin HIGH or LOW 
{
  if (setting == true)
    PORTD.OUTSET= PIN4_bm; //SET PWKEY HIGH
  if (setting == false)
    PORTD.OUTCLR=PIN4_bm; //SET PWKEY LOW
}

void SET_RST(bool setting) //Function to set RST pin HIGH or LOW 
{
  if (setting == true)
    PORTD.OUTSET= PIN3_bm; //SET RST HIGH
  if (setting == false)
    PORTD.OUTCLR=PIN3_bm; //SET RST LOW
}

void SIM808_POWER_ONOFF()
{
    SET_PWKEY(HIGH);
    DELAY_milliseconds(1500);
    SET_PWKEY(LOW);
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
    char rxdata=USART0.RXDATAL;
    
    if(rxdata=='$')
        GPS_Info_Flag = true; 
    
    if(rxdata==':' && BAT_LVL_Begin_Flg==true)
        BAT_LVL_Check_Flag=true;
    
    //We signal in the Recieve Interrupt Vector to store the data 
    if (GPS_Info_Flag == true)                               // GPS_Info_Flag warns to store GPS data in the USART buffer
    {
         GPS_USART0_Buffer[GPS_Buffer_Index++] = rxdata; 
                                                                
        if (rxdata == '*') //We stop storing the GPS data at the checksum 
        {
          GPS_Info_Flag = false;
          GPS_Buffer_Index = 0;
        }
    }
    
    if(BAT_LVL_Check_Flag==true && BAT_LVL_Begin_Flg==true)
        {
            GPS_USART0_Buffer_Bat_Lvl[GPS_Buffer_Bat_Index++] = rxdata;
            if(rxdata=='K')
            {
                BAT_LVL_Check_Flag=false;
                GPS_Buffer_Bat_Index=0;
                BAT_LVL_Check_Flag_Is_Done=true;
            }
        }
        
    USART_DummyBuffer = rxdata;       //The RXC interrupt flag is cleard only when RXDATAL is read.
     
    USART1_Write(rxdata);
    
    
}
void Motion_Detected()
{
    Movement_Sensor_Status=true;
    
}

void VBUS_Detect()
{
    VBUS_Change_Flag=true;
    VBUS_Flag=!VBUS_Flag;
    USART_Control_Print_once=false;
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

void VBUS_Check()
{
    if(VBUS_Flag==true)
        {
        
            USART1_Enable();
            PORTC.DIR|=PIN0_bm;//Apparently, disabling USART modules also reset the PIN's output status. We have to reset it.
            if(USART_Control_Print_once==false)
            {
                printf("[CONSOLE] USART1 Enabled\r\n");
                USART0_Print("AT+ECHARGE=1\r\n");
                USART_Control_Print_once=true;
            }
            
        }
        else
        {
            if(USART_Control_Print_once==false)
            {
                printf("[CONSOLE] USART1 Disabled\r\n");
                USART0_Print("AT+ECHARGE=0\r\n");
                USART_Control_Print_once=true;
            }
          
             DELAY_milliseconds(100);   
             USART1_Disable();
        }
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

void send_lat_and_long_gprs(char lat_param[],
                            char lat_dir_param[], 
                            char lng_param[],
                            char lng_dir_param[],
                            char bat_lvl[])
{
    USART0_Print("AT+CGATT=1\r\n");                                                     
    DELAY_milliseconds(300);
     USART0_Print("AT+SAPBR=3,1,\"Contype\",\"GPRS\"\r\n");                                                     
    DELAY_milliseconds(300);
     USART0_Print("AT+SAPBR=3,1,\"APN\",\"live.vodafone.com\"\r\n");                                                     
    DELAY_milliseconds(300);
     USART0_Print("AT+SAPBR=1,1\r\n");                                                     
    DELAY_milliseconds(300);
     USART0_Print("AT+SAPBR=2,1\r\n");                                                     
    DELAY_milliseconds(300);
     USART0_Print("AT+HTTPINIT\r\n");                                                     
    DELAY_milliseconds(300);
     USART0_Print("AT+HTTPPARA=\"CID\",1\r\n");                                  
    DELAY_milliseconds(300);
    USART0_Print("AT+HTTPPARA=\"URL\",\"");   
    USART0_Print(Website_URL);
    USART0_Print("lat="); USART0_Print(lat_param);
    USART0_Print("&lat_dir="); USART0_Print(lat_dir_param);
    USART0_Print("&lng="); USART0_Print(lng_param);
    USART0_Print("&lng_dir="); USART0_Print(lng_dir_param);
    USART0_Print("&bat="); USART0_Print(bat_lvl);
    USART0_Print("\"\r\n");
    DELAY_milliseconds(600);
    USART0_Print("AT+HTTPACTION=1\r\n");
    DELAY_milliseconds(300);
    USART0_Print("AT+HTTPTERM\r\n");
    DELAY_milliseconds(300);
    USART0_Print("AT+CIPSHUT\r\n");
    DELAY_milliseconds(300);
}

void Sleep_Mode_Init()
{
     if (do_once_flag == false)                 //These commands need to be sent only once
      {
         PWR_UP_FLG=false;
         if(VBUS_Flag==false)
         {
            USART0_Print("AT+CNETLIGHT=0\r\n");
            DELAY_milliseconds(100);
            USART0_Print("AT+CGPSPWR=0\r\n");
            DELAY_milliseconds(100);
            USART0_Print("AT+CFUN=0\r\n");
            DELAY_milliseconds(100);
            USART0_Print("AT+CSCLK=1\r\n");
            DELAY_milliseconds(100);
            SET_DTR(HIGH);
            USART0_Print("AT+CPOWD=1\r\n");
            SIM808_POWER_ONOFF();
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_mode();
         }
         else
         {
            USART0_Print("AT+CNETLIGHT=0\r\n");
            DELAY_milliseconds(100); 
            USART0_Print("AT+CGPSPWR=0\r\n");
            DELAY_milliseconds(100);
            USART0_Print("AT+CFUN=4\r\n");
            DELAY_milliseconds(100);
            USART0_Print("AT+CSCLK=1\r\n");
            DELAY_milliseconds(100);
            SET_DTR(HIGH);  
         }
             
        do_once_flag = true;
        GPS_USART0_Buffer[0]=0;         //clear buffer
        GPS_USART0_Buffer_Bat_Lvl[0]=0;
        
      }
      
}



/* Function used to send GPS Coordonates read by the SIM808 Module */
void GPS_Coordonates_Send()
{
    if (Delay_Flag == true)                     //Delay_Flag is toggled once every 15s
      {
        USART0_Print("AT+CNETLIGHT=1\r\n");
        DELAY_milliseconds(50);
        Delay_Flag = false;
        SET_DTR(LOW);
        
        if(PWR_UP_FLG==false && VBUS_Flag==false)
        {
            SIM808_POWER_ONOFF();
            PWR_UP_FLG=true;
        } 
         
        USART0_Print("AT+CFUN=1\r\n");        //Enables Full GSM Functionality
        DELAY_milliseconds(500);
        
        BAT_LVL_Begin_Flg=true;
        USART0_Print("AT+CBC\r\n");
        DELAY_milliseconds(100);
        if(BAT_LVL_Check_Flag_Is_Done==true)
          parse_comma_delimited_str(GPS_USART0_Buffer_Bat_Lvl,Bat_Check_Fields,3);
        BAT_LVL_Begin_Flg=false;
        
        DELAY_milliseconds(100);
        USART0_Print("AT+CGPSPWR=1\r\n"); //Turn on GPS power
        DELAY_milliseconds(300);
        USART0_Print("AT+CGPSOUT=32\r\n"); // CGPSOUT=32 enables the SIM808 to send GPS data in GPRMC  format once every second
        
        DELAY_milliseconds(900);         //We use a 2s delay to recieve at least one full string of data to parse
                                                            
        
        USART0_Print("AT+CGPSOUT=0\r\n");
        
        //parse_comma_delimited_str(GPS_USART1_Buffer,GPRMC_Fields,NMEA_NO_OF_FIELDS);
       // send_sms_message_AT(SMS_STRING);
        DELAY_milliseconds(100);
        
            
        if(strcmp( NMEA_Parse(GPS_USART0_Buffer,GPS_Validity),"Invalid\n")!=0)
        {
           
            send_lat_and_long_gprs(DecimalDegrees_and_Minutes.Lat_DecMin,
                                   DecimalDegrees_and_Minutes.Lat_Dir_DecMin,
                                   DecimalDegrees_and_Minutes.Lng_DecMin,
                                   DecimalDegrees_and_Minutes.Lng_Dir_DecMin,
                                   Bat_Check_Fields[1]);
        }
        DELAY_milliseconds(500);
        /* For Debugging reasons, we print out the GPS counter*/
        if(VBUS_Flag==true)
            printf("[CONSOLE] GPS COUNT: %d\n\r",--Get_GPS_Cnt);
        else
            Get_GPS_Cnt--;
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
          if(GPS_SMS_SENT==false)
          {
              send_sms_message_AT("VALID GPS SIGNAL\n");
              GPS_SMS_SENT=true;
          }
            snprintf(output, OUTPUT_BUFFER_SIZE, "Valid\n");
            snprintf(DecimalDegrees_and_Minutes.Lat_DecMin, 10, GPRMC_Fields[GPRMC_FIELD_LAT]);
            snprintf(DecimalDegrees_and_Minutes.Lng_DecMin, 10, GPRMC_Fields[GPRMC_FIELD_LONG]);
            snprintf(DecimalDegrees_and_Minutes.Lat_Dir_DecMin, 2, GPRMC_Fields[GPRMC_FIELD_LAT_DIR]);
            snprintf(DecimalDegrees_and_Minutes.Lng_Dir_DecMin, 2, GPRMC_Fields[GPRMC_FIELD_LONG_DIR]);
           
      }
    else
        {
            snprintf(output, OUTPUT_BUFFER_SIZE, "Invalid\n");
            if(VBUS_Flag==true)
                 printf("[CONSOLE] INVALID\n\r");
        }

    return output;
}