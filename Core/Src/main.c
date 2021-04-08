// /* USER CODE BEGIN Header */
// /**
//   ******************************************************************************
//   * @file           : main.c
//   * @brief          : Main program body
//   ******************************************************************************
//   * @attention
//   *
//   * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
//   * All rights reserved.</center></h2>
//   *
//   * This software component is licensed by ST under BSD 3-Clause license,
//   * the "License"; You may not use this file except in compliance with the
//   * License. You may obtain a copy of the License at:
//   *                        opensource.org/licenses/BSD-3-Clause
//   *
//   ******************************************************************************
//   */
// /* USER CODE END Header */
// /* Includes ------------------------------------------------------------------*/
// #include "main.h"
// #include "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h"
// #include "Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_rcc.h"
// #include "Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash.h"
// #include "Drivers/CMSIS/Device/ST/STM32F4xx/Include/stm32f407xx.h"
// #include "Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_flash_ex.h"

// /* Private includes ----------------------------------------------------------*/
// /* USER CODE BEGIN Includes */
// #include "lib/UL/spinner/spinner.h"
// #include "lib/UL/button_controler/button_controler.h"
// #include "lib/drivers/uart/uart.h"
// #include "lib/UL/io/io_generic/io_generic.h"
// #include "lib/UL/io/io_uart/io_uart.h"
// #include "lib/UL/io/io_spi/io_spi.h"
// #include "lib/UL/io/io_i2c/io_i2c.h"
// /* USER CODE END Includes */

// /* Private typedef -----------------------------------------------------------*/
// /* USER CODE BEGIN PTD */

// /* USER CODE END PTD */

// /* Private define ------------------------------------------------------------*/
// /* USER CODE BEGIN PD */
// /* USER CODE END PD */

// /* Private macro -------------------------------------------------------------*/
// /* USER CODE BEGIN PM */

// /* USER CODE END PM */

// /* Private variables ---------------------------------------------------------*/
// UART_HandleTypeDef huart2;

// /* Definitions for defaultTask */
// osThreadId_t defaultTaskHandle;
// const osThreadAttr_t defaultTask_attributes = {
//   .name = "defaultTask",
//   .priority = (osPriority_t) osPriorityNormal,
//   .stack_size = 128 * 4
// };
// /* Definitions for blink_task */
// osThreadId_t blink_taskHandle;
// const osThreadAttr_t blink_task_attributes = {
//   .name = "blink_task",
//   .priority = (osPriority_t) osPriorityRealtime7,
//   .stack_size = 128 * 4
// };
// /* USER CODE BEGIN PV */

// /* USER CODE END PV */

// /* Private function prototypes -----------------------------------------------*/
// void SystemClock_Config(void);
// static void MX_GPIO_Init(void);
// static void MX_USART2_UART_Init(void);
// void StartDefaultTask(void *argument);
// void blink_task_entry(void *argument);

// /* USER CODE BEGIN PFP */

// /* USER CODE END PFP */

// /* Private user code ---------------------------------------------------------*/
// /* USER CODE BEGIN 0 */

// /* USER CODE END 0 */

// /**
//   * @brief  The application entry point.
//   * @retval int
//   */
int main(void)
{
  // /* USER CODE BEGIN 1 */

  // /* USER CODE END 1 */

  // /* MCU Configuration--------------------------------------------------------*/

  // /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  // HAL_Init();

  // /* USER CODE BEGIN Init */

  // /* USER CODE END Init */

  // /* Configure the system clock */
  // SystemClock_Config();

  // /* USER CODE BEGIN SysInit */

  // /* USER CODE END SysInit */

  // /* Initialize all configured peripherals */
  // MX_GPIO_Init();
  // MX_USART2_UART_Init();
  // /* USER CODE BEGIN 2 */
  // spinner_init();
  // button_controler_init();
  // io_configurate();
  // /* USER CODE END 2 */

  // /* Init scheduler */
  // osKernelInitialize();

  // /* USER CODE BEGIN RTOS_MUTEX */
  // /* add mutexes, ... */
  // /* USER CODE END RTOS_MUTEX */

  // /* USER CODE BEGIN RTOS_SEMAPHORES */
  // /* add semaphores, ... */
  // /* USER CODE END RTOS_SEMAPHORES */

  // /* USER CODE BEGIN RTOS_TIMERS */
  // /* start timers, add new ones, ... */
  // /* USER CODE END RTOS_TIMERS */

  // /* USER CODE BEGIN RTOS_QUEUES */
  // /* add queues, ... */
  // /* USER CODE END RTOS_QUEUES */

  // /* Create the thread(s) */
  // /* creation of defaultTask */
  // defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  // /* creation of blink_task */
  // blink_taskHandle = osThreadNew(blink_task_entry, NULL, &blink_task_attributes);

  // /* USER CODE BEGIN RTOS_THREADS */
  // /* add threads, ... */
  // /* USER CODE END RTOS_THREADS */

  // /* Start scheduler */
  // osKernelStart();

  // /* We should never get here as control is now taken by the scheduler */
  // /* Infinite loop */
  // /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

// /**
//   * @brief System Clock Configuration
//   * @retval None
//   */
// void SystemClock_Config(void)
// {
//   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

//   /** Configure the main internal regulator output voltage
//   */
//   __HAL_RCC_PWR_CLK_ENABLE();
//   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
//   /** Initializes the RCC Oscillators according to the specified parameters
//   * in the RCC_OscInitTypeDef structure.
//   */
//   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
//   RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//   RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
//   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
//   if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   /** Initializes the CPU, AHB and APB buses clocks
//   */
//   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                               |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
//   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

//   if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
//   {
//     Error_Handler();
//   }
// }

// /**
//   * @brief USART2 Initialization Function
//   * @param None
//   * @retval None
//   */
// static void MX_USART2_UART_Init(void)
// {

//   /* USER CODE BEGIN USART2_Init 0 */

//   /* USER CODE END USART2_Init 0 */

//   /* USER CODE BEGIN USART2_Init 1 */

//   /* USER CODE END USART2_Init 1 */
//   huart2.Instance = USART2;
//   huart2.Init.BaudRate = 9600;
//   huart2.Init.WordLength = UART_WORDLENGTH_8B;
//   huart2.Init.StopBits = UART_STOPBITS_1;
//   huart2.Init.Parity = UART_PARITY_NONE;
//   huart2.Init.Mode = UART_MODE_TX_RX;
//   huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//   huart2.Init.OverSampling = UART_OVERSAMPLING_16;
//   if (HAL_UART_Init(&huart2) != HAL_OK)
//   {
//     Error_Handler();
//   }
//   /* USER CODE BEGIN USART2_Init 2 */

//   /* USER CODE END USART2_Init 2 */

// }

// /**
//   * @brief GPIO Initialization Function
//   * @param None
//   * @retval None
//   */
// static void MX_GPIO_Init(void)
// {
//   GPIO_InitTypeDef GPIO_InitStruct = {0};

//   /* GPIO Ports Clock Enable */
//   __HAL_RCC_GPIOA_CLK_ENABLE();
//   __HAL_RCC_GPIOD_CLK_ENABLE();

//   /*Configure GPIO pin Output Level */
//   HAL_GPIO_WritePin(GPIOA, RAD_LED_Pin|GREEN_LED_Pin|YELLOW_LED_Pin|BLUE_LED_Pin, GPIO_PIN_RESET);

//   /*Configure GPIO pins : RAD_LED_Pin GREEN_LED_Pin YELLOW_LED_Pin BLUE_LED_Pin */
//   GPIO_InitStruct.Pin = RAD_LED_Pin|GREEN_LED_Pin|YELLOW_LED_Pin|BLUE_LED_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//   /*Configure GPIO pin : BUTTON_Pin */
//   GPIO_InitStruct.Pin = BUTTON_Pin;
//   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   HAL_GPIO_Init(BUTTON_GPIO_Port, &GPIO_InitStruct);

// }

// /* USER CODE BEGIN 4 */

// /* USER CODE END 4 */

// /* USER CODE BEGIN Header_StartDefaultTask */
// /**
//   * @brief  Function implementing the defaultTask thread.
//   * @param  argument: Not used
//   * @retval None
//   */
// /* USER CODE END Header_StartDefaultTask */
// void StartDefaultTask(void *argument)
// {
//   /* USER CODE BEGIN 5 */
//   /* Infinite loop */
//   for(;;)
//   {
//     osDelay(1);
//   }
//   /* USER CODE END 5 */
// }

// /* USER CODE BEGIN Header_blink_task_entry */
// /**
// * @brief Function implementing the blink_task thread.
// * @param argument: Not used
// * @retval None
// */
// /* USER CODE END Header_blink_task_entry */
// void blink_task_entry(void *argument)
// {
//   /* USER CODE BEGIN blink_task_entry */
//   /* Infinite loop */
//   for(;;)
//   {
//     HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
//     vTaskDelay(1000);
//   }
//   vTaskDelay(0);
//   /* USER CODE END blink_task_entry */
// }

// /**
//   * @brief  This function is executed in case of error occurrence.
//   * @retval None
//   */
// void Error_Handler(void)
// {
//   /* USER CODE BEGIN Error_Handler_Debug */
//   /* User can add his own implementation to report the HAL error return state */

//   /* USER CODE END Error_Handler_Debug */
// }

// #ifdef  USE_FULL_ASSERT
// /**
//   * @brief  Reports the name of the source file and the source line number
//   *         where the assert_param error has occurred.
//   * @param  file: pointer to the source file name
//   * @param  line: assert_param error line source number
//   * @retval None
//   */
// void assert_failed(uint8_t *file, uint32_t line)
// {
//   /* USER CODE BEGIN 6 */
//   /* User can add his own implementation to report the file name and line number,
//      tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//   /* USER CODE END 6 */
// }
// #endif /* USE_FULL_ASSERT */

// /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/