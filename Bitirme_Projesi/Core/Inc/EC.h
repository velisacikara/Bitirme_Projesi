/*
 * EC.h
 *
 *  Created on: Apr 17, 2024
 *      Author: VeliSacikara
 */

#ifndef INC_EC_H_
#define INC_EC_H_


#include "main.h"





uint16_t EC_Read_ADC();

void EC_Buffera_Topla();

float EC_Get_Median_Num(uint32_t *bArray, int iFilterLen);

float EC_Get_Value();







#endif /* INC_EC_H_ */
