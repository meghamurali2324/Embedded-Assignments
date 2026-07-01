################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/inc/stm32f446xx_gpio.c 

OBJS += \
./drivers/inc/stm32f446xx_gpio.o 

C_DEPS += \
./drivers/inc/stm32f446xx_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/inc/%.o drivers/inc/%.su drivers/inc/%.cyclo: ../drivers/inc/%.c drivers/inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/megha/OneDrive/Desktop/Embedded_Assignments/STM32/Driver_Assignment/drivers/inc" -I"C:/Users/megha/OneDrive/Desktop/Embedded_Assignments/STM32/Driver_Assignment/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-inc

clean-drivers-2f-inc:
	-$(RM) ./drivers/inc/stm32f446xx_gpio.cyclo ./drivers/inc/stm32f446xx_gpio.d ./drivers/inc/stm32f446xx_gpio.o ./drivers/inc/stm32f446xx_gpio.su

.PHONY: clean-drivers-2f-inc

