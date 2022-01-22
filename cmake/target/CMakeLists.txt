cmake_minimum_required(VERSION 3.11.1)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)
set(CMAKE_C_COMPILER arm-none-eabi-gcc CACHE PATH "" FORCE)

project(target
  LANGUAGES C ASM
)

set(SDK SDK_2.11.0_FRDM-KE06Z)
set(DEVICE MKE06Z4)

set(ROOT ${CMAKE_CURRENT_LIST_DIR}/../..)

set(target_SRC
  ${ROOT}/src/main.c
  ${ROOT}/src/start.S
  ${ROOT}/src/hello_world.c
  ${ROOT}/src/hardware/clock.c
  ${ROOT}/src/hardware/flash_test.c
  ${ROOT}/src/hardware/heartbeat.c
  ${ROOT}/src/hardware/systick.c
  ${ROOT}/src/hardware/uart.c
  ${ROOT}/src/hardware/watchdog.c
)

include_directories(
  ${ROOT}/src
  ${ROOT}/src/hardware
)

add_definitions(
  -DCPU_MKE06Z128VLK4
  -D__NO_SYSTEM_INIT
  -D__STARTUP_CLEAR_BSS
  -D__START=main
)

include(flags.cmake)

add_executable(${PROJECT_NAME}.elf ${target_SRC})

include(fsl.cmake)
include(${ROOT}/lib/tiny/CMakeLists.txt)

target_link_libraries(${PROJECT_NAME}.elf
  tiny
  fsl
  fsl-system
)
