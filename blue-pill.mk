TARGET = tiny
BUILD_DIR ?= ./build/blue-pill

CPU := cortex-m3
ARCH := armv7-m
OPENOCD_CFG := openocd/blue-pill
LINKER_CFG := ld/blue-pill.ld

DEFINES := \
  STM32F103xB \
  HSE_VALUE=8000000 \

SRC_DIRS := \
  src/app/blue-pill \

LIB_FILES := \
  lib/stm32cube/CMSIS/STM32F1xx/src/system_stm32f1xx.c \

LIB_DIRS := \
  lib/tiny/src \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \

INC_DIRS := \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32F1xx/inc \
  lib/stm32cube/HAL/STM32F1xx/inc \
  lib/tiny/include \

include makefile-worker.mk
