/*
 * application.h
 *
 * Created: 12/20/2023 9:00:51 PM
 *  Author: EECE
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ADC/ADC_init.h"
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#include "../DIO/DIO_int.h"
#include "../INTERRUPT/external interrupts/external interrupts initilalizations.h"
#include "../INTERRUPT/general interrupts/Initialization.h"
#include "../UART/UART_interface.h"
#include "../../HAL/DC MOTOR/DC MOTOR.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../TIMER/Timer_interface.h"
#include <util/delay.h>
void app_initialization();
void application();

#endif /* APPLICATION_H_ */