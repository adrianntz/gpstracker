/* 
 * File:   GPGGA_Parser.h
 * Author: Neata Adrian 
 *
 * Created on January 26, 2022, 3:16 PM
 */

#ifndef GPGGA_PARSER_H
#define	GPGGA_PARSER_H
#define HIGH 1
#define LOW 0
extern void GPGGAHandler();
extern void errorHandler();
extern void parse(char  data[]);
extern volatile bool NMEA_ERROR;
extern  char SMS_STRING[];



#endif	/* GPGGA_PARSER_H */

