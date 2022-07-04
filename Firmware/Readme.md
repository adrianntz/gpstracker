
# Power Efficient GPS Tracker

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/9/99/Microchip_logo.svg/2560px-Microchip_logo.svg.png)

This is an internship project aiming to build a portable GPS Tracker which sends out its GPS coordinates whenever it detects motion either through SMS or to a website application through power efficient means.

## Code Features

- Easily portable using Microchip MPLAB's Code Configurator (MCC)
- Can add or remove features easily using MCC, the main code being modular and  based on interrupts.



## AVR's Peripherals Used:
- USART
- RTC 
- AC 
- I2C


# Main Code
The system works on two states: A sleep state and a transmission state. The sleep state is a state in which most hardware peripherals are shut down and both processing units(both the AVR microcontroller and SIM808 module) are in sleep mode, thus preserving battery life. The other one, GET_GPS is working at full capacity to send GPS coordinates for a specified number of times.

````


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
````
