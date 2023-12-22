/*
 * prog_external_interrupts.c
 *
 * Created: 12/9/2023 4:45:14 PM
 *  Author: EECE
 */ 
#include "external interrupts initilalizations.h"
#include "../../../Library/TYPES.h"
#include "../../../Library/BIT_MATH.h"
void external_interrupt_enable(u8 line)
{
	switch(line)
	{
		case external_interrupt0 : SET_BIT(external_GICS_reg,6);break;
		case external_interrupt1 : SET_BIT(external_GICS_reg,7);break;
		case external_interrupt2 : SET_BIT(external_GICS_reg,5);break;
	}
}
void external_interrupt_disable(u8 line)
{
	switch(line)
	{
		case external_interrupt0 : CLR_BIT(external_GICS_reg,6);break;
		case external_interrupt1 : CLR_BIT(external_GICS_reg,7);break;
		case external_interrupt2 : CLR_BIT(external_GICS_reg,5);break;
	}
	
}
void external_interrupt_sense_control(u8 line ,u8 mode)
{
	switch(line)
	{
		case external_interrupt0 :
		switch(mode)
		{
			case external_interrupt_low_level:
			CLR_BIT(external_MCUCR_reg,0);
			CLR_BIT(external_MCUCR_reg,1);
			break;
			case external_interrupt_on_change:
			SET_BIT(external_MCUCR_reg,0);
			CLR_BIT(external_MCUCR_reg,1);
			break;
			case external_interrupt_falling:
			CLR_BIT(external_MCUCR_reg,0);
			SET_BIT(external_MCUCR_reg,1);
			break;
			case external_interrupt_rising:
			CLR_BIT(external_MCUCR_reg,0);
			CLR_BIT(external_MCUCR_reg,1);
			break;
		}
		break;
		case external_interrupt1 :
		switch(mode)
		{
			case external_interrupt_low_level:
			CLR_BIT(external_MCUCR_reg,2);
			CLR_BIT(external_MCUCR_reg,3);
			break;
			case external_interrupt_on_change:
			SET_BIT(external_MCUCR_reg,2);
			CLR_BIT(external_MCUCR_reg,3);
			break;
			case external_interrupt_falling:
			CLR_BIT(external_MCUCR_reg,2);
			SET_BIT(external_MCUCR_reg,3);
			break;
			case external_interrupt_rising:
			CLR_BIT(external_MCUCR_reg,2);
			CLR_BIT(external_MCUCR_reg,3);
			break;
		}
		break;
		case external_interrupt2 :
		switch(mode)
		{
			
			case external_interrupt_falling:
			CLR_BIT(external_MCUCSR_reg,6);
			break;
			case external_interrupt_rising:
			SET_BIT(external_MCUCSR_reg,6);
			break;
		}
		break;
	}
	
}