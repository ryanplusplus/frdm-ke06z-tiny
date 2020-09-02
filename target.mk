TARGET = tiny
BUILD_DIR ?= ./build

CPU := cortex-m0
ARCH := armv6-m
OPENOCD_CFG := openocd
LINKER_CFG := linker.ld

DEFINES := \
  CPU_MKE06Z128VLK4 \
  __NO_SYSTEM_INIT \

SRC_FILES := \

SRC_DIRS := \
  src \

  # src/hardware \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \

INC_DIRS := \
  lib/tiny/include \
  lib/tiny/include/hal \

include makefile-worker.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
