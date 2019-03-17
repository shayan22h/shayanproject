/**
  ******************************************************************************
  * Author : shayan
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* UART handler declaration */
UART_HandleTypeDef UartHandle;
uint8_t mydata[13] = "Heooo world\r\n";

#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */



static void SystemClock_Config(void);
static void Error_Handler(void);
//static void MX_GPIO_Init(void);


int main(void)
{

	HAL_Init();

	  /* Configure the system clock to 180 MHz */
	  SystemClock_Config();
	  MX_GPIO_Init();

	  BSP_LED_Init(LED2);

	  __HAL_RCC_USART3_CLK_ENABLE();
	  UartHandle.Instance        = USARTx;

	    UartHandle.Init.BaudRate   = 9600;
	    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	    UartHandle.Init.StopBits   = UART_STOPBITS_1;
	    UartHandle.Init.Parity     = UART_PARITY_ODD;
	    UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	    UartHandle.Init.Mode       = UART_MODE_TX_RX;
	    UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	    if (HAL_UART_Init(&UartHandle) != HAL_OK)
	    {
	      /* Initialization Error */
	      Error_Handler();
	    }
	    /* Output a message on Hyperterminal using printf function */
	    HAL_UART_Transmit(&UartHandle,mydata,13,10);
	    printf("\n\r UART Printf Example: retarget the C library printf function to the UART\n\r");
	    printf("** Test finished successfully. ** \n\r");

	    /* Infinite loop */
	    while (1)
	    {
	  	 //HAL_UART_Transmit(&UartHandle,mydata,13,10);
	    	 if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)) {

	    	            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
	    	            HAL_UART_Transmit(&UartHandle,mydata,13,10);
	    	        } else {
	    	        	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
	    	        }

	    }
}


PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART3 and Loop until the end of transmission */
  HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}


static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
}

static void Error_Handler(void)
{
  /* Turn LED2 on */
  BSP_LED_On(LED2);
  while (1)
  {
  }
}
