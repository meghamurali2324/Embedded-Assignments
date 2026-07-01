/*
 * stm32f446xx_uart.h
 *
 *  Created on: June 1, 2026
 *      Author: megha
 */

#ifndef INC_STM32F446XX_USART_H_
#define INC_STM32F446XX_USART_H_


#include "stm32f446xx.h"

/******************************************************************
 * USART Configuration Structure
 ******************************************************************/
typedef struct
{
	uint8_t USART_Mode;
	uint32_t USART_Baud;
	uint8_t USART_NoOfStopBits;
	uint8_t USART_WordLength;
	uint8_t USART_ParityControl;
	uint8_t USART_HWFlowControl;

}USART_Config_t;

/******************************************************************
 * USART Handle Structure
 ******************************************************************/
typedef struct
{
	USART_RegDef_t *pUSARTx;
	USART_Config_t USART_Config;

}USART_Handle_t;

/******************************************************************
 * USART Modes
 ******************************************************************/
#define USART_MODE_ONLY_TX      0
#define USART_MODE_ONLY_RX      1
#define USART_MODE_TXRX         2

/******************************************************************
 * Baud Rates
 ******************************************************************/
#define USART_STD_BAUD_9600     9600
#define USART_STD_BAUD_19200    19200
#define USART_STD_BAUD_38400    38400
#define USART_STD_BAUD_57600    57600
#define USART_STD_BAUD_115200   115200

/******************************************************************
 * Stop Bits
 ******************************************************************/
#define USART_STOPBITS_1        0
#define USART_STOPBITS_0_5      1
#define USART_STOPBITS_2        2
#define USART_STOPBITS_1_5      3

/******************************************************************
 * Word Length
 ******************************************************************/
#define USART_WORDLEN_8BITS     0
#define USART_WORDLEN_9BITS     1

/******************************************************************
 * Parity
 ******************************************************************/
#define USART_PARITY_DISABLE    0
#define USART_PARITY_EN_EVEN    1
#define USART_PARITY_EN_ODD     2

/******************************************************************
 * Hardware Flow Control
 ******************************************************************/
#define USART_HW_FLOW_CTRL_NONE     0
#define USART_HW_FLOW_CTRL_CTS      1
#define USART_HW_FLOW_CTRL_RTS      2
#define USART_HW_FLOW_CTRL_CTS_RTS  3

/******************************************************************
 * USART Flags
 ******************************************************************/
#define USART_FLAG_TXE         (1 << 7)
#define USART_FLAG_RXNE        (1 << 5)
#define USART_FLAG_TC          (1 << 6)

/******************************************************************
 * APIs
 ******************************************************************/
void USART_PeriClockControl(USART_RegDef_t *pUSARTx,uint8_t EnOrDi);

void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_RegDef_t *pUSARTx);

void USART_SendData(USART_Handle_t *pUSARTHandle,
                    uint8_t *pTxBuffer,
                    uint32_t Len);

void USART_ReceiveData(USART_Handle_t *pUSARTHandle,
                       uint8_t *pRxBuffer,
                       uint32_t Len);

void USART_PeripheralControl(USART_RegDef_t *pUSARTx,uint8_t EnOrDi);

uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx,uint8_t StatusFlagName);



#endif /* INC_STM32F446XX_USART_H_ */
