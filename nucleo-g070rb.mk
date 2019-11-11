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
