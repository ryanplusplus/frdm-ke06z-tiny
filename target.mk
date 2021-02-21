TARGET = target
BUILD_DIR ?= ./build

CPU := cortex-m0
ARCH := armv6-m
OPENOCD_CFG_DIR := openocd
LINKER_CFG := linker.ld

SDK := SDK_2.9.0_FRDM-KE06Z
SVD := lib/nxp/$(SDK)/devices/MKE06Z4/MKE06Z4.xml

DEFINES := \
  CPU_MKE06Z128VLK4 \
  __NO_SYSTEM_INIT \
  __STARTUP_CLEAR_BSS \

ASFLAGS := \
  -mcpu=$(CPU) \
  -march=$(ARCH) \
  -mthumb \
  -g2 \

CPPFLAGS := \
  --specs=nano.specs \
  -mcpu=$(CPU) \
  -march=$(ARCH) \
  -mthumb \
  -g \
  -g2 \
  -Os \
  $(addprefix -D,$(DEFINES)) \
  -fdata-sections \
  -ffunction-sections \
  -Wall \
  -Wextra \
  -Werror \
  -Wfatal-errors \

CFLAGS := \
  -std=c99 \

CXXFLAGS := \
  -fno-rtti \
  -fno-exceptions \
  -fno-non-call-exceptions \
  -fno-use-cxa-atexit \
  -Weffc++ \
  -std=c++17 \

LDFLAGS := \
  -Og \
  --gc-sections \
  -Map=$(BUILD_DIR)/$(TARGET).map \

SRC_FILES := \

SRC_DIRS := \
  lib/nxp/$(SDK)/devices/MKE06Z4 \
  src \
  src/hardware \

INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Include \
  lib/tiny/include \
  lib/tiny/include/hal \

include lib_fsl.mk
include lib_tiny.mk

include tools/tools.mk

.PHONY: watch
watch:
	@rerun "$(MAKE) --no-print-directory -f $(firstword $(MAKEFILE_LIST))"
