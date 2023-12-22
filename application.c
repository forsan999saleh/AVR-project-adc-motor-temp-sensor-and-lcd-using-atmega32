/*
 * application.c
 *
 * Created: 12/20/2023 9:01:09 PM
 *  Author: EECE
 */ 

#include "application.h"
u32  adc_signal,temperature;
u8 critical_temperature=40;
u16 counter=0;
void timer0_function();
app_initialization()
{
	//initializations
	//tmr0_enable_ocm_interrupt();
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);//PIN4 IN PORT D O/P FOR LED TO TOGGLE AFTER TIMER
	//tmr0_set_ocm_callback(timer0_function);
	//tmr0_set_overflow_callback(timer0_function);
	tmr0_initialization();
	//tmr0_enable_overflow_interrupt();
	general_interrupt_enable();
	dc_motor_initialization();
	LCD_voidInit();
	ADC_voidADCInit();
	MUART_voidInit();
	external_interrupt_enable(external_interrupt0 );//INITIALIZE INT 0
	external_interrupt_sense_control(external_interrupt0,external_interrupt_rising)	;
	
	

}
application()
{
       /* adc application of temperature with dc motor and leds */
		adc_signal=ADC_u16ReadChannel(CH_1)*4.88;
		//adc_signal=((u16)(ADC_u16ReadChannel(CH_1) *(u32) 1500))/(s32)(1024);
		temperature = adc_signal/10;
		/* lcd display to temperature and status*/
		LCD_voidGoTo(1,1);
		LCD_voidWriteString("Temperature:");
		LCD_voidGoTo(1,2);
		LCD_voidWriteNum(temperature);
		_delay_ms(1000);
		/* temperature conditions to operate dc motor and leds*/
		if(temperature<critical_temperature)
		{
			dc_motor_operation(anti_clockwise_direction_dc);
			LCD_voidWriteString(" Normal Temp");
			_delay_ms(1000);
			ISR(INT0_vect);
		}
		if(temperature>=critical_temperature)
		{
			dc_motor_operation(clock_wise_direction_dc);
			LCD_voidWriteString(" High Temp");
			
		}
		/* uart application */
		MUART_voidSendCharSynch('B');
		MUART_u8RecieveCharSynch();
		MUART_voidSendString("UART says hi");
		/* isr and timer*/
		//ISR(INT0_vect);
		//tmr0_set_overflow_callback(timer0_function);//timer to turn on led in port d port 4
		
	
	
		
		
	
}

/* timer for interrupt to happen and turn on the led */
	
	void timer0_function()
	{
		
		counter++;
		while(counter==100)
		{
			DIO_voidTogPinVal(DIO_PORTD,DIO_PIN4);
			_delay_ms(1000);
			
		}
		
	}


ISR(INT0_vect)
{
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN0,DIO_LOW);//to stop dc motor 
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN1,DIO_LOW);
	
}