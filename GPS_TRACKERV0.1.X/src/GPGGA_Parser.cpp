#include <stdint.h>

#include <string.h>

#include "NMEAParser.h"

#include "ConvertToString.h"

#include "uart_initialization.h"


struct gpgga {
  float TIME;
  float LAT;
  char LAT_DIR;
  float LONG;
  char LONG_DIR;
  /*
  int POS_INDICATOR;
  int SATTELITES_USED;
  float HDOP;
  float MSL_ALT;
  char MSL_ALT_UNIT;
  float GEOID_SEP;
  char GEOID_SEP_UNIT;
   */
};

NMEAParser < 2 > parser;
volatile bool NMEA_ERROR = false;
char SMS_STRING[130];

void errorHandler() {
  //  uart_print("*** Error : \n\r");
  NMEA_ERROR = true;
  //uart_print(parser.error());
}

void GPGGAHandler() {
  NMEA_ERROR = false;
  //  uart_print("Got $GPPGA with ");
  // uart_print(parser.argCount());
  // uart_print(" arguments\n");

  gpgga GPGGA;

  char passer[30];
  strcpy(SMS_STRING, "");
  if (parser.getArg(0, GPGGA.TIME)) {
    strcat(SMS_STRING, " Time:(hhmmss) ");
    floatToStr(GPGGA.TIME, passer, 3);
    strcat(SMS_STRING, passer);
    strcat(SMS_STRING, "\n\r");

  }

  if (parser.getArg(1, GPGGA.LAT)) {
    strcat(SMS_STRING, "Latitude (ddmm.mmm): ");
    floatToStr(GPGGA.LAT, passer, 3);
    strcat(SMS_STRING, passer);
    strcat(SMS_STRING, "\n\r");

  }
  if (parser.getArg(2, GPGGA.LAT_DIR)) {
    strcat(SMS_STRING, "N/S: ");
    char cToStr[2];
    cToStr[1] = '\0';
    cToStr[0] = GPGGA.LAT_DIR;
    strcat(SMS_STRING, cToStr);
    strcat(SMS_STRING, " \n\r");

  }

  if (parser.getArg(3, GPGGA.LONG)) {
    strcat(SMS_STRING, "Longitude (ddmm.mmm):");
    floatToStr(GPGGA.LONG, passer, 3);
    strcat(SMS_STRING, passer);
    strcat(SMS_STRING, "\n\r");

  }
  if (parser.getArg(4, GPGGA.LONG_DIR)) {
    strcat(SMS_STRING, "E/W Indicator: ");
    char cToStr[2];
    cToStr[1] = '\0';
    cToStr[0] = GPGGA.LONG_DIR;
    strcat(SMS_STRING, cToStr);
    strcat(SMS_STRING, "\n\r");

  }

  /* 
  if (parser.getArg(5, GPGGA.POS_INDICATOR)) {
      strcat(SMS_STRING, "Position fix indicator: ");
      floatToStr(GPGGA.POS_INDICATOR, passer, 3);
      strcat(SMS_STRING, passer);
      strcat(SMS_STRING, "\n\r");
      
  }
  if (parser.getArg(6, GPGGA.SATTELITES_USED)) {
      strcat(SMS_STRING, "Satellites used: ");
      floatToStr(GPGGA.SATTELITES_USED, passer, 3);
      strcat(SMS_STRING, passer);
      strcat(SMS_STRING, "\n\r");
      
  }
  if (parser.getArg(7, GPGGA.HDOP)) {
      strcat(SMS_STRING, "HDOP: ");
      floatToStr(GPGGA.HDOP, passer, 3);
      strcat(SMS_STRING, passer);
      strcat(SMS_STRING, "\n\r");
      
  }
  if (parser.getArg(8, GPGGA.MSL_ALT)) {
      strcat(SMS_STRING, "MSL altitude: ");
      floatToStr(GPGGA.MSL_ALT, passer, 3);
      strcat(SMS_STRING, passer);
      strcat(SMS_STRING, "\n\r");
      
  }
  if (parser.getArg(9, GPGGA.MSL_ALT_UNIT)) {
      strcat(SMS_STRING, "Units (meters): ");
      char cToStr[2];
      cToStr[1] = '\0'; cToStr[0] = GPGGA.MSL_ALT_UNIT;
      strcat(SMS_STRING, cToStr);
      strcat(SMS_STRING, " \n\r");
      
  }
  if (parser.getArg(10, GPGGA.GEOID_SEP)) {
      strcat(SMS_STRING, "Geoid Separation: ");
      floatToStr(GPGGA.GEOID_SEP, passer, 3);
      strcat(SMS_STRING, passer);
      strcat(SMS_STRING, "\n\r");
      
  }

  if (parser.getArg(11, GPGGA.GEOID_SEP_UNIT)) {
      strcat(SMS_STRING, " Units (meters)");
      char cToStr[2];
      cToStr[1] = '\0'; cToStr[0] = GPGGA.GEOID_SEP_UNIT;
      strcat(SMS_STRING, cToStr);
      strcat(SMS_STRING, " \n\r");
      
  }
  */

}

void parse(char data[]) {

  //  uart_print("Parse begin\n");
  parser.setErrorHandler(errorHandler);
  // parser.addHandler("DBAXK", firstHandler);
  parser.addHandler("GPGGA", GPGGAHandler);

  /* uart_print("Parsing : ");
   uart_print(firstSentence);
   
   for (uint8_t i = 0; i < strlen(firstSentence); i++) {
       parser << firstSentence[i];
   }
   */
  //  uart_print("Parsing : ");
  //  uart_print(data);

  for (uint32_t i = 0; i < strlen(data); i++) {
    parser << data[i];
  }
}