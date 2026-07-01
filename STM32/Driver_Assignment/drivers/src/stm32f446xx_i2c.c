/*
 * stm32f446xx_i2c.c
 *
 *  Created on: June 1, 2026
 *      Author: megha
 */


/*
 * stm32f446re_i2c_driver.c
 */

#include "stm32f446xx_i2c.h"

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE)
    {
        if(pI2Cx == I2C1) I2C1_PCLK_EN();
        else if(pI2Cx == I2C2) I2C2_PCLK_EN();
        else if(pI2Cx == I2C3) I2C3_PCLK_EN();
    }
}

void I2C_Init(I2C_Handle_t *pI2CHandle)
{
    pI2CHandle->pI2Cx->CR1 |= (1 << 15);   // Software reset
    pI2CHandle->pI2Cx->CR1 &= ~(1 << 15);

    pI2CHandle->pI2Cx->CR2 = 16;           // APB1 = 16 MHz
    pI2CHandle->pI2Cx->CCR = 80;           // 100 kHz
    pI2CHandle->pI2Cx->TRISE = 17;

    if(pI2CHandle->I2C_Config.I2C_ACKControl == I2C_ACK_ENABLE)
        pI2CHandle->pI2Cx->CR1 |= (1 << 10);

    pI2CHandle->pI2Cx->CR1 |= (1 << 0);    // Peripheral Enable
}

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE)
        pI2Cx->CR1 |= (1 << 0);
    else
        pI2Cx->CR1 &= ~(1 << 0);
}

uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint32_t FlagName)
{
    return ((pI2Cx->SR1 & FlagName) ? SET : RESET);
}

void I2C_MasterSendData(I2C_Handle_t *pI2CHandle,
                        uint8_t *pTxBuffer,
                        uint32_t Len,
                        uint8_t SlaveAddr)
{
    I2C_RegDef_t *pI2Cx = pI2CHandle->pI2Cx;

    pI2Cx->CR1 |= (1 << 8);                 // START
    while(!(pI2Cx->SR1 & (1 << 0)));        // SB

    pI2Cx->DR = (SlaveAddr << 1);

    while(!(pI2Cx->SR1 & (1 << 1)));        // ADDR
    (void)pI2Cx->SR1;
    (void)pI2Cx->SR2;

    while(Len)
    {
        while(!(pI2Cx->SR1 & (1 << 7)));    // TXE
        pI2Cx->DR = *pTxBuffer++;
        Len--;
    }

    while(!(pI2Cx->SR1 & (1 << 2)));        // BTF
    pI2Cx->CR1 |= (1 << 9);                 // STOP
}

void I2C_DeInit(I2C_RegDef_t *pI2Cx)
{
    /* User can implement RCC reset here */
}

void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,
                           uint8_t *pRxBuffer,
                           uint32_t Len,
                           uint8_t SlaveAddr)
{
    /* Receive API can be implemented similarly */
}
