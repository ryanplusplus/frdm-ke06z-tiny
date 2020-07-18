# stm32-tiny
Sample project using [`tiny`](https://github.com/ryanplusplus/tiny) with STM32.

## Hardware
### Blue F030
https://stm32-base.org/boards/STM32F030F4P6-STM32F030-DEMO-BOARD-V1.1

### Blue F051
https://stm32-base.org/boards/STM32F051C8T6-LC-Technology

### Blue Pill
https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill

### NUCLEO-G031K8
https://www.st.com/en/evaluation-tools/nucleo-g031k8.html

### NUCLEO-G070RB
https://www.st.com/en/evaluation-tools/nucleo-g070rb.html

### STM32F3 Discovery
https://www.st.com/en/evaluation-tools/stm32f3discovery.html

### STM32VL Discovery
https://www.st.com/en/evaluation-tools/stm32vldiscovery.html

Note that on Linux `./scripts/stlink-quirks` must be run prior to connection to avoid loading the buggy mass storage implementation in ST-Link v1.

## Setup
- Install `gcc-arm-none-eabi`
- Install [`openocd`](https://sourceforge.net/p/openocd/code/ci/master/tree/) (build `master`from source for STM32G0 support)

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
### Reference Manuals
- [STM32F030 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00091010.pdf)
- [STM32F100 Reference Manual](https://www.st.com/resource/en/reference_manual/cd00246267.pdf)
- [STM32F103 Reference Manual](https://www.st.com/resource/en/reference_manual/cd00171190.pdf)
- [STM32F3 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00043574.pdf)
- [STM32G0x0 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00463896.pdf)
- [STM32G0x1 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00371828.pdf)

### Datasheets
- [STM32F030F4 Datasheet](https://www.st.com/resource/en/datasheet/stm32f030f4.pdf)
- [STM32F100RB Datasheet](https://www.st.com/resource/en/datasheet/stm32f100rb.pdf)
- [STM32F103C8 Datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf)
- [STM32F303VC Datasheet](https://www.st.com/resource/en/datasheet/stm32f303vc.pdf)
- [STM32G031K8 Datasheet](https://www.st.com/resource/en/datasheet/stm32g031k8.pdf)
- [STM32G070RB Datasheet](https://www.st.com/resource/en/datasheet/stm32g070rb.pdf)

### User Manuals
- [NUCLEO-G031K8 User Manual](https://www.st.com/resource/en/user_manual/dm00622380.pdf)
- [NUCLEO-G070RB User Manual](https://www.st.com/resource/en/user_manual/dm00452640.pdf)
- [STM32F3 Discovery User Manual](https://www.st.com/resource/en/user_manual/dm00063382.pdf)
- [STM32VL Discovery User Manual](https://www.st.com/resource/en/user_manual/cd00267113.pdf)

### References
- [STM32-base](https://stm32-base.org/)
- [libopencm3](https://github.com/libopencm3/libopencm3)
