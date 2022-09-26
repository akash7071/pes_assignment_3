################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Assignment3_final.c \
../source/delay.c \
../source/led.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/sequence.c 

C_DEPS += \
./source/Assignment3_final.d \
./source/delay.d \
./source/led.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/sequence.d 

OBJS += \
./source/Assignment3_final.o \
./source/delay.o \
./source/led.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/sequence.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final\board" -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final\source" -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final" -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final\drivers" -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final\CMSIS" -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final\utilities" -I"C:\Users\akash7071\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Assignment3_final\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Assignment3_final.d ./source/Assignment3_final.o ./source/delay.d ./source/delay.o ./source/led.d ./source/led.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/sequence.d ./source/sequence.o

.PHONY: clean-source

