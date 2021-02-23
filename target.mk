TARGET := target
BUILD_DIR := ./build

CPU := cortex-m0
ARCH := armv6-m
LINKER_CFG := linker.ld

DEVICE := MKE06Z4

SDK := SDK_2.9.0_FRDM-KE06Z
SVD := lib/nxp/$(SDK)/devices/$(DEVICE)/$(DEVICE).xml

DEBUG_ADAPTER ?= openocd
OPENOCD_CFG_DIR := openocd
BLACK_MAGIC_PORT ?= /dev/ttyACM0
BLACK_MAGIC_POWER_TARGET ?= N

DEFINES := \
  CPU_MKE06Z128VLK4 \
  __NO_SYSTEM_INIT \
  __STARTUP_CLEAR_BSS \

include tools/defaults.mk

INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Include \

SYS_INC_DIRS := \

SRC_FILES := \
  lib/nxp/$(SDK)/devices/$(DEVICE)/system_$(DEVICE).c \

SRC_DIRS := \
  src \
  src/hardware \

include lib_fsl.mk
include lib_tiny.mk

include tools/tools.mk
include docs.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
