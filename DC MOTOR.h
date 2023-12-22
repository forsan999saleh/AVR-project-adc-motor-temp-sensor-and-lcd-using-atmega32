/*
 * DC_MOTOR.h
 *
 * Created: 12/9/2023 11:38:12 AM
 *  Author: EECE
 */ 


#ifndef DC MOTOR_H_
#define DC MOTOR_H_
#include "../../MCAL/DIO/DIO_int.h"
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#define clock_wise_direction_dc  1
#define anti_clockwise_direction_dc 2
#define  Delay_Time 1000
void dc_motor_initialization();
void dc_motor_operation(u8 direction);


#endif /* DC MOTOR_H_ */