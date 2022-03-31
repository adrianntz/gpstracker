# Power Efficient GPS Tracker
This is an internship project aiming to build a portable GPS Tracker which sends out its GPS coordinates whenever it detects motion either through SMS or to a website application through power efficient means.
## Changelog
-  `1.0`  : Initial release

## Features

- Portable and lightweight hardware design
- Long-lasting battery life with easy USB Charging
- User-Friendly web-hosted application with Google Maps integration🌍


## Hardware Modules Used

A number of hardware modules were used in order to create this project

-  [SIM808 | SIMCom ](https://simcom.ee/modules/gsm-gprs-gnss/sim808/) - GSM and GPS module used for GPS tracking and mobile communication
- [Inertial Measurement Unit BMI160 | Bosch Sensortec ](https://www.bosch-sensortec.com/products/motion-sensors/imus/bmi160/) - Power efficient accelerometer used to detect sudden motion.
- [MCHP AVR128DA48 Microcontroller](https://www.microchip.com/en-us/product/AVR128DA48/) - AVR architecture based microcontroller used for main processing and coordination of the GPS tracker.

## Usage

The GPS tracker can be turned on by switching the main switch on the casing. A Green LED will flash twice on power up, letting the user know the module is fully functional.

A lithium-ion battery is inside the casing that can be easily swapped if needed for a bigger one. The module can be charged through the USB port. A red led will turn on near the port which will turn yellow when it is 50% charged and then green when it is 100% charged.

The GPS antenna must be outdoors in order for it to function properly

The device has a SIM card slot which can be accessed by the user with a simple SIM-pin. The SIM card must be linked with a functional account tied  to a GSM carrier (Vodafone/Orange/Telekom/Digi etc.) .

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
