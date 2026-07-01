/*
 * stm32f446xx_spi.c
 *
 *  Created on: June 1, 2026
 *      Author: megha
 */



#include "stm32f446xx_spi.h"

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pSPIx == SPI1) SPI1_PCLK_EN();
        else if(pSPIx == SPI2) SPI2_PCLK_EN();
        else if(pSPIx == SPI3) SPI3_PCLK_EN();
    }
}

void SPI_Init(SPI_Handle_t *pSPIHandle)
{
    uint32_t temp = 0;

    temp |= pSPIHandle->SPIConfig.SPI_DeviceMode << 2;

    if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
        temp &= ~(1 << 15);
    else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
        temp |= (1 << 15);
    else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX)
        temp &= ~(1 << 15), temp |= (1 << 10);

    temp |= (pSPIHandle->SPIConfig.SPI_SclkSpeed << 3);
    temp |= (pSPIHandle->SPIConfig.SPI_DFF << 11);
    temp |= (pSPIHandle->SPIConfig.SPI_CPOL << 1);
    temp |= (pSPIHandle->SPIConfig.SPI_CPHA << 0);
    temp |= (pSPIHandle->SPIConfig.SPI_SSM << 9);

    pSPIHandle->pSPIx->CR1 = temp;
}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
    if(pSPIx->SR & FlagName)
        return SET;

    return RESET;
}

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
    while(Len > 0)
    {
        while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == RESET);

        if(pSPIx->CR1 & (1 << 11))
        {
            pSPIx->DR = *((uint16_t*)pTxBuffer);
            Len -= 2;
            pTxBuffer += 2;
        }
        else
        {
            *((volatile uint8_t*)&pSPIx->DR) = *pTxBuffer;
            Len--;
            pTxBuffer++;
        }
    }
}

void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{
    while(Len > 0)
    {
        while(SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG) == RESET);

        if(pSPIx->CR1 & (1 << 11))
        {
            *((uint16_t*)pRxBuffer) = pSPIx->DR;
            Len -= 2;
            pRxBuffer += 2;
        }
        else
        {
            *pRxBuffer = *((volatile uint8_t*)&pSPIx->DR);
            Len--;
            pRxBuffer++;
        }
    }
}

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
        pSPIx->CR1 |= (1 << 6);
    else
        pSPIx->CR1 &= ~(1 << 6);
}

void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
        pSPIx->CR1 |= (1 << 8);
    else
        pSPIx->CR1 &= ~(1 << 8);
}

void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
        pSPIx->CR2 |= (1 << 2);
    else
        pSPIx->CR2 &= ~(1 << 2);
}
