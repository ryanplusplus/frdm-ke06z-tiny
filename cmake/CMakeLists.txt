cmake_minimum_required(VERSION 3.11.1)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)
set(CMAKE_C_COMPILER arm-none-eabi-gcc CACHE PATH "" FORCE)

enable_language(C ASM)

project(target)

set(SDK SDK_2.11.0_FRDM-KE06Z)
set(DEVICE MKE06Z4)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(SOURCES
  ../src/main.c
  ../src/start.S
  ../src/hello_world.c
  ../src/hardware/clock.c
  ../src/hardware/flash_test.c
  ../src/hardware/heartbeat.c
  ../src/hardware/systick.c
  ../src/hardware/uart.c
  ../src/hardware/watchdog.c
)

include_directories(
  ../src
  ../src/hardware
)

set(COMPILE_AND_LINK_OPTIONS
  --specs=nano.specs
  -mcpu=cortex-m0plus
  -mthumb
  -g
  -g2
  -Os
  -fdata-sections
  -ffunction-sections
  -Wall
  -Wextra
  -Werror
  -Wfatal-errors
  -Wcast-qual
  -pedantic
  -nostartfiles
  -std=c99
)

add_compile_options(
  ${COMPILE_AND_LINK_OPTIONS}
)

add_link_options(
  ${COMPILE_AND_LINK_OPTIONS}
  -Wl,--gc-sections
  -Wl,-Map=${PROJECT_NAME}.map
  -T ../linker.ld
)

add_definitions(
  -DCPU_MKE06Z128VLK4
  -D__NO_SYSTEM_INIT
  -D__STARTUP_CLEAR_BSS
  -D__START=main
)

include(fsl.cmake)
add_subdirectory(../lib/tiny tiny-build)

add_executable(${PROJECT_NAME}.elf ${SOURCES})

target_link_libraries(${PROJECT_NAME}.elf
  tiny
  fsl
  fsl-system
)
