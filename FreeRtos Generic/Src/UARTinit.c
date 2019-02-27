/*
 * UARTinit.c
 *
 *  Created on: 27. feb. 2019
 *      Author: U373170
 */

#include "stm32f4xx_hal.h"
#include "main.h"
#include "UARTinit.h"

//void Setuart(UART_HandleTypeDef *huart);

void Setuart(UART_HandleTypeDef *huart)
{
	__HAL_RCC_USART3_CLK_ENABLE();


	huart->Instance        = USARTx;
	huart->Init.BaudRate   = 9600;
	huart->Init.WordLength = UART_WORDLENGTH_8B;
	huart->Init.StopBits   = UART_STOPBITS_1;
	huart->Init.Parity     = UART_PARITY_ODD;
	huart->Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	huart->Init.Mode       = UART_MODE_TX_RX;
	huart->Init.OverSampling = UART_OVERSAMPLING_16;
}
