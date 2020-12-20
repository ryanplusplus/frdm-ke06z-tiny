TARGET = tiny
BUILD_DIR ?= ./build

CPU := cortex-m0
ARCH := armv6-m
OPENOCD_CFG := openocd
LINKER_CFG := linker.ld

SDK := SDK_2.8.0_FRDM-KE06Z

DEFINES := \
  CPU_MKE06Z128VLK4 \
  __NO_SYSTEM_INIT \
  __STARTUP_CLEAR_BSS \
  NDEBUG \

SRC_FILES := \

SRC_DIRS := \
  lib/nxp/$(SDK)/devices/MKE06Z4 \
  src \
  src/hardware \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \
  lib/nxp/$(SDK)/devices/MKE06Z4/drivers/ \

INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Include \
  lib/tiny/include \
  lib/tiny/include/hal \

include target-worker.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
