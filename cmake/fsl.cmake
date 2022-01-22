add_library(fsl-system INTERFACE)

set(fsl_SDK_DIR ${ROOT}/lib/nxp/${SDK})

target_sources(fsl-system INTERFACE
  ${fsl_SDK_DIR}/devices/${DEVICE}/system_${DEVICE}.c
)

add_library(fsl)

target_sources(fsl PRIVATE
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_acmp.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_adc.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_clock.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_common_arm.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_common.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_flash.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_ftm.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_gpio.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_i2c.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_irq.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_kbi.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_mscan.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_pit.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_port.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_pwt.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_rtc.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_spi.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_tpm.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_uart.c
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers/fsl_wdog8.c
)

target_include_directories(fsl PUBLIC
  ${fsl_SDK_DIR}/CMSIS/Core/Include
  ${fsl_SDK_DIR}/devices/${DEVICE}
  ${fsl_SDK_DIR}/devices/${DEVICE}/drivers
)

target_compile_options(fsl PUBLIC
  -Wno-pedantic
)

target_compile_options(fsl PRIVATE
  -Wno-unused-parameter
  -Wno-old-style-declaration
)

target_compile_definitions(fsl PUBLIC
  -DNDEBUG
)
