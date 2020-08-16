.PHONY: all
all: patch_freertos

FREERTOS_SOURCES := $(shell find lib/FreeRTOS-Kernel)

.PHONY: patch_freertos
patch_freertos: lib/patched/FreeRTOS-Kernel/patched

lib/patched/FreeRTOS-Kernel/patched: patch/system-view-freertos-10.3.1.patch $(FREERTOS_SOURCES)
	@echo Patching FreeRTOS
	@rm -rf lib/patched
	@mkdir -p lib/patched
	@cp -r lib/FreeRTOS-Kernel lib/patched/FreeRTOS-Kernel
	@patch -p0 < $<
	@touch $@
