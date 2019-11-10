TARGET = tiny
BUILD_DIR ?= ./build/f3-discovery

CPU := cortex-m4
ARCH := armv7e-m
OPENOCD_CFG := openocd/f3-discovery

DEFINES := \
  STM32F303xC \
  HSE_VALUE=8000000 \
  USE_STDPERIPH_DRIVER \

SRC_DIRS := \
  src/app/f3-discovery \

LIB_FILES := \
  lib/st/stm32f30x/CMSIS/Device/ST/STM32F30x/Source/Templates/system_stm32f30x.c \

LIB_DIRS := \
  lib/tiny/src \
  lib/st/stm32f30x/STM32F30x_StdPeriph_Driver/src \
  src/peripheral/stm32f30x \

INC_DIRS := \
  lib/st/stm32f30x/CMSIS/Include \
  lib/st/stm32f30x/CMSIS/Device/ST/STM32F30x/Include \
  lib/st/stm32f30x/STM32F30x_StdPeriph_Driver/inc \

include makefile-worker.mk
