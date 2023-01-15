################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer_0/Timer_0_Program.c 

OBJS += \
./MCAL/Timer_0/Timer_0_Program.o 

C_DEPS += \
./MCAL/Timer_0/Timer_0_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer_0/%.o: ../MCAL/Timer_0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL\Timer_1" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\Lib" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\KeyPad" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL\Timer_0" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\TempSensor" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\Ssd" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL\ADC" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL\GIE" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL\Ext_Int" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\PushButton" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\LCD" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\BUZZER" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\APP" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\MCAL\DIO" -I"C:\Users\Mazin.DESKTOP-QR6VN6E\OneDrive\Desktop\lec2\HAL\LED" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


