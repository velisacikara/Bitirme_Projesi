/*
 * EC.c
 *
 *  Created on: Apr 17, 2024
 *      Author: VeliSacikara
 */

#include "EC.h"

#define VREF 5.0           // analog reference voltage(Volt) of the ADC
#define SCOUNT 30          // sum of sample point
uint32_t analogBuffer[SCOUNT];  // store the analog value in the array, read from ADC
uint32_t analogBufferTemp[SCOUNT];
uint32_t analogBufferIndex = 0, copyIndex = 0;
float averageVoltage = 0, tdsValue = 0, temperature = 25;

uint32_t ec_val = 0;
uint16_t temp_ec = 0;

extern ADC_HandleTypeDef hadc2;


uint16_t EC_Read_ADC()
{
	uint16_t adc_val = 0;
	HAL_ADC_Start(&hadc2);
	if(HAL_ADC_PollForConversion(&hadc2, HAL_MAX_DELAY) == HAL_OK)
	{
		adc_val = HAL_ADC_GetValue(&hadc2);
	}
	HAL_ADC_Stop(&hadc2);
	return adc_val;
}


void EC_Buffera_Topla()
{
	for(int i = 0; i <= SCOUNT; i++)
	{
		analogBuffer[i] = ( EC_Read_ADC() / 10);
		HAL_Delay(50);
	}
}


float EC_Get_Median_Num(uint32_t *bArray, int iFilterLen) {
  uint32_t bTab[iFilterLen];
  for (uint8_t i = 0; i < iFilterLen; i++)
    bTab[i] = bArray[i];
  int i, j;
  float bTemp;

  for (j = 0; j < iFilterLen - 1; j++) {
    for (i = 0; i < iFilterLen - j - 1; i++) {
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0)
    bTemp = bTab[(iFilterLen - 1) / 2];

  else
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  return bTemp * 1.48148148;
}


float EC_Get_Value()
{
	EC_Buffera_Topla();
    averageVoltage = EC_Get_Median_Num(analogBuffer, SCOUNT) * (float)VREF / 1024.0;
    float compensationCoefficient = 1.0 + 0.02 * (temperature - 25.0);                                                                                                                //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
    float compensationVolatge = averageVoltage / compensationCoefficient;                                                                                                             //temperature compensation
    tdsValue = (133.42 * compensationVolatge * compensationVolatge * compensationVolatge - 255.86 * compensationVolatge * compensationVolatge + 857.39 * compensationVolatge) * 0.5;  //convert voltage value to tds value
    HAL_Delay(800);
    return tdsValue;

}

