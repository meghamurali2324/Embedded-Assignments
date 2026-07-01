/*
 * stm32f446xx_uart.c
 *
 *  Created on: June 1, 2026
 *      Author: megha
 */

/*
 * stm32f446re_uart_driver.c
 */

#include "stm32f446xx_usart.h"

void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE)
    {
        if(pUSARTx == USART1) USART1_PCLK_EN();
        else if(pUSARTx == USART2) USART2_PCLK_EN();
        else if(pUSARTx == USART6) USART6_PCLK_EN();
    }
}

void USART_Init(USART_Handle_t *pUSARTHandle)
{
    uint32_t temp = 0;

    /* Enable TX/RX */
    if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
        temp |= (1 << 3);
    else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
        temp |= (1 << 2);
    else
        temp |= (1 << 2) | (1 << 3);

    /* Word Length */
    temp |= (pUSARTHandle->USART_Config.USART_WordLength << 12);

    /* Parity */
    if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
        temp |= (1 << 10);
    else if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD)
        temp |= (1 << 10) | (1 << 9);

    pUSARTHandle->pUSARTx->CR1 = temp;

    /* Configure stop bits */
    pUSARTHandle->pUSARTx->CR2 |=
        (pUSARTHandle->USART_Config.USART_NoOfStopBits << 12);

    /* Example BRR for 16MHz PCLK and 9600 baud */
    pUSARTHandle->pUSARTx->BRR = 0x0683;

    /* Enable USART */
    pUSARTHandle->pUSARTx->CR1 |= (1 << 13);
}

uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx, uint8_t StatusFlagName)
{
    if(pUSARTx->SR & StatusFlagName)
        return SET;

    return RESET;
}

void USART_SendData(USART_Handle_t *pUSARTHandle,
                    uint8_t *pTxBuffer,
                    uint32_t Len)
{
    while(Len)
    {
        while(USART_GetFlagStatus(pUSARTHandle->pUSARTx,
                                  USART_FLAG_TXE) == RESET);

        pUSARTHandle->pUSARTx->DR = (*pTxBuffer & 0xFF);

        pTxBuffer++;
        Len--;
    }

    while(USART_GetFlagStatus(pUSARTHandle->pUSARTx,
                              USART_FLAG_TC) == RESET);
}

void USART_ReceiveData(USART_Handle_t *pUSARTHandle,
                       uint8_t *pRxBuffer,
                       uint32_t Len)
{
    while(Len)
    {
        while(USART_GetFlagStatus(pUSARTHandle->pUSARTx,
                                  USART_FLAG_RXNE) == RESET);

        *pRxBuffer = (uint8_t)(pUSARTHandle->pUSARTx->DR & 0xFF);

        pRxBuffer++;
        Len--;
    }
}

void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE)
        pUSARTx->CR1 |= (1 << 13);
    else
        pUSARTx->CR1 &= ~(1 << 13);
}

void USART_DeInit(USART_RegDef_t *pUSARTx)
{
    /* RCC reset macro can be added here */
}
