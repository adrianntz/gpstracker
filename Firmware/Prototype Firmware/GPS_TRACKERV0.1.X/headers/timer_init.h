/* 
 * File:   newfile.h
 * Author: Neata Adrian 
 *
 * Created on January 28, 2022, 8:55 AM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#define F_CLK_TIMER 4000
#define arg_ms(x) (((x)/1000.0)*(F_CLK_TIMER)-1)

void Delay_Timer(uint16_t per);
void TIMER_INIT(void);
#endif	/* NEWFILE_H */

