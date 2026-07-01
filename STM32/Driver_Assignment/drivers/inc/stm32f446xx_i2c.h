/*
 * stm32f446xx_i2c.h
 *
 *  Created on: June 1, 2026
 *      Author: megha
 */

#ifndef INC_STM32F446XX_I2C_H_
#define INC_STM32F446XX_I2C_H_



#include "stm32f446xx.h"

/*********************************************************************
 * I2C Configuration Structure
 *********************************************************************/
typedef struct
{
	uint32_t I2C_SCLSpeed;
	uint8_t  I2C_DeviceAddress;
	uint8_t  I2C_ACKControl;
	uint16_t I2C_FMDutyCycle;

}I2C_Config_t;

/*********************************************************************
 * I2C Handle Structure
 *********************************************************************/
typedef struct
{
	I2C_RegDef_t *pI2Cx;
	I2C_Config_t I2C_Config;

}I2C_Handle_t;

/*********************************************************************
 * ACK Control
 *********************************************************************/
#define I2C_ACK_ENABLE      ENABLE
#define I2C_ACK_DISABLE     DISABLE

/*********************************************************************
 * I2C SCL Speed
 *********************************************************************/
#define I2C_SCL_SPEED_SM    100000U
#define I2C_SCL_SPEED_FM2K  200000U
#define I2C_SCL_SPEED_FM4K  400000U

/*********************************************************************
 * Fast Mode Duty Cycle
 *********************************************************************/
#define I2C_FM_DUTY_2       0
#define I2C_FM_DUTY_16_9    1

/*********************************************************************
 * I2C Status Flags
 *********************************************************************/
#define I2C_FLAG_SB         (1<<0)
#define I2C_FLAG_ADDR       (1<<1)
#define I2C_FLAG_BTF        (1<<2)
#define I2C_FLAG_STOPF      (1<<4)
#define I2C_FLAG_RXNE       (1<<6)
#define I2C_FLAG_TXE        (1<<7)
#define I2C_FLAG_BUSY       (1<<1)

/*********************************************************************
 * APIs
 *********************************************************************/
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx,uint8_t EnOrDi);

void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

void I2C_MasterSendData(I2C_Handle_t *pI2CHandle,
						uint8_t *pTxBuffer,
						uint32_t Len,
						uint8_t SlaveAddr);

void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,
						   uint8_t *pRxBuffer,
						   uint32_t Len,
						   uint8_t SlaveAddr);

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx,uint8_t EnOrDi);

uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx,uint32_t FlagName);



#endif /* INC_STM32F446XX_I2C_H_ */
