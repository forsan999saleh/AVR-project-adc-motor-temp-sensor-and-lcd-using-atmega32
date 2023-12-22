/*
 * Prog_int.c
 *
 * Created: 12/9/2023 1:41:26 PM
 *  Author: EECE
 */ 
#include "Initialization.h"

void general_interrupt_enable()
{
	 SET_BIT(general_interrupt_SREG_reg,7);
}
void general_interrupt_disable()
{
	CLR_BIT(general_interrupt_SREG_reg,7);
}
