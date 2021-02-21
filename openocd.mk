.PHONY: debug-deps
debug-deps: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/openocd.cfg $(BUILD_DIR)/$(TARGET).svd

.PHONY: upload
upload: $(BUILD_DIR)/$(TARGET).hex
	@openocd -f $(OPENOCD_CFG)/upload.cfg

.PHONY: erase
erase:
	@openocd -f $(OPENOCD_CFG)/erase.cfg

$(BUILD_DIR)/$(TARGET).svd: $(SVD)
	@cp $(SVD) $@

$(BUILD_DIR)/openocd.cfg: $(OPENOCD_CFG)/debug.cfg
	@cp @< $@
