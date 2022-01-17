enable_language(C ASM)

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
  -T ${ROOT}/linker.ld
)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
