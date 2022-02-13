$(call create_lib_with_defaults,fsl)

DEFINES += NDEBUG

fsl_DEFINES := $(DEFINES)

fsl_CPPFLAGS += \
  -Wno-pedantic \
  -Wno-unused-parameter \
  -Wno-expansion-to-defined \
  -Wno-old-style-declaration \
  -Wno-overflow

fsl_INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Core/Include \
  lib/nxp/$(SDK)/devices/$(DEVICE) \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

fsl_SYS_INC_DIRS := \

fsl_SRC_FILES := \

fsl_SRC_DIRS := \
  lib/nxp/$(SDK)/devices/$(DEVICE)/drivers \

SRC_FILES += \
  lib/nxp/$(SDK)/devices/$(DEVICE)/system_$(DEVICE).c \

INC_DIRS += \
  $(fsl_INC_DIRS) \

CPPFLAGS += \
  -Wno-pedantic \
