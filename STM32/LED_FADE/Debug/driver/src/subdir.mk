################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/stm32f446xx_gpio.c 

OBJS += \
./driver/src/stm32f446xx_gpio.o 

C_DEPS += \
./driver/src/stm32f446xx_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o driver/src/%.su driver/src/%.cyclo: ../driver/src/%.c driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/megha/OneDrive/Desktop/Embedded_Assignments/STM32/LED_FADE/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-src

clean-driver-2f-src:
	-$(RM) ./driver/src/stm32f446xx_gpio.cyclo ./driver/src/stm32f446xx_gpio.d ./driver/src/stm32f446xx_gpio.o ./driver/src/stm32f446xx_gpio.su

.PHONY: clean-driver-2f-src

