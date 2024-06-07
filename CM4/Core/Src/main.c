/* USER CODE BEGIN Header */
/**
  **********
  * @file           : main.c
  * @brief          : Main program body
  **********
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  **********
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
int vetor[1667] = {240, 241, 242, 243, 244, 245, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 272, 273, 274, 275,
		276, 277, 278, 279, 280, 281, 281, 282, 283, 284, 285, 286, 287, 288, 289, 289, 290, 291, 292, 293, 294, 295, 296, 296, 297, 298, 299, 300, 301, 302, 303, 303, 304, 305, 306, 307, 308, 309, 310, 310, 311, 312, 313,
		314, 315, 316, 316, 317, 318, 319, 320, 321, 322, 322, 323, 324, 325, 326, 327, 327, 328, 329, 330, 331, 332, 333, 333, 334, 335, 336, 337, 338, 338, 339, 340, 341, 342, 342, 343, 344, 345, 346, 347, 347, 348, 349,
		350, 351, 351, 352, 353, 354, 355, 355, 356, 357, 358, 358, 359, 360, 361, 362, 362, 363, 364, 365, 366, 366, 367, 368, 369, 369, 370, 371, 372, 372, 373, 374, 375, 375, 376, 377, 378, 378, 379, 380, 381, 381, 382,
		383, 383, 384, 385, 386, 386, 387, 388, 388, 389, 390, 391, 391, 392, 393, 393, 394, 395, 395, 396, 397, 398, 398, 399, 400, 400, 401, 402, 402, 403, 404, 404, 405, 406, 406, 407, 408, 408, 409, 409, 410, 411, 411,
		412, 413, 413, 414, 415, 415, 416, 416, 417, 418, 418, 419, 419, 420, 421, 421, 422, 422, 423, 424, 424, 425, 425, 426, 426, 427, 428, 428, 429, 429, 430, 430, 431, 431, 432, 433, 433, 434, 434, 435, 435, 436, 436,
		437, 437, 438, 438, 439, 439, 440, 440, 441, 441, 442, 442, 443, 443, 444, 444, 445, 445, 446, 446, 447, 447, 447, 448, 448, 449, 449, 450, 450, 451, 451, 451, 452, 452, 453, 453, 454, 454, 454, 455, 455, 456, 456,
		456, 457, 457, 458, 458, 458, 459, 459, 459, 460, 460, 460, 461, 461, 462, 462, 462, 463, 463, 463, 464, 464, 464, 465, 465, 465, 465, 466, 466, 466, 467, 467, 467, 468, 468, 468, 468, 469, 469, 469, 470, 470, 470,
		470, 471, 471, 471, 471, 472, 472, 472, 472, 472, 473, 473, 473, 473, 474, 474, 474, 474, 474, 475, 475, 475, 475, 475, 475, 476, 476, 476, 476, 476, 476, 477, 477, 477, 477, 477, 477, 477, 478, 478, 478, 478, 478,
		478, 478, 478, 478, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480, 480,
		480, 480, 480, 480, 480, 480, 480, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 479, 478, 478, 478, 478, 478, 478, 478, 478, 478, 477, 477, 477, 477, 477, 477, 477, 476, 476, 476, 476, 476, 476, 475,
		475, 475, 475, 475, 474, 474, 474, 474, 474, 473, 473, 473, 473, 473, 472, 472, 472, 472, 471, 471, 471, 471, 470, 470, 470, 470, 469, 469, 469, 469, 468, 468, 468, 467, 467, 467, 467, 466, 466, 466, 465, 465, 465,
		464, 464, 464, 463, 463, 463, 462, 462, 462, 461, 461, 461, 460, 460, 460, 459, 459, 458, 458, 458, 457, 457, 457, 456, 456, 455, 455, 455, 454, 454, 453, 453, 453, 452, 452, 451, 451, 450, 450, 449, 449, 449, 448,
		448, 447, 447, 446, 446, 445, 445, 444, 444, 443, 443, 443, 442, 442, 441, 441, 440, 440, 439, 439, 438, 438, 437, 437, 436, 435, 435, 434, 434, 433, 433, 432, 432, 431, 431, 430, 430, 429, 428, 428, 427, 427, 426,
		426, 425, 424, 424, 423, 423, 422, 421, 421, 420, 420, 419, 418, 418, 417, 417, 416, 415, 415, 414, 414, 413, 412, 412, 411, 410, 410, 409, 409, 408, 407, 407, 406, 405, 405, 404, 403, 403, 402, 401, 401, 400, 399,
		399, 398, 397, 397, 396, 395, 394, 394, 393, 392, 392, 391, 390, 390, 389, 388, 387, 387, 386, 385, 385, 384, 383, 382, 382, 381, 380, 379, 379, 378, 377, 376, 376, 375, 374, 374, 373, 372, 371, 370, 370, 369, 368,
		367, 367, 366, 365, 364, 364, 363, 362, 361, 360, 360, 359, 358, 357, 357, 356, 355, 354, 353, 353, 352, 351, 350, 349, 349, 348, 347, 346, 345, 344, 344, 343, 342, 341, 340, 340, 339, 338, 337, 336, 335, 335, 334,
		333, 332, 331, 330, 330, 329, 328, 327, 326, 325, 325, 324, 323, 322, 321, 320, 319, 319, 318, 317, 316, 315, 314, 313, 313, 312, 311, 310, 309, 308, 307, 307, 306, 305, 304, 303, 302, 301, 300, 300, 299, 298, 297,
		296, 295, 294, 293, 292, 292, 291, 290, 289, 288, 287, 286, 285, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 276, 275, 274, 273, 272, 271, 270, 269, 268, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 259,
		258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 221, 220,
		219, 218, 217, 216, 215, 214, 213, 212, 212, 211, 210, 209, 208, 207, 206, 205, 204, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 195, 194, 193, 192, 191, 190, 189, 188, 188, 187, 186, 185, 184, 183, 182, 181,
		180, 180, 179, 178, 177, 176, 175, 174, 173, 173, 172, 171, 170, 169, 168, 167, 167, 166, 165, 164, 163, 162, 161, 161, 160, 159, 158, 157, 156, 155, 155, 154, 153, 152, 151, 150, 150, 149, 148, 147, 146, 145, 145,
		144, 143, 142, 141, 140, 140, 139, 138, 137, 136, 136, 135, 134, 133, 132, 131, 131, 130, 129, 128, 127, 127, 126, 125, 124, 123, 123, 122, 121, 120, 120, 119, 118, 117, 116, 116, 115, 114, 113, 113, 112, 111, 110,
		110, 109, 108, 107, 106, 106, 105, 104, 104, 103, 102, 101, 101, 100, 99, 98, 98, 97, 96, 95, 95, 94, 93, 93, 92, 91, 90, 90, 89, 88, 88, 87, 86, 86, 85, 84, 83, 83, 82, 81, 81, 80, 79, 79, 78, 77, 77, 76, 75, 75,
		74, 73, 73, 72, 71, 71, 70, 70, 69, 68, 68, 67, 66, 66, 65, 65, 64, 63, 63, 62, 62, 61, 60, 60, 59, 59, 58, 57, 57, 56, 56, 55, 54, 54, 53, 53, 52, 52, 51, 50, 50, 49, 49, 48, 48, 47, 47, 46, 46, 45, 45, 44, 43, 43,
		42, 42, 41, 41, 40, 40, 39, 39, 38, 38, 37, 37, 37, 36, 36, 35, 35, 34, 34, 33, 33, 32, 32, 31, 31, 31, 30, 30, 29, 29, 28, 28, 27, 27, 27, 26, 26, 25, 25, 25, 24, 24, 23, 23, 23, 22, 22, 22, 21, 21, 20, 20, 20, 19,
		19, 19, 18, 18, 18, 17, 17, 17, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4,
		3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 14, 14, 14,
		15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 18, 19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 24, 24, 24, 25, 25, 26, 26, 26, 27, 27, 28, 28, 29, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 33, 34, 34, 35, 35,
		36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 54, 54, 55, 55, 56, 56, 57, 58, 58, 59, 59, 60, 61, 61, 62, 62, 63, 64, 64, 65,
		65, 66, 67, 67, 68, 69, 69, 70, 71, 71, 72, 72, 73, 74, 74, 75, 76, 76, 77, 78, 78, 79, 80, 80, 81, 82, 82, 83, 84, 85, 85, 86, 87, 87, 88, 89, 89, 90, 91, 92, 92, 93, 94, 94, 95, 96, 97, 97, 98, 99, 99, 100, 101,
		102, 102, 103, 104, 105, 105, 106, 107, 108, 108, 109, 110, 111, 111, 112, 113, 114, 114, 115, 116, 117, 118, 118, 119, 120, 121, 122, 122, 123, 124, 125, 125, 126, 127, 128, 129, 129, 130, 131, 132, 133, 133, 134,
		135, 136, 137, 138, 138, 139, 140, 141, 142, 142, 143, 144, 145, 146, 147, 147, 148, 149, 150, 151, 152, 153, 153, 154, 155, 156, 157, 158, 158, 159, 160, 161, 162, 163, 164, 164, 165, 166, 167, 168, 169, 170, 170,
		171, 172, 173, 174, 175, 176, 177, 177, 178, 179, 180, 181, 182, 183, 184, 184, 185, 186, 187, 188, 189, 190, 191, 191, 192, 193, 194, 195, 196, 197, 198, 199, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 208,
		209, 210, 211, 212, 213, 214, 215, 216, 217, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 235, 236, 237, 238, 239};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int index = 1;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  TIM1 -> CCR1 = vetor[0];
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Boot CPU2 */
  HAL_PWREx_ReleaseCore(PWR_CORE_CPU2);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3|RCC_CLOCKTYPE_HCLK2
                              |RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK2Divider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 479;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim -> Instance == TIM1)
    {
    	TIM1 -> CCR1 = vetor[index];
    	if(index<1666)
			index++;
    	else
    		index = 0;
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
