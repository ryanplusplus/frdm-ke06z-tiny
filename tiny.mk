LIBS := tiny $(LIBS)

tiny_LIB_ROOT := lib/tiny

tiny_ASFLAGS := $(ASFLAGS)
tiny_CPPFLAGS := $(CPPFLAGS)
tiny_CFLAGS := $(CFLAGS)
tiny_CXXFLAGS := $(CXXFLAGS)

tiny_CPPFLAGS += \
  -DNDEBUG \
  -Wno-unused-parameter \
  -Wno-expansion-to-defined \
  -Wno-old-style-declaration \

tiny_INC_DIRS := \
  lib/tiny/include \

tiny_LIB_DIRS := \
  lib/tiny/src \
