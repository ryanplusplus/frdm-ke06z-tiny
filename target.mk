TARGET = tiny
BUILD_DIR ?= ./build

CPU := cortex-m0
ARCH := armv6-m
OPENOCD_CFG := openocd
LINKER_CFG := linker.ld
USE_SYSTEM_VIEW := Y

DEFINES := \
  STM32F051x8 \
  HSE_VALUE=8000000 \

ifeq ($(USE_SYSTEM_VIEW),Y)
FREERTOS := lib/patched/FreeRTOS-Kernel
else
FREERTOS := lib/FreeRTOS-Kernel
endif

SRC_FILES := \

SRC_DIRS := \
  $(FREERTOS) \
  $(FREERTOS)/portable/GCC/ARM_CM0 \
  src \
  src/app \
  src/hardware \

LIB_FILES := \
  lib/stm32cube/CMSIS/STM32F0xx/src/system_stm32f0xx.c \

LIB_DIRS := \
  lib/tiny/src \

INC_DIRS := \
  $(FREERTOS)/include \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32F0xx/inc \
  lib/stm32cube/HAL/STM32F0xx/inc \
  lib/tiny/include \

IGNORE := $(shell $(MAKE) --no-print-directory -f patch.mk)

include makefile-worker.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
