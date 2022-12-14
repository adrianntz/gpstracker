/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 1.0.1
*/

/*
? [2022] Microchip Technology Inc. and its subsidiaries.

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

#include "../pins.h"

static void (*PC1_InterruptHandler)(void);
static void (*PC0_InterruptHandler)(void);
static void (*PA1_InterruptHandler)(void);
static void (*PA0_InterruptHandler)(void);
static void (*PD2_InterruptHandler)(void);
static void (*PD6_InterruptHandler)(void);
static void (*PA2_InterruptHandler)(void);
static void (*PA3_InterruptHandler)(void);
static void (*PD3_InterruptHandler)(void);
static void (*PD4_InterruptHandler)(void);
static void (*PD5_InterruptHandler)(void);
static void (*PD7_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{
  /* DIR Registers Initialization */
    PORTA.DIR = 0xD;
    PORTC.DIR = 0x1;
    PORTD.DIR = 0xB8;
    PORTF.DIR = 0x0;

  /* OUT Registers Initialization */
    PORTA.OUT = 0x1;
    PORTC.OUT = 0x1;
    PORTD.OUT = 0x0;
    PORTF.OUT = 0x0;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x8;
    PORTA.PIN3CTRL = 0x8;
    PORTA.PIN4CTRL = 0x0;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x0;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x0;
    PORTC.PIN2CTRL = 0x0;
    PORTC.PIN3CTRL = 0x0;
    PORTC.PIN4CTRL = 0x0;
    PORTC.PIN5CTRL = 0x0;
    PORTC.PIN6CTRL = 0x0;
    PORTC.PIN7CTRL = 0x0;
    PORTD.PIN0CTRL = 0x0;
    PORTD.PIN1CTRL = 0x0;
    PORTD.PIN2CTRL = 0x1;
    PORTD.PIN3CTRL = 0x0;
    PORTD.PIN4CTRL = 0x0;
    PORTD.PIN5CTRL = 0x0;
    PORTD.PIN6CTRL = 0x2;
    PORTD.PIN7CTRL = 0x0;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x0;
    PORTF.PIN3CTRL = 0x0;
    PORTF.PIN4CTRL = 0x0;
    PORTF.PIN5CTRL = 0x0;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;

  /* PORTMUX Initialization */
    PORTMUX.ACROUTEA = 0x0;
    PORTMUX.CCLROUTEA = 0x0;
    PORTMUX.EVSYSROUTEA = 0x0;
    PORTMUX.SPIROUTEA = 0x0;
    PORTMUX.TCAROUTEA = 0x0;
    PORTMUX.TCBROUTEA = 0x0;
    PORTMUX.TCDROUTEA = 0x0;
    PORTMUX.TWIROUTEA = 0x0;
    PORTMUX.USARTROUTEA = 0x0;
    PORTMUX.ZCDROUTEA = 0x0;

  // register default ISC callback functions at runtime; use these methods to register a custom function
    PC1_SetInterruptHandler(PC1_DefaultInterruptHandler);
    PC0_SetInterruptHandler(PC0_DefaultInterruptHandler);
    PA1_SetInterruptHandler(PA1_DefaultInterruptHandler);
    PA0_SetInterruptHandler(PA0_DefaultInterruptHandler);
    PD2_SetInterruptHandler(PD2_DefaultInterruptHandler);
    PD6_SetInterruptHandler(PD6_DefaultInterruptHandler);
    PA2_SetInterruptHandler(PA2_DefaultInterruptHandler);
    PA3_SetInterruptHandler(PA3_DefaultInterruptHandler);
    PD3_SetInterruptHandler(PD3_DefaultInterruptHandler);
    PD4_SetInterruptHandler(PD4_DefaultInterruptHandler);
    PD5_SetInterruptHandler(PD5_DefaultInterruptHandler);
    PD7_SetInterruptHandler(PD7_DefaultInterruptHandler);
}

/**
  Allows selecting an interrupt handler for PC1 at application runtime
*/
void PC1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PC1_InterruptHandler = interruptHandler;
}

void PC1_DefaultInterruptHandler(void)
{
    // add your PC1 interrupt custom code
    // or set custom function using PC1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PC0 at application runtime
*/
void PC0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PC0_InterruptHandler = interruptHandler;
}

void PC0_DefaultInterruptHandler(void)
{
    // add your PC0 interrupt custom code
    // or set custom function using PC0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PA1 at application runtime
*/
void PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PA1_InterruptHandler = interruptHandler;
}

void PA1_DefaultInterruptHandler(void)
{
    // add your PA1 interrupt custom code
    // or set custom function using PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PA0 at application runtime
*/
void PA0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PA0_InterruptHandler = interruptHandler;
}

void PA0_DefaultInterruptHandler(void)
{
    // add your PA0 interrupt custom code
    // or set custom function using PA0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PD2 at application runtime
*/
void PD2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PD2_InterruptHandler = interruptHandler;
}

void PD2_DefaultInterruptHandler(void)
{
    // add your PD2 interrupt custom code
    // or set custom function using PD2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PD6 at application runtime
*/
void PD6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PD6_InterruptHandler = interruptHandler;
}

void PD6_DefaultInterruptHandler(void)
{
    // add your PD6 interrupt custom code
    // or set custom function using PD6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PA2 at application runtime
*/
void PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PA2_InterruptHandler = interruptHandler;
}

void PA2_DefaultInterruptHandler(void)
{
    // add your PA2 interrupt custom code
    // or set custom function using PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PA3 at application runtime
*/
void PA3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PA3_InterruptHandler = interruptHandler;
}

void PA3_DefaultInterruptHandler(void)
{
    // add your PA3 interrupt custom code
    // or set custom function using PA3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PD3 at application runtime
*/
void PD3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PD3_InterruptHandler = interruptHandler;
}

void PD3_DefaultInterruptHandler(void)
{
    // add your PD3 interrupt custom code
    // or set custom function using PD3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PD4 at application runtime
*/
void PD4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PD4_InterruptHandler = interruptHandler;
}

void PD4_DefaultInterruptHandler(void)
{
    // add your PD4 interrupt custom code
    // or set custom function using PD4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PD5 at application runtime
*/
void PD5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PD5_InterruptHandler = interruptHandler;
}

void PD5_DefaultInterruptHandler(void)
{
    // add your PD5 interrupt custom code
    // or set custom function using PD5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PD7 at application runtime
*/
void PD7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PD7_InterruptHandler = interruptHandler;
}

void PD7_DefaultInterruptHandler(void)
{
    // add your PD7 interrupt custom code
    // or set custom function using PD7_SetInterruptHandler()
}
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT1_bm)
    {
       PA1_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT0_bm)
    {
       PA0_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT2_bm)
    {
       PA2_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT3_bm)
    {
       PA3_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT1_bm)
    {
       PC1_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       PC0_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       PD2_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       PD6_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       PD3_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       PD4_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       PD5_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       PD7_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

/**
 End of File
*/