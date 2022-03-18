#include <string.h>
#include "NMEAParser.h"
#include"uart_initialization.h"

void secondHandler()
{
    
    uart_print("Got $GPPGA with ");
   // uart_print(parser.argCount());
   // uart_print(" arguments\n");
    
    float arg0;
    float arg1;
    char arg2;
    float arg3;
    char arg4;
    int arg5;
    int arg6;
    float arg7;
    float arg8;
    char arg9;
    float arg10;
    char arg11;
    
    if (parser.getArg(0, arg0)) 
    {
       uart_print( "Time:(hhmmss) "+to_string(arg0)); 
       uart_print("\n\r");
    }
    if (parser.getArg(1, arg1)){
        uart_print("Latitude (ddmm.mmm): "+to_string(arg1)); 
        uart_print("\n\r");
    }
    if (parser.getArg(2, arg2)){
        uart_print("N/S: "); 
        uart_send(arg2);
        uart_print("\n\r");
    }
    
    if (parser.getArg(3, arg3)) {
        uart_print("Longitude (ddmm.mmm):"+to_string(arg3));
        uart_print("\n\r");
    }
    if (parser.getArg(4, arg4)) 
    {
        uart_print("E/W Indicator: ");
        uart_send(arg4); 
        uart_print("\n\r");
    }
    if (parser.getArg(5, arg5)){
        uart_print("Position fix indicator: "+to_string(arg5)); 
        uart_print("\n\r");
    }
    if (parser.getArg(6, arg6)){ 
        uart_print("Satellites used: "+to_string(arg6)); 
        uart_print("\n\r");
    }
    if (parser.getArg(7, arg7)){
        uart_print("HDOP: "+to_string(arg7));
        uart_print("\n\r");
    }
    if (parser.getArg(8, arg8)) {
        uart_print("MSL altitude: "+to_string(arg8)); 
        uart_print("\n\r");
    }
    if (parser.getArg(9, arg9)) {
        uart_print("Units (metres)");
        uart_send(arg9);
        uart_print("\n\r");
    }
    if (parser.getArg(10, arg10)) {
        uart_print("Geoid Separation: "+to_string(arg10)); 
        uart_print("\n\r");
    }
    
    if (parser.getArg(11, arg11)) {
        uart_print(" Units (metres)");
        uart_send(arg11);
        uart_print("\n\r");
    }

    
  
}