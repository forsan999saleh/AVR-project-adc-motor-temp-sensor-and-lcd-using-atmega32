

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#include "../DIO/DIO_int.h"
#include "../INTERRUPT/external interrupts/external interrupts initilalizations.h"
#include "../INTERRUPT/general interrupts/Initialization.h"
void tmr0_set_overflow_callback(void(*locpfunc)(void));
void tmr0_set_ocm_callback(void(*locpfunc)(void));
void tmr0_initialization(void);
void tmr0_enable_overflow_interrupt(void);
void tmr0_enable_ocm_interrupt(void);
void tmr0_set_counter(u8 value_of_TCNT0);
void tmr0_set_cm(u8 value_of_OCR0);
void tmr0_set_duty_cycle(u8 duty_cycle);

#endif /* TIMER_INTERFACE_H_ */