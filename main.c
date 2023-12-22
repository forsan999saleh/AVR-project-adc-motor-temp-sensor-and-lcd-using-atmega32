/*
 * GccApplication1.c
 *
 * Created: 12/18/2023 8:52:54 PM
 * Author : EECE
 */ 
#define F_CPU 1000000UL
#include "MCAL/APPLICATION/application.h"
int main(void)
{
	app_initialization();
	while(1)
	{
		application();
	}
	return 0;
}
