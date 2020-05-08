SRCS := $(SRC_FILES)

ifneq ($(SRC_DIRS),)
SRCS += $(shell find $(SRC_DIRS) -name *.c -or -name *.s -or -name *.S)
endif

LIB_SRCS := $(LIB_FILES)

ifneq ($(LIB_DIRS),)
LIB_SRCS += $(shell find $(LIB_DIRS) -name *.c -or -name *.s -or -name *.S)
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(SRCS:%=$(BUILD_DIR)/%.d)
LIB_OBJS := $(LIB_SRCS:%=$(BUILD_DIR)/%.o)
LIB_DEPS := $(LIB_SRCS:%=$(BUILD_DIR)/%.d)

INC_DIRS += $(shell find $(SRC_DIRS) -type d)
ifneq ($(LIB_DIRS),)
INC_DIRS += $(shell find $(LIB_DIRS) -type d)
endif

INC_FLAGS := $(addprefix -I,$(INC_DIRS))
DEFINE_FLAGS := $(addprefix -D,$(DEFINES))

CFLAGS += \
  $(INC_FLAGS) \
  $(DEFINE_FLAGS) \
  -fno-exceptions \
  -fdata-sections \
  -ffunction-sections \
  -nostdlib \
  -Wextra \
  -Werror \
  -Wfatal-errors \
	-Wno-implicit-fallthrough \

LDFLAGS += \
  $(CFLAGS) \

CC      := arm-none-eabi-gcc
AS      := arm-none-eabi-as
LD      := arm-none-eabi-gcc
AR      := arm-none-eabi-ar
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex
	@$(SIZE) $<

$(BUILD_DIR)/openocd.cfg:
	@cp $(OPENOCD_CFG)/debug.cfg $@

.PHONY: debug-deps
debug-deps: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/openocd.cfg

.PHONY: upload
upload: $(BUILD_DIR)/$(TARGET).hex
	@openocd -f $(OPENOCD_CFG)/upload.cfg

.PHONY: erase
erase:
	@openocd -f $(OPENOCD_CFG)/erase.cfg

$(BUILD_DIR)/$(TARGET).elf: $(OBJS) $(BUILD_DIR)/$(TARGET).lib
	@echo Linking $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(LD) $(OBJS) -mcpu=$(CPU) -march=$(ARCH) -mthumb --specs=nano.specs -Wl,-Og -Wl,--gc-sections -Wl,--start-group $(BUILD_DIR)/$(TARGET).lib -Wl,--end-group -o $@ -T $(LINKER_CFG) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	@echo Creating $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(OBJCOPY) -O ihex $< $@

$(BUILD_DIR)/$(TARGET).lib: $(LIB_OBJS)
	@echo Building $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(AR) rcs $@ $^

$(BUILD_DIR)/%.s.o: %.s
	@echo Assembling $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(AS) -g2 -mcpu=$(CPU) -march=$(ARCH) -mthumb $< $(INC_FLAGS) -o $@

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $(notdir $@)...
	@$(MKDIR_P) $(dir $@)
	@$(CC) --specs=nano.specs -MM -MP -MF "$(@:%.o=%.d)" -MT "$(@)" $(CFLAGS) -E $<
	@$(CC) --specs=nano.specs -x c -g -g2 -Os $(CFLAGS) -mcpu=$(CPU) -march=$(ARCH) -mthumb -std=c99 -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning...
	@$(RM) -rf $(BUILD_DIR)

MKDIR_P ?= mkdir -p

-include $(DEPS) $(LIB_DEPS)
