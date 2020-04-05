TARGET = tiny
BUILD_DIR ?= ./build/nucleo-g031k8

CPU := cortex-m0plus
ARCH := armv6-m
OPENOCD_CFG := openocd/nucleo-g031k8
LINKER_CFG := ld/nucleo-g031k8.ld

DEFINES := \
  STM32G031xx \

SRC_DIRS := \
  src/app/nucleo-g031k8 \

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
  lib/tiny/include \

include makefile-worker.mk
