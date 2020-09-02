# frdm-ke06z-tiny
Sample project using [`tiny`](https://github.com/ryanplusplus/tiny) and [FRDM-KE06Z](https://www.nxp.com/design/development-boards/freedom-development-boards/mcu-boards/freedom-development-platform-for-kinetis-ke06-mcus:FRDM-KE06Z).

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
- [FRDM-KE06Z User's Guide](https://www.nxp.com/webapp/Download?colCode=FRDMKE06UG)
- [KE06 Reference Manual](https://www.nxp.com/files-static/microcontrollers/doc/ref_manual/MKE06P80M48SF0RM.pdf)
