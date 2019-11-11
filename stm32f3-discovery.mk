TARGET = tiny
BUILD_DIR ?= ./build/stm32f3-discovery

CPU := cortex-m4
ARCH := armv7e-m
OPENOCD_CFG := openocd/stm32f3-discovery
LINKER_CFG := ld/stm32f3-discovery.ld

DEFINES := \
  STM32F303xC \
  HSE_VALUE=8000000 \

SRC_DIRS := \
  src/app/stm32f3-discovery \

LIB_FILES := \
  lib/st/stm32f3xx/CMSIS/Device/ST/STM32F3xx/Source/Templates/system_stm32f3xx.c \

LIB_DIRS := \
  lib/tiny/src \
  src/peripheral/cmsis \
  src/peripheral/stm32xxxx \

INC_DIRS := \
  lib/st/stm32f3xx/CMSIS/Include \
  lib/st/stm32f3xx/CMSIS/Device/ST/STM32F3xx/Include \
  lib/st/stm32f3xx/STM32F3xx_HAL_Driver/Inc \

include makefile-worker.mk
