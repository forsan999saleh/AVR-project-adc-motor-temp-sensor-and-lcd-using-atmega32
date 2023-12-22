
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#include "../DIO/DIO_int.h"
#define F_CPU 8000000ul

#include "../INTERRUPT/Interupt_interface.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"
/*global pointer to functions*/
void (*timer0_ptr_to_func_ovf)(void)=NULL;
void (*timer0_ptr_to_func_ocm)(void)=NULL;
void tmr0_set_overflow_callback(void(*locpfunc)(void))
{
	timer0_ptr_to_func_ovf=locpfunc;
}
void tmr0_set_ocm_callback(void(*locpfunc)(void))
{
	timer0_ptr_to_func_ocm=locpfunc;
}
ISR  (TIMER0_OVF_vect)
{
	if(timer0_ptr_to_func_ovf!=NULL)
	{
		timer0_ptr_to_func_ovf();
	}
}

ISR  (TIMER0_COMP_vect)
{
	if(*timer0_ptr_to_func_ocm !=NULL)
	{
		timer0_ptr_to_func_ocm();
	}
}
void tmr0_initialization(void)
{
	#if timer_mode==normal
	CLR_BIT(TCCR0 ,WGM00);
	CLR_BIT(TCCR0 ,WGM01);
	#elif timer_mode==pwm_phase_correct
	SET_BIT(TCCR0 ,WGM00);
	CLR_BIT(TCCR0 ,WGM01);
	#elif timer_mode==ctc
	CLR_BIT(TCCR0 ,WGM00);
	SET_BIT(TCCR0 ,WGM01);
	#elif timer_mode==fast_pwm
	set_oc0(TCCR0 ,WGM00);
	SET_BIT(TCCR0 ,WGM01);
	#endif
	/*timer prescaler */
	TCCR0 &=0xf8;
	TCCR0 |=time0_prescaler;
	/*timer oc0 mode */
	#if timer_oc0_mode==oc0_disconnected
	CLR_BIT(TCCR0 ,com00);
	CLR_BIT(TCCR0 ,com01);
	#elif timer_oc0_mode==toggle_oc0
	SET_BIT(TCCR0 ,com00);
	CLR_BIT(TCCR0 ,com01);
	#elif timer_oc0_mode==reserved
	SET_BIT(TCCR0 ,com00);
	CLR_BIT(TCCR0 ,com01);
	#elif timer_oc0_mode==set_oc0
	SET_BIT(TCCR0 ,com00);
	SET_BIT(TCCR0 ,com01);
	#endif
	
	
}
void tmr0_enable_overflow_interrupt(void)
{
	SET_BIT(TIMSK,toie0);
}
void tmr0_enable_ocm_interrupt(void)
{
	SET_BIT(TIMSK,ocie0);
}
void tmr0_set_counter(u8 value_of_TCNT0)
{
	TCNT0=value_of_TCNT0;
}
void tmr0_set_cm(u8 value_of_OCR0)
{
	OCR0=value_of_OCR0;
}
void tmr0_set_duty_cycle(u8 duty_cycle)
{
	OCR0=(duty_cycle*255)/100;
}