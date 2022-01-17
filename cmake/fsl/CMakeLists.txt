add_library(fsl)

target_sources(fsl PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_acmp.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_adc.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_clock.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_common_arm.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_common.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_flash.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_ftm.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_gpio.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_i2c.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_irq.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_kbi.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_mscan.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_pit.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_port.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_pwt.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_rtc.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_spi.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_tpm.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_uart.c
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers/fsl_wdog8.c
)

target_include_directories(fsl PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/CMSIS/Core/Include
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}
  ${CMAKE_CURRENT_LIST_DIR}/../../lib/nxp/${SDK}/devices/${DEVICE}/drivers
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
