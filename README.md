# stm32f051-freertos
Sample project using [`tiny`](https://github.com/ryanplusplus/tiny) and [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel) with [STM32F051C8T6](https://stm32-base.org/boards/STM32F051C8T6-LC-Technology).

## Setup
- Install `gcc-arm-none-eabi`
- Install [`openocd`](https://sourceforge.net/p/openocd/code/ci/master/tree/)

## Use
### Compile
```shell
make -f <target>.mk
```

### Clean
```shell
make -f <target>.mk clean
```

### Erase via SWD
```shell
make -f <target>.mk erase
```

### Flash via SWD
```shell
make -f <target>.mk upload
```

## Resources
- [STM32F030 Reference Manual](https://www.st.com/resource/en/programming_manual/dm00051352-stm32f0xxx-cortexm0-programming-manual-stmicroelectronics.pdf)
- [STM32F051C8 Datasheet](https://www.st.com/resource/en/datasheet/stm32f051c8.pdf)
- [STM32-base](https://stm32-base.org/)
- [libopencm3](https://github.com/libopencm3/libopencm3)
