TARGET = tiny
BUILD_DIR ?= ./build/stm32vl-discovery

CPU := cortex-m3
ARCH := armv7-m
OPENOCD_CFG := openocd/stm32vl-discovery
LINKER_CFG := ld/stm32vl-discovery.ld

DEFINES := \
  STM32F100xB \
  HSE_VALUE=8000000 \

SRC_DIRS := \
  src/app/stm32vl-discovery \

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
