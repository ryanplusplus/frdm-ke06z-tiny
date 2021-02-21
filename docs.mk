HARDWARE_MANUAL_URL := https://www.nxp.com/files-static/microcontrollers/doc/ref_manual/MKE06P80M48SF0RM.pdf
DATASHEET_URL := https://www.nxp.com/docs/en/data-sheet/MKE06P80M48SF0.pdf

.PHONY: hardware_manual
hardware_manual:
	xdg-open $(HARDWARE_MANUAL_URL)

.PHONY: datasheet
datasheet:
	xdg-open $(DATASHEET_URL)
