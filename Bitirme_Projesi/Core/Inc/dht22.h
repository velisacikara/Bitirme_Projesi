#ifndef DHT22_H_
#define DHT22_H_
//--------------------------------------------------
#include "stm32f4xx_hal.h"
//--------------------------------------------------
#define data_port GPIOD
#define data_pin  GPIO_PIN_15
void DHT22_Init(void);
float DHT22_Get_Humidity();
//--------------------------------------------------
#endif /* DHT22_H_ */
