BUILD_DEPS := $(BUILD_DEPS) $(MAKEFILE_LIST)

SRCS := $(SRC_FILES)

ifneq ($(SRC_DIRS),)
SRCS += $(shell find $(SRC_DIRS) -maxdepth 1 -name *.c -or -name *.s -or -name *.S)
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(SRCS:%=$(BUILD_DIR)/%.d)

INC_DIRS += $(shell find $(SRC_DIRS) -maxdepth 1 -type d)

INC_FLAGS := $(addprefix -iquote,$(INC_DIRS))
DEFINE_FLAGS := $(addprefix -D,$(DEFINES))

CPPFLAGS := \
  $(INC_FLAGS) \
  $(CPPFLAGS) \

COMMA :=,
LDFLAGS := \
  $(addprefix -Wl$(COMMA),$(LDFLAGS)) \

LDLIBS := \
	$(foreach _lib,$(LIBS),$(BUILD_DIR)/$(_lib).lib) \
	$(LDLIBS) \

CC      := arm-none-eabi-gcc
CXX     := arm-none-eabi-g++
AS      := arm-none-eabi-as
LD      := arm-none-eabi-gcc
AR      := arm-none-eabi-ar
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size
MKDIR_P ?= mkdir -p

# $1 prefix
# $2 ASFLAGS
# $3 CPPFLAGS
# $4 CFLAGS
# $5 CXXFLAGS
define generate_compilation_rules

$$(BUILD_DIR)/$(1)%.s.o: $(1)%.s $$(BUILD_DEPS)
	@echo Assembling $$(notdir $$@)...
	@$$(MKDIR_P) $$(dir $$@)
	@$$(AS) $(2) $$< -o $$@

$$(BUILD_DIR)/$(1)%.S.o: $(1)%.S $$(BUILD_DEPS)
	@echo Assembling $$(notdir $$@)...
	@$$(MKDIR_P) $$(dir $$@)
	@$$(CC) -c $(2) $$< $(3) -o $$@

$$(BUILD_DIR)/$(1)%.c.o: $(1)%.c $$(BUILD_DEPS)
	@echo Compiling $$(notdir $$@)...
	@$$(MKDIR_P) $$(dir $$@)
	@$$(CC) -MM -MP -MF "$$(@:%.o=%.d)" -MT "$$@" $(3) $(4) -E $$<
	@$$(CC) -x c $(3) $(4) -c $$< -o $$@

$$(BUILD_DIR)/$(1)%.cpp.o: $(1)%.cpp $$(BUILD_DEPS)
	@echo Compiling $$(notdir $$@)...
	@$$(MKDIR_P) $$(dir $$@)
	@$$(CXX) -MM -MP -MF "$$(@:%.o=%.d)" -MT "$$@" $(3) $(5) -E $$<
	@$$(CXX) -x c++ $(3) $(5) -c $$< -o $$@

endef

# $1 lib name
define generate_lib

$(1)_INC_DIRS += $$(shell find $$($(1)_LIB_DIRS) -maxdepth 1 -type d)
$(1)_INC_FLAGS := $$(addprefix -iquote,$$($(1)_INC_DIRS))

$(1)_CPPFLAGS := \
  $$($(1)_INC_FLAGS) \
  $$($(1)_CPPFLAGS) \

$(1)_LIB_SRCS := $$($(1)_LIB_FILES)

ifneq ($$($(1)_LIB_DIRS),)
$(1)_LIB_SRCS += $$(shell find $$($(1)_LIB_DIRS) -maxdepth 1 -name *.c -or -name *.s -or -name *.S)
endif

$(1)_LIB_OBJS := $$($(1)_LIB_SRCS:%=$$(BUILD_DIR)/%.o)
$(1)_LIB_DEPS := $$($(1)_LIB_SRCS:%=$$(BUILD_DIR)/%.d)

DEPS := $(DEPS) $(1)_LIB_DEPS

$$(BUILD_DIR)/$(1).lib: $$($1_LIB_OBJS)
	@echo Building $$(notdir $$@)...
	@$$(MKDIR_P) $$(dir $$@)
	@$$(AR) rcs $$@ $$^

$$(eval $$(call generate_compilation_rules,$$($(1)_LIB_ROOT),$$($(1)_ASFLAGS),$$($(1)_CPPFLAGS),$$($(1)_CFLAGS),$$($(1)_CXXFLAGS)))

endef

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex
	@$(SIZE) $<

$(foreach _lib,$(LIBS),$(eval $(call generate_lib,$(_lib))))

$(BUILD_DIR)/$(TARGET).elf: $(OBJS) $(LDLIBS)
	@echo Linking $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(LD) -T $(LINKER_CFG) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -Wl,--start-group $(LDLIBS) -Wl,--end-group -o $@

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	@echo Creating $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(OBJCOPY) -O ihex $< $@

$(eval $(call generate_compilation_rules,,$(ASFLAGS),$(CPPFLAGS),$(CFLAGS),$(CXXFLAGS)))

.PHONY: clean
clean:
	@echo Cleaning...
	@$(RM) -rf $(BUILD_DIR)

-include $(DEPS)
