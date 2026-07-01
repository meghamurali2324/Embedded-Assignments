/*
 * stm32f446xx.h
 *
 *  Created on: June 1, 2026
 *      Author: megha
 */



#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

/*********************************************************************
 * Generic Macros
 *********************************************************************/

#define __vo volatile

#define ENABLE      1
#define DISABLE     0
#define SET         ENABLE
#define RESET       DISABLE

/*********************************************************************
 * Cortex M4 Processor Memory Map
 *********************************************************************/

#define FLASH_BASEADDR      0x08000000U
#define SRAM1_BASEADDR      0x20000000U
#define SRAM2_BASEADDR      0x2001C000U
#define ROM_BASEADDR        0x1FFF0000U

/*********************************************************************
 * Bus Base Addresses
 *********************************************************************/

#define PERIPH_BASE         0x40000000U
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     0x40010000U
#define AHB1PERIPH_BASE     0x40020000U
#define AHB2PERIPH_BASE     0x50000000U

/*********************************************************************
 * AHB1 Peripheral Base Addresses
 *********************************************************************/

#define GPIOA_BASEADDR      (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR      (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR      (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR      (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR      (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR      (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR      (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR      (AHB1PERIPH_BASE + 0x1C00)

#define RCC_BASEADDR        (AHB1PERIPH_BASE + 0x3800)


#define SPI2_BASEADDR      (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR      (APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR    (APB1PERIPH_BASE + 0x4400)

#define I2C1_BASEADDR      (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR      (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR      (APB1PERIPH_BASE + 0x5C00)


#define SPI1_BASEADDR      (APB2PERIPH_BASE + 0x3000)

#define USART1_BASEADDR    (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR    (APB2PERIPH_BASE + 0x1400)

#define SYSCFG_BASEADDR    (APB2PERIPH_BASE + 0x3800)
#define EXTI_BASEADDR      (APB2PERIPH_BASE + 0x3C00)


/* SPI */
#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()     (RCC->APB1ENR |= (1<<15))

/* I2C */
#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR |= (1<<23))

/* USART */
#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1<<17))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1<<5))

/*********************************************************************
 * GPIO Register Definition Structure
 *********************************************************************/

typedef struct
{
    __vo uint32_t MODER;
    __vo uint32_t OTYPER;
    __vo uint32_t OSPEEDR;
    __vo uint32_t PUPDR;
    __vo uint32_t IDR;
    __vo uint32_t ODR;
    __vo uint32_t BSRR;
    __vo uint32_t LCKR;
    __vo uint32_t AFR[2];

}GPIO_RegDef_t;

/*********************************************************************
 * RCC Register Definition Structure
 *********************************************************************/

typedef struct
{
    __vo uint32_t CR;
    __vo uint32_t PLLCFGR;
    __vo uint32_t CFGR;
    __vo uint32_t CIR;
    __vo uint32_t AHB1RSTR;
    __vo uint32_t AHB2RSTR;
    __vo uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    __vo uint32_t APB1RSTR;
    __vo uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    __vo uint32_t AHB1ENR;
    __vo uint32_t AHB2ENR;
    __vo uint32_t AHB3ENR;
    uint32_t RESERVED2;
    __vo uint32_t APB1ENR;
    __vo uint32_t APB2ENR;
    uint32_t RESERVED3[2];
    __vo uint32_t AHB1LPENR;
    __vo uint32_t AHB2LPENR;
    __vo uint32_t AHB3LPENR;
    uint32_t RESERVED4;
    __vo uint32_t APB1LPENR;
    __vo uint32_t APB2LPENR;
    uint32_t RESERVED5[2];
    __vo uint32_t BDCR;
    __vo uint32_t CSR;
    uint32_t RESERVED6[2];
    __vo uint32_t SSCGR;
    __vo uint32_t PLLI2SCFGR;
    __vo uint32_t PLLSAICFGR;
    __vo uint32_t DCKCFGR;
    __vo uint32_t CKGATENR;
    __vo uint32_t DCKCFGR2;

}RCC_RegDef_t;


typedef struct
{
    __vo uint32_t CR1;
    __vo uint32_t CR2;
    __vo uint32_t SR;
    __vo uint32_t DR;
    __vo uint32_t CRCPR;
    __vo uint32_t RXCRCR;
    __vo uint32_t TXCRCR;
    __vo uint32_t I2SCFGR;
    __vo uint32_t I2SPR;
} SPI_RegDef_t;

typedef struct
{
    __vo uint32_t CR1;
    __vo uint32_t CR2;
    __vo uint32_t OAR1;
    __vo uint32_t OAR2;
    __vo uint32_t DR;
    __vo uint32_t SR1;
    __vo uint32_t SR2;
    __vo uint32_t CCR;
    __vo uint32_t TRISE;
    __vo uint32_t FLTR;
} I2C_RegDef_t;

typedef struct
{
    __vo uint32_t SR;
    __vo uint32_t DR;
    __vo uint32_t BRR;
    __vo uint32_t CR1;
    __vo uint32_t CR2;
    __vo uint32_t CR3;
    __vo uint32_t GTPR;
} USART_RegDef_t;



/*********************************************************************
 * Peripheral Definitions
 *********************************************************************/

#define GPIOA      ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB      ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC      ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD      ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE      ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF      ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG      ((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH      ((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC        ((RCC_RegDef_t *)RCC_BASEADDR)


#define SPI1   ((SPI_RegDef_t *)SPI1_BASEADDR)
#define SPI2   ((SPI_RegDef_t *)SPI2_BASEADDR)
#define SPI3   ((SPI_RegDef_t *)SPI3_BASEADDR)

#define I2C1   ((I2C_RegDef_t *)I2C1_BASEADDR)
#define I2C2   ((I2C_RegDef_t *)I2C2_BASEADDR)
#define I2C3   ((I2C_RegDef_t *)I2C3_BASEADDR)

#define USART1 ((USART_RegDef_t *)USART1_BASEADDR)
#define USART2 ((USART_RegDef_t *)USART2_BASEADDR)
#define USART6 ((USART_RegDef_t *)USART6_BASEADDR)

/*
 * RCC Clock Enable Macros
*/

#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()    (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()    (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1<<7))

/*
 * RCC Clock Disable Macros
 */

#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1<<7))


#endif /* INC_STM32F446XX_H_ */
