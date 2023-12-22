/*
 * ADC_Prog.c
 *
 * Created: 12/16/2023 10:30:04 AM
 *  Author: EECE
 */ 
#include "ADC_Configure.h"
#include "ADC_init.h"
#include "ADC_Private.h"
void ADC_voidADCInit(){

	//ENABLE ADC
	SET_BIT(ADCSRA,ADEN);
	//ADCSRA = ADCSRA | (1<<ADEN);
	//ADCSRA|= (1<<ADEN);


	ADCSRA &= 0XF8;      //CLEAR PRESCAL BITS    0B11111000
	ADCSRA |= PRESCALE;

	ADMUX  &= 0X3F;      //CLEAR REF. BITS       0B00111111
	ADMUX  |= (REFERENCE << REFS0);

	CLR_BIT(ADMUX,ADLAR);
	//ADMUX  &= ~(RESULT_ADJUST <<ADLAR);
	ADCSRA |= (1<<ADSC);
}



u16  ADC_u16ReadChannel(u8 u8CH){

	u8CH &= 0X07; // make sure that channel not bigger than 7

	ADMUX = (ADMUX & 0xF8) | u8CH ; // clear bits 0:2 first to avoid garbage value from old operation, whit respict other bit as they are (5,6,7) , then assign Channel Id on it.

	ADCSRA |= (1<<ADSC);
	//while (GET_BIT(ADCSRA,ADIF)==0);
	while (!(ADCSRA & (1<<ADIF)) ); //STUCK UNTIL FLAG OF FINSH CONVEGRATION =1
	ADCSRA|=(1<<ADIF); // clear flag

	return ADC;
}
