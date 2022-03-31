#include <avr/io.h>
#define PERIODIC_INTERRUPT_INTERVAL_sec 1 


uint16_t per_interr=PERIODIC_INTERRUPT_INTERVAL_sec*4000-1;
void Delay_Timer(uint16_t per)  //Timer TCA1 set up to delay the CPU for an x amount of time, amount of time being offered by the per argument
{
  TCA1.SINGLE.CTRLA = (7 << TCA_SINGLE_CLKSEL_gp); // Timer Clock set to F_CPU divided by 1024 => F_Timer= 4MHz/1024
  TCA1.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm; //Overflow Register Reset
  TCA1.SINGLE.PER = per; // assuming 4MHz default clock, per is the calculated register value for the delay in ms desired
  TCA1.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm; // start the timer
  TCA1.SINGLE.CNT = 0; //Clear CNT register
  while (!(TCA1.SINGLE.INTFLAGS & TCA_SINGLE_OVF_bm)); //Wait for overflow
  TCA1.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm; //Reset Overflow Register

}

void TIMER_INIT(void)//Timer TCA0 set up to offer periodic interrupt every 10 seconds
{
  TCA0.SINGLE.CNT = 0;
  TCA0.SINGLE.PER = per_interr; // timeout is 10 seconds , PER=OverFlowPeriod[s] * FreqTimer[Hz]-1, a.k.a 10*4000-1
  TCA0.SINGLE.CTRLA = (7 << TCA_SINGLE_CLKSEL_gp); //  Timer Clock set to F_CPU divided by 1024 => F_Timer= 4MHz/1024
  TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;//Overflow Register Reset
  TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm; //Set interrupt mode when overflow is reached
  TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm; // start timer
}