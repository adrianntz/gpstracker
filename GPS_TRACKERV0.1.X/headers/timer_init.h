/* 
 * File:   newfile.h
 * Author: adyco
 *
 * Created on January 28, 2022, 8:55 AM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#define F_CLK_TIMER 4000
#define arg_ms(x) (((x)/1000.0)*(F_CLK_TIMER)-1)

void delay_timer(uint16_t per);
void timer_init(void);
#endif	/* NEWFILE_H */

