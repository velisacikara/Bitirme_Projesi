/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ISITICI_ROLE_Pin GPIO_PIN_12
#define ISITICI_ROLE_GPIO_Port GPIOC
#define FAN_2_ROLE_Pin GPIO_PIN_0
#define FAN_2_ROLE_GPIO_Port GPIOD
#define FAN_1_ROLE_Pin GPIO_PIN_1
#define FAN_1_ROLE_GPIO_Port GPIOD
#define LED2_ROLE_Pin GPIO_PIN_2
#define LED2_ROLE_GPIO_Port GPIOD
#define LED_1_ROLE_Pin GPIO_PIN_3
#define LED_1_ROLE_GPIO_Port GPIOD
#define PH_DUSURUCU_ROLE_Pin GPIO_PIN_4
#define PH_DUSURUCU_ROLE_GPIO_Port GPIOD
#define PH_ARTIRICI_ROLE_Pin GPIO_PIN_5
#define PH_ARTIRICI_ROLE_GPIO_Port GPIOD
#define EC_ROLE_Pin GPIO_PIN_6
#define EC_ROLE_GPIO_Port GPIOD
#define SU_ROLE_Pin GPIO_PIN_7
#define SU_ROLE_GPIO_Port GPIOD
#define RESET_ROLE_Pin GPIO_PIN_3
#define RESET_ROLE_GPIO_Port GPIOB
#define MOTOR_ROLE_Pin GPIO_PIN_4
#define MOTOR_ROLE_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
