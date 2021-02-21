BUILD_DEPS += $(MAKEFILE_LIST)
BUILD_DEPS := $(BUILD_DEPS)

SRCS := $(SRC_FILES)

ifneq ($(SRC_DIRS),)
SRCS += $(shell find $(SRC_DIRS) -maxdepth 1 -name *.c -or -name *.s -or -name *.S)
endif

LIB_SRCS := $(LIB_FILES)

ifneq ($(LIB_DIRS),)
LIB_SRCS += $(shell find $(LIB_DIRS) -maxdepth 1 -name *.c -or -name *.s -or -name *.S)
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(SRCS:%=$(BUILD_DIR)/%.d)
LIB_OBJS := $(LIB_SRCS:%=$(BUILD_DIR)/%.o)
LIB_DEPS := $(LIB_SRCS:%=$(BUILD_DIR)/%.d)

$(TARGET)_LIB_OBJS := $(LIB_OBJS)

INC_DIRS += $(shell find $(SRC_DIRS) -maxdepth 1 -type d)
ifneq ($(LIB_DIRS),)
INC_DIRS += $(shell find $(LIB_DIRS) -maxdepth 1 -type d)
endif

INC_FLAGS := $(addprefix -iquote,$(INC_DIRS))
DEFINE_FLAGS := $(addprefix -D,$(DEFINES))

CPPFLAGS := \
  $(INC_FLAGS) \
  $(DEFINE_FLAGS) \
  $(CPPFLAGS) \

COMMA :=,
LDFLAGS := \
  $(addprefix -Wl$(COMMA),$(LDFLAGS)) \

LDLIBS := \
  $(BUILD_DIR)/$(TARGET).lib \
	$(LDLIBS) \

CC      := arm-none-eabi-gcc
CXX     := arm-none-eabi-g++
AS      := arm-none-eabi-as
LD      := arm-none-eabi-gcc
AR      := arm-none-eabi-ar
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size
MKDIR_P ?= mkdir -p

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex
	@$(SIZE) $<

$(BUILD_DIR)/openocd.cfg: $(OPENOCD_CFG)/debug.cfg
	@cp @< $@

$(BUILD_DIR)/$(TARGET).svd: $(SVD)
	@cp $(SVD) $@

.PHONY: debug-deps
debug-deps: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/openocd.cfg $(BUILD_DIR)/$(TARGET).svd

.PHONY: upload
upload: $(BUILD_DIR)/$(TARGET).hex
	@openocd -f $(OPENOCD_CFG)/upload.cfg

.PHONY: erase
erase:
	@openocd -f $(OPENOCD_CFG)/erase.cfg

$(BUILD_DIR)/$(TARGET).elf: $(OBJS) $(LDLIBS)
	@echo Linking $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(LD) -T $(LINKER_CFG) $(CPPFLAGS) $(LDFLAGS) $(OBJS) -Wl,--start-group $(LDLIBS) -Wl,--end-group -o $@

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	@echo Creating $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(OBJCOPY) -O ihex $< $@

# $1 lib name
define generate_lib_rule

$$(BUILD_DIR)/$(1).lib: $$($1_LIB_OBJS)
	@echo Building $$(notdir $$@)...
	@$$(MKDIR_P) $$(dir $$@)
	@$$(AR) rcs $$@ $$^

endef

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

$(eval $(call generate_lib_rule,$(TARGET)))
$(eval $(call generate_compilation_rules,,$(ASFLAGS),$(CPPFLAGS),$(CFLAGS),$(CXXFLAGS)))

.PHONY: clean
clean:
	@echo Cleaning...
	@$(RM) -rf $(BUILD_DIR)


-include $(DEPS) $(LIB_DEPS)
