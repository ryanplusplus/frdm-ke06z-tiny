TARGET = tiny
BUILD_DIR ?= ./build/nucleo-g070rb

CPU := cortex-m0plus
ARCH := armv6-m
OPENOCD_CFG := openocd/nucleo-g070rb
LINKER_CFG := ld/nucleo-g070rb.ld

DEFINES := \
  STM32G070xx \

SRC_DIRS := \
  src/app/nucleo-g070rb \

LIB_FILES := \
  lib/stm32cube/CMSIS/STM32G0xx/src/system_stm32g0xx.c \

LIB_DIRS := \
  lib/tiny/src \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \

INC_DIRS := \
  lib/stm32cube/CMSIS/ARM/inc \
  lib/stm32cube/CMSIS/STM32G0xx/inc \
  lib/stm32cube/HAL/STM32G0xx/inc \

include makefile-worker.mk
