TARGET ?= stm32-tiny
BUILD_DIR ?= ./build

CPU := cortex-m4
ARCH := armv7e-m

DEFINES := \
  STM32F303xC \
  HSE_VALUE=8000000 \
  USE_STDPERIPH_DRIVER \

SRC_DIRS := \
  src \

LIB_FILES := \
	lib/st/CMSIS/Device/ST/STM32F30x/Source/Templates/system_stm32f30x.c \

LIB_DIRS := \
  lib/tiny/src \
  lib/st/STM32F30x_StdPeriph_Driver/src \

INC_DIRS := \
  lib/st/CMSIS/Include \
  lib/st/CMSIS/Device/ST/STM32F30x/Include \
  lib/st/STM32F30x_StdPeriph_Driver/inc \

include makefile-worker.mk
