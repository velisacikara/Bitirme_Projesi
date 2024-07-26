#ifndef _BMP180_H_
#define _BMP180_H_


#include "stm32f4xx_hal.h"
#include "math.h"


void BMP180_Init (void);

float BMP180_Sicaklik_Okuma (void);

#endif /* INC_BMP180_H_ */
