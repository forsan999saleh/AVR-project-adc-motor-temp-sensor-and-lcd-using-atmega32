/*
 * private_external_interrupts.h
 *
 * Created: 12/9/2023 4:44:49 PM
 *  Author: EECE
 */ 


#ifndef PRIVATE EXTERNAL INTERRUPTS_H_
#define PRIVATE EXTERNAL INTERRUPTS_H_

#define external_GICS_reg  *((volatile u8 *) 0x5B)
#define external_MCUCR_reg  *((volatile u8* ) 0x55)
#define external_MCUCSR_reg  *((volatile u8* ) 0x54)
#define external_GIFR_reg  *((volatile u8* ) 0x5A)

#endif /* PRIVATE EXTERNAL INTERRUPTS_H_ */