/*
 * external_interrupts_initilalizations.h
 *
 * Created: 12/9/2023 4:44:24 PM
 *  Author: EECE
 */ 


#ifndef EXTERNAL INTERRUPTS INITILALIZATIONS_H_
#define EXTERNAL INTERRUPTS INITILALIZATIONS_H_
#include <avr/interrupt.h>
#include "private external interrupts.h"
#include "../../../Library/BIT_MATH.h"
#include "../../../Library/TYPES.h"
#define external_interrupt0 0
#define external_interrupt1 1
#define external_interrupt2 2
#define external_interrupt_low_level 0
#define external_interrupt_on_change 1
#define external_interrupt_falling 2
#define external_interrupt_rising  3
void external_interrupt_enable(u8 line);
void external_interrupt_disable(u8 line);
void external_interrupt_sense_control(u8 line ,u8 mode);

#endif /* EXTERNAL INTERRUPTS INITILALIZATIONS_H_ */