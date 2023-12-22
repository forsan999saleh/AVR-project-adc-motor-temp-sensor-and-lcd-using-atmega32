/*
 * ADC.h
 *
 * Created: 12/16/2023 10:29:41 AM
 *  Author: EECE
 */ 

#ifndef ADC_INIT_H
#define ADC_INIT_H
#include "ADC_Configure.h"
#include "ADC_Private.h"
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#include "../DIO/DIO_int.h"

#define EXT      0X00
#define Vcc      0X01
#define reversed 0X02
#define internal  0X11



#define CH_0 0X00
#define CH_1 0X01
#define CH_2 0X02
#define CH_3 0X03
#define CH_4 0X04
#define CH_5 0X05
#define CH_6 0X06
#define CH_7 0X07


#define DIV_2        0X00
#define DIV_4        0X02
#define DIV_8        0X03
#define DIV_16       0X04
#define DIV_32       0X05
#define DIV_64       0X06
#define DIV_128      0X07

#define Adj_Right 0
#define Adj_Left  1

#define Enable    1
#define Disable   0

#define ADLAR     5
#define REFS0     6
#define REFS1     7

#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADSC      6
#define ADIF      4
#define ADEN      7

void ADC_voidADCInit();
u16  ADC_u16ReadChannel(u8 u8CH);
#endif /* ADC_H_ */