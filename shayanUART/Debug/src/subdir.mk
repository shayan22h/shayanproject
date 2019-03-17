################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpioinit.c \
../src/main.c \
../src/stm32f4xx_it.c \
../src/stm32fxx_hal_msp.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/gpioinit.o \
./src/main.o \
./src/stm32f4xx_it.o \
./src/stm32fxx_hal_msp.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/gpioinit.d \
./src/main.d \
./src/stm32f4xx_it.d \
./src/stm32fxx_hal_msp.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F429ZITx -DNUCLEO_F429ZI -DDEBUG -DSTM32F429xx -DUSE_HAL_DRIVER -I"C:/Users/shaya/OneDrive/Desktop/shayan git/shayanproject/shayanUART/HAL_Driver/Inc/Legacy" -I"C:/Users/shaya/OneDrive/Desktop/shayan git/shayanproject/shayanUART/Utilities/STM32F4xx_Nucleo_144" -I"C:/Users/shaya/OneDrive/Desktop/shayan git/shayanproject/shayanUART/inc" -I"C:/Users/shaya/OneDrive/Desktop/shayan git/shayanproject/shayanUART/CMSIS/device" -I"C:/Users/shaya/OneDrive/Desktop/shayan git/shayanproject/shayanUART/CMSIS/core" -I"C:/Users/shaya/OneDrive/Desktop/shayan git/shayanproject/shayanUART/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


