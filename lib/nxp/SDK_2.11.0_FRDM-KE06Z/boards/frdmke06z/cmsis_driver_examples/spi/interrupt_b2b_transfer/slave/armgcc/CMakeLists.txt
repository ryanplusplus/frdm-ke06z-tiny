# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(cmsis_spi_interrupt_b2b_transfer_slave)

set(MCUX_SDK_PROJECT_NAME cmsis_spi_interrupt_b2b_transfer_slave.elf)

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../cmsis_spi_interrupt_b2b_transfer_slave.c"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../RTE_Device.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/..
)

set(CMAKE_MODULE_PATH
    ${ProjDirPath}/../../../../../../../devices/MKE06Z4/utilities/debug_console_lite
    ${ProjDirPath}/../../../../../../../devices/MKE06Z4/drivers
    ${ProjDirPath}/../../../../../../../devices/MKE06Z4/cmsis_drivers
    ${ProjDirPath}/../../../../../../../devices/MKE06Z4
    ${ProjDirPath}/../../../../../../../components/uart
    ${ProjDirPath}/../../../../../../../components/lists
    ${ProjDirPath}/../../../../../../../CMSIS/Core/Include
    ${ProjDirPath}/../../../../../../../CMSIS/Driver/Include
    ${ProjDirPath}/../../../../../../../devices/MKE06Z4/utilities
)

# include modules
include(utility_debug_console_lite_MKE06Z4)

include(utility_assert_lite_MKE06Z4)

include(driver_clock_MKE06Z4)

include(driver_spi_MKE06Z4)

include(driver_cmsis_spi_MKE06Z4)

include(driver_common_MKE06Z4)

include(device_MKE06Z4_CMSIS_MKE06Z4)

include(component_uart_adapter_MKE06Z4)

include(component_lists_MKE06Z4)

include(driver_uart_MKE06Z4)

include(device_MKE06Z4_startup_MKE06Z4)

include(driver_port_ke06_MKE06Z4)

include(driver_gpio_1_MKE06Z4)

include(CMSIS_Include_core_cm_MKE06Z4)

include(CMSIS_Driver_Include_SPI_MKE06Z4)

include(CMSIS_Driver_Include_Common_MKE06Z4)

include(utilities_misc_utilities_MKE06Z4)

include(device_MKE06Z4_system_MKE06Z4)


TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE m)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE c)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE gcc)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE nosys)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)


