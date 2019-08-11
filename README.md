# stm32-tiny
Sample project using [`tiny`](https://github.com/ryanplusplus/tiny) with STM32F303.

## Hardware
### STM32F3 Discovery
https://www.st.com/en/evaluation-tools/stm32f3discovery.html

## Setup
- Install [`gcc-arm-none-eabi`]
- Install [`openocd`](https://github.com/ntfreak/openocd)

## Use
### Compile
```shell
make
```

### Clean
```shell
make clean
```

### Erase via SWIM
```shell
make erase
```

### Flash via SWIM
```shell
make upload
```

## Resources
- [STM32F3 Discovery user manual](https://www.st.com/content/ccc/resource/technical/document/user_manual/8a/56/97/63/8d/56/41/73/DM00063382.pdf/files/DM00063382.pdf/jcr:content/translations/en.DM00063382.pdf)
- [Reference manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/4a/19/6e/18/9d/92/43/32/DM00043574.pdf/files/DM00043574.pdf/jcr:content/translations/en.DM00043574.pdf)
