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
  lib/st/stm32g0xx/CMSIS/Device/ST/STM32G0xx/Source/Templates/system_stm32g0xx.c \

LIB_DIRS := \
  lib/tiny/src \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \

INC_DIRS := \
  lib/st/stm32g0xx/CMSIS/Include \
  lib/st/stm32g0xx/CMSIS/Device/ST/STM32G0xx/Include \
  lib/st/stm32g0xx/STM32G0xx_HAL_Driver/Inc \

include makefile-worker.mk
