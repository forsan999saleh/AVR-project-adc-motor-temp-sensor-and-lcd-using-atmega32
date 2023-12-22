/*
 * ADC_Private.h
 *
 * Created: 12/16/2023 10:36:46 AM
 *  Author: EECE
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC    *((volatile u16*)0x24)

#define ADMUX   *((volatile u8*)0x27)
#define ADCSRA  *((volatile u8*)0x26)



#endif /* ADC PRIVATE_H_ */