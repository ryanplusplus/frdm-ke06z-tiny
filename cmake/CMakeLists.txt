cmake_minimum_required(VERSION 3.11.1)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)

project(target)

set(SDK SDK_2.11.0_FRDM-KE06Z)
set(DEVICE MKE06Z4)

set(target_SRC
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

add_definitions(
  -DCPU_MKE06Z128VLK4
  -D__NO_SYSTEM_INIT
  -D__STARTUP_CLEAR_BSS
  -D__START=main
)

include(flags.cmake)

add_executable(${PROJECT_NAME}.elf ${target_SRC})

include(fsl.cmake)
include(../lib/tiny/CMakeLists.txt)

target_link_libraries(${PROJECT_NAME}.elf
  tiny
  fsl
  fsl-system
)
