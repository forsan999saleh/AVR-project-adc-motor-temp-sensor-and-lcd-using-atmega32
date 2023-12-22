/*
 * DC_MOTOR_Prog.c
 *
 * Created: 12/9/2023 11:38:35 AM
 *  Author: EECE
 */ 
#include "DC MOTOR.h"
#include <util/delay.h>
void dc_motor_initialization()
{
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
}
void dc_motor_operation(u8 direction)
{
	switch(direction)
	{
		case clock_wise_direction_dc: 
		DIO_voidSetPinVal(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		DIO_voidSetPinVal(DIO_PORTC,DIO_PIN1,DIO_LOW);
		_delay_ms(Delay_Time);
		break;
		case anti_clockwise_direction_dc: 
		DIO_voidSetPinVal(DIO_PORTC,DIO_PIN0,DIO_LOW);
		DIO_voidSetPinVal(DIO_PORTC,DIO_PIN1,DIO_HIGH);
			_delay_ms(Delay_Time);
		break;
		default: break;
	}
}