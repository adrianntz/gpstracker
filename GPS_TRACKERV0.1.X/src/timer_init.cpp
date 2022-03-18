#include <avr/io.h>

void delay_timer(uint16_t per) {
  TCA1.SINGLE.CTRLA = (7 << TCA_SINGLE_CLKSEL_gp); // 4MHz/1024
  TCA1.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm; //resetam registrul de overflow
  TCA1.SINGLE.PER = per; // assume 4MHz default clock
  TCA1.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm; // start the timer
  TCA1.SINGLE.CNT = 0; //dam clear la cnt
  while (!(TCA1.SINGLE.INTFLAGS & TCA_SINGLE_OVF_bm)); //asteptam pana cand avem overflow
  TCA1.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm; //resetma registrul de overflow

}

void timer_init(void) {
  TCA0.SINGLE.CNT = 0;
  TCA0.SINGLE.PER = 3999; // timeout is 10 seconds , PER=OverFlowPeriod[s] * FreqTimer[Hz]-1, a.k.a 10*4000-1
  TCA0.SINGLE.CTRLA = (7 << TCA_SINGLE_CLKSEL_gp); // FreqTimer=4MHz/1024~4kHz
  TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
  TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
  TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm; // start timer
}