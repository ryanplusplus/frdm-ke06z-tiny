LIB_THINGS := fsl $(LIB_THINGS)

fsl_LIB_ROOT := lib/nxp/$(SDK)/devices/MKE06Z4/drivers/

# Temporary, this should be moved into the worker
LDLIBS := $(BUILD_DIR)/fsl.lib $(LDLIBS)

fsl_ASFLAGS := $(ASFLAGS)
fsl_CPPFLAGS := $(CPPFLAGS)
fsl_CFLAGS := $(CFLAGS)
fsl_CXXFLAGS := $(CXXFLAGS)

fsl_CPPFLAGS += \
  -DNDEBUG \
  -Wno-unused-parameter \
  -Wno-expansion-to-defined \
  -Wno-old-style-declaration \

fsl_INC_DIRS := \
  lib/nxp/$(SDK)/CMSIS/Include \
  lib/nxp/$(SDK)/devices/MKE06Z4 \

fsl_LIB_DIRS := \
  lib/nxp/$(SDK)/devices/MKE06Z4/drivers \
