################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer_1/subdir.mk
-include MCAL/Timer_0/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/Ext_Int/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TempSensor/subdir.mk
-include HAL/Ssd/subdir.mk
-include HAL/PushButton/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KeyPad/subdir.mk
-include HAL/BUZZER/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
lec2.lss \

FLASH_IMAGE += \
lec2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: lec2.elf secondary-outputs

# Tool invocations
lec2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lec2.map -mmcu=atmega32 -o "lec2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lec2.lss: lec2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lec2.elf  >"lec2.lss"
	@echo 'Finished building: $@'
	@echo ' '

lec2.hex: lec2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lec2.elf  "lec2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lec2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t lec2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lec2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
