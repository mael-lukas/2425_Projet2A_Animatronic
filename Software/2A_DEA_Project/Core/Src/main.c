/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "stm32g4xx_hal.h"
#include "xl430.h"
#include "neopixel.h"
#include "mp3.h"
#include "bluetooth_protocol.h"
#include "VL53L1X_api.h"
#include "vl53l1_error_codes.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define VL53L1X_DEFAULT_ADDRESS (0x29 << 1)

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif

PUTCHAR_PROTOTYPE {
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

GETCHAR_PROTOTYPE
{
	uint8_t ch = 0;

	/* Clear the Overrun flag just before receiving the first character */
	__HAL_UART_CLEAR_OREFLAG(&huart2);

	/* Wait for reception of a character on the USART RX line and echo this
	 * character on console */
	HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}

///////////////////////////////////////////////// TOF ////////////////////////////////////////////////////////////////////

//uint32_t measure_counter = 0;
//uint8_t data_available = 0;
//
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	if (TOF_GPIO_Pin == GPIO_Pin)
//	{
//		measure_counter++;
//		data_available++;
//	}
//}

//////////////////////////////////////////// Bluetooth protocol //////////////////////////////////////////////////////////

//char startChar = '@';
//char endChar = '#';
//
//uint8_t rx_char; // Variable to store the received character
//
//char instruction[200];
//int instructionIndex = 0;
//
//int UARTReceiverState = 0;
//
//volatile int flagUART1 = 0;
//
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//	// Re-enable UART interrupt reception
//	HAL_UART_Receive_IT(&huart3, &rx_char, 1);
//
//	instruction[instructionIndex] = rx_char;
//	instructionIndex++;
//
//	if (rx_char == '#')
//	{
//		instruction[instructionIndex] = 0; // 0 character for the printf
//		instructionIndex = 0;
//		flagUART1 = 1;
//	}
//}

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
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_UART4_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_I2C3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */


  /////////////////////////////////////////////// Tests XL430 ////////////////////////////////////////////////////////////////

	printf("\r\n===== ANIMATRONIC EAGLE FUCK YEAH =====\r\n");
	__XL430_HandleTypeDef XL430_1;
//	__XL430_HandleTypeDef XL430_2;
//	__XL430_HandleTypeDef XL430_3;
//	__XL430_HandleTypeDef XL430_4;
//	__XL430_HandleTypeDef XL430_5;
//	__XL430_HandleTypeDef XL430_6;
//
	XL430_Init(&XL430_1, &huart1, 1, 0);
	XL430_Init_debug(&XL430_1, &huart1, &huart2, 1, 0);
	HAL_Delay(300);
	XL430_Write_Data2(&XL430_1,XL430_REG_TORQUE_ENABLE,1);
	(&XL430_1)->torque_enable = 1;
//
//	XL430_Init(&XL430_2, &huart1, 2, 0);
//	XL430_Init_debug(&XL430_2, &huart1, &huart2, 2, 0);
//	HAL_Delay(200);
//	XL430_Write_Data2(&XL430_2,XL430_REG_TORQUE_ENABLE,1);
//	(&XL430_2)->torque_enable = 1;
//
//	XL430_Init(&XL430_3, &huart1, 3, 0);
//	XL430_Init_debug(&XL430_3, &huart1, &huart2, 3, 0);
//	HAL_Delay(200);
//	XL430_Write_Data2(&XL430_3,XL430_REG_TORQUE_ENABLE,1);
//	(&XL430_3)->torque_enable = 1;
//	HAL_Delay(200);
//
//	XL430_Init(&XL430_4, &huart1, 4, 0);
//	XL430_Init_debug(&XL430_4, &huart1, &huart2, 4, 0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_4,XL430_REG_TORQUE_ENABLE,1);
//	(&XL430_4)->torque_enable = 1;
//	HAL_Delay(300);
//
//	XL430_Init(&XL430_5, &huart1, 5, 0);
//	XL430_Init_debug(&XL430_5, &huart1, &huart2, 5, 0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_5,XL430_REG_TORQUE_ENABLE,1);
//	(&XL430_5)->torque_enable = 1;
//	HAL_Delay(300);
//
//	XL430_Init(&XL430_6, &huart1, 6, 0);
//	XL430_Init_debug(&XL430_6, &huart1, &huart2, 6, 0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_6,XL430_REG_TORQUE_ENABLE,1);
//	(&XL430_6)->torque_enable = 1;
//	HAL_Delay(300);
//
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(1000);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,-40);
//	HAL_Delay(1000);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(1000);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,-40);
//	HAL_Delay(1000);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,0);
//

	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,-40);
	printf("jaaj\n\r");
	HAL_Delay(2000);
	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,40);
	printf("jaaj\n\r");
	HAL_Delay(2000);
	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,0);

//	XL430_Write_Data2(&XL430_2,XL430_REG_GOAL_VELOCITY,40);
//	printf("jaaj\n\r");
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_2,XL430_REG_GOAL_VELOCITY,-40);
//	printf("jaaj\n\r");
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_2,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_3,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_3,XL430_REG_GOAL_VELOCITY,-40);
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_3,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(300);
//	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(2000);
//	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,0);
//
//	HAL_Delay(200);
//
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(2000);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,-40);
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_6,XL430_REG_GOAL_VELOCITY,40);
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_6,XL430_REG_GOAL_VELOCITY,-40);
//	HAL_Delay(1500);
//	XL430_Write_Data2(&XL430_6,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,-40);
//	HAL_Delay(2000);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,0);


//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,80);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,-80);
//	HAL_Delay(950);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,-80);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_2,XL430_REG_GOAL_VELOCITY,80);
//	HAL_Delay(700);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,80);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_2,XL430_REG_GOAL_VELOCITY,-80);
//	HAL_Delay(700);
//	XL430_Write_Data2(&XL430_5,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_2,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//
//
//	XL430_Write_Data2(&XL430_6,XL430_REG_GOAL_VELOCITY,80);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_3,XL430_REG_GOAL_VELOCITY,80);
//	HAL_Delay(700);
//	XL430_Write_Data2(&XL430_6,XL430_REG_GOAL_VELOCITY,-80);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_3,XL430_REG_GOAL_VELOCITY,-80);
//	HAL_Delay(700);
//	XL430_Write_Data2(&XL430_6,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_3,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,-80);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,80);
//	HAL_Delay(950);
//	XL430_Write_Data2(&XL430_4,XL430_REG_GOAL_VELOCITY,0);
//	HAL_Delay(100);
//	XL430_Write_Data2(&XL430_1,XL430_REG_GOAL_VELOCITY,0);


//////////////////////////////////////////////// Tests mp3 player ////////////////////////////////////////////////////////////////

//	mp3_selectStorageDevice();
//	waitNms(20);
//	mp3_setVolume(10);
//	waitNms(20);
//	mp3_playWithIndex(2);


///////////////////////////////////////////// Tests neopixel ////////////////////////////////////////////////////////////////
//  animateInit();
//  HAL_Delay(1000);
//  animateChaserFwd(0xFF4400,25);


///////////////////////////////////////////// Tests TOF //////////////////////////////////////////////////////////////////
//  printf("\r\n===== VL53L1X-SATEL =====\r\n");
//
////  	HAL_GPIO_WritePin(XSDN_GPIO_Port, XSDN_Pin, GPIO_PIN_SET);
////  	HAL_Delay(10);
//
//  	uint16_t id;
//  	if (VL53L1X_GetSensorId(VL53L1X_DEFAULT_ADDRESS, &id) != VL53L1_ERROR_NONE)
//  	{
//  		Error_Handler();
//  	}
//  	printf("SensorID : 0x%X\r\n", id);
//
//  	VL53L1X_Version_t version;
//  	if (VL53L1X_GetSWVersion(&version) != VL53L1_ERROR_NONE)
//  	{
//  		Error_Handler();
//  	}
//  	printf("Version : %u.%ub%ur%lu\r\n", version.major, version.minor, version.build, version.revision);
//
//  	uint8_t boot_state = 0;
//  	uint8_t boot_state_counter = 0;
//
//  	while(boot_state == 0)
//  	{
//  		boot_state_counter++;
//  		if (VL53L1X_BootState(VL53L1X_DEFAULT_ADDRESS, &boot_state) != VL53L1_ERROR_NONE)
//  		{
//  			Error_Handler();
//  		}
//  		HAL_Delay(1);
//  	}
//
//  	printf("Chip booted in %d...\r\n", boot_state_counter);
//
//  	//Loads the 135 bytes default values to initialize the sensor.
//  	if (VL53L1X_SensorInit(VL53L1X_DEFAULT_ADDRESS) != VL53L1_ERROR_NONE)
//  	{
//  		Error_Handler();
//  	}
//  	printf("Sensor initialized with the default values\r\n");
//
//  	if (VL53L1X_SetDistanceMode(VL53L1X_DEFAULT_ADDRESS, 1) != VL53L1_ERROR_NONE) // 1=short, limited to 1.3m
//  	{
//  		Error_Handler();
//  	}
//  	printf("Short distance mode\r\n");
//
//  	if (VL53L1X_SetTimingBudgetInMs(VL53L1X_DEFAULT_ADDRESS, 50) != VL53L1_ERROR_NONE) // in ms possible values [20, 50, 100, 200, 500]
//  	{
//  		Error_Handler();
//  	}
//
//  	if (VL53L1X_SetInterMeasurementInMs(VL53L1X_DEFAULT_ADDRESS, 50) != VL53L1_ERROR_NONE) // in ms, IM must be >= TB
//  	{
//  		Error_Handler();
//  	}
//
//  	printf("Timing budget set\r\n");
//
//  	if (VL53L1X_StartRanging(VL53L1X_DEFAULT_ADDRESS) != VL53L1_ERROR_NONE)
//  	{
//  		Error_Handler();
//  	}


////////////////////////////////////////// Tests bluetooth protocol ////////////////////////////////////////////////////////////////
//  float volume = 1.0;
//  char* variableNames[1] = {"volume"};
//  float* variablePointers[1] = {&volume};
//  dictOfVariables_t dictOfVars = {
//		  .n = 1,
//		  .variableNames = variableNames,
//		  .variables = variablePointers
//  };
//
//  labelValue_t lv_test = {
//		  .label = "volume",
//		  .value = 5.0
//  };
//  printf("volume = %f\r\n", volume);
//  applyLabelValue(lv_test, dictOfVars);
//  printf("volume = %f\r\n", volume);
//
//  HAL_UART_Receive_IT(&huart3,&rx_char,1);

  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);
  printf("Led on \n\r");

  /* USER CODE END 2 */

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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
