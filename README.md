# stm32-tiny
Sample project using [`tiny`](https://github.com/ryanplusplus/tiny) with STM32.

## Hardware
### STM32F3 Discovery
https://www.st.com/en/evaluation-tools/stm32f3discovery.html

### NUCLEO-G031K8
https://www.st.com/en/evaluation-tools/nucleo-g031k8.html

## Setup
- Install [`gcc-arm-none-eabi`]
- Install [`openocd`](https://github.com/ntfreak/openocd) (patches [here](http://openocd.zylin.com/#/c/4807/) for STM32G0 support)

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
- [STM32F3 Reference Manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/4a/19/6e/18/9d/92/43/32/DM00043574.pdf/files/DM00043574.pdf/jcr:content/translations/en.DM00043574.pdf)
- [STM32G0x1 Reference Manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/group0/2f/21/cb/33/78/80/42/64/DM00371828/files/DM00371828.pdf/jcr:content/translations/en.DM00371828.pdf)
- [STM32F303VC Datasheet](https://www.st.com/resource/en/datasheet/stm32f303vc.pdf)
- [STM32G031K8 Datasheet](https://www.st.com/resource/en/datasheet/stm32g031k8.pdf)
- [STM32F3 Discovery User Manual](https://www.st.com/content/ccc/resource/technical/document/user_manual/8a/56/97/63/8d/56/41/73/DM00063382.pdf/files/DM00063382.pdf/jcr:content/translations/en.DM00063382.pdf)
- [NUCLEO-G031K8 User Manual](https://www.st.com/content/ccc/resource/technical/document/user_manual/group1/b5/f7/d3/3c/11/82/44/a8/DM00622380/files/DM00622380.pdf/jcr:content/translations/en.DM00622380.pdf)
- [Accelerometer/Magnetometer Datasheet](https://cdn-shop.adafruit.com/datasheets/LSM303DLHC.PDF)
