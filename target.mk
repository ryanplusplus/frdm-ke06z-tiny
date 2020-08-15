TARGET = tiny
BUILD_DIR ?= ./build

CPU := cortex-m0
ARCH := armv6-m
OPENOCD_CFG := openocd
LINKER_CFG := linker.ld

DEFINES := \
  STM32F051x8 \
  HSE_VALUE=8000000 \

SRC_DIRS := \
  lib/FreeRTOS-Kernel \
  lib/FreeRTOS-Kernel/portable/GCC/ARM_CM0 \
  src \
  src/app \
  src/hardware \

LIB_FILES := \
  lib/stm32cube/CMSIS/STM32F0xx/src/system_stm32f0xx.c \

LIB_DIRS := \
  lib/tiny/src \

INC_DIRS := \
  lib/FreeRTOS-Kernel/include \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32F0xx/inc \
  lib/stm32cube/HAL/STM32F0xx/inc \
  lib/tiny/include \

.PHONY: watch
watch:
	rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"

include makefile-worker.mk
