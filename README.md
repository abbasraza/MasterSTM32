# STM32 Bare Metal Programming on STM32F429I-DISC1 Discovery Kit

This project focuses on STM32 bare metal programming using the STM32F429I-DISC1 Discovery kit with the STM32F429ZIT6 MCU. The goal is to explore and understand the capabilities of the STM32 Cortex-M4 microcontroller, develop low-level firmware, and gain insight into hardware-level programming. We will use a combination of reference manuals, user guides, and programming manuals to master STM32 bare metal programming.


## Documents for Reference

- Reference manual STM32F429 advanced Arm®-based 32-bit MCUs
- Arm® Cortex®-M4 Processor Technical Reference Manual
- Cortex -M4 Devices™ Generic User Guide
- Application Note Migrating from 8051 to Cortex™ Microcontrollers
- User manual Discovery kit with STM32F429ZI MCU
- User manual Getting started with STM32F429 Discovery software development tools
- User manual Getting started with STM32 MCU Discovery Kits software development tools
- Programming manual STM32 Cortex®-M4 MCUs and MPUs programming manual
- CMSIS documentation

For detailed insights into the STM32 architecture and programming, refer to these resources.


## Hardware Requirements

- STM32F429I-DISC1 Discovery kit
- USB Type-A to Mini-B cable

## Supported OS

- Ubuntu


## Installation
- Download and install [STLINK tools](https://github.com/stlink-org/stlink)  stlink_1.7.0-1_amd64.deb from [here
](https://github.com/stlink-org/stlink/releases)
- Install ninja
```shell
sudo apt-get install ninja-build
```

### 1. Download pre-built ARM bare metal toolchain and untar it from [here](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads/12-2-rel1).
    - x86_64 Linux hosted cross toolchains --> AArch32 bare-metal target (arm-none-eabi) --> arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi.tar.xz
### 2. Add the toolchain to your PATH:
```shell
    PATH=$PATH:/path_where_downloaded_toolchain/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/
```
### 3. Setup Python virtual environment and install Meson:
```shell
    python3.10 -m venv meson_venv
    source ../meson_venv/bin/activate
    pip install meson
```
### 4. Clone the repository:
```shell
    git clone git@github.com:abbasraza/MasterSTM32.git
    cd MasterSTM32
```
### 5. Submodules

This project includes the following submodules:

#### [CMSIS_5](https://github.com/ARM-software/CMSIS_5)
- Path: CMSIS_5
- URL: https://github.com/ARM-software/CMSIS_5

The CMSIS (Cortex Microcontroller Software Interface Standard) submodule is a crucial component for ARM-based microcontroller development. It provides standardized hardware abstraction and peripheral driver interfaces.

#### [cmsis_device_f4](https://github.com/STMicroelectronics/cmsis_device_f4.git)
- Path: cmsis_device_f4
- URL: https://github.com/STMicroelectronics/cmsis_device_f4.git

The 'cmsis_device_f4' submodule is specific to STMicroelectronics' STM32F4 microcontrollers. It includes startup and system files required for programming STM32F4 microcontrollers.

Including these submodules is necessary to access the required files and libraries for STM32 development.

Before using this project, make sure to initialize and update these submodules:
```shell
git submodule init
git submodule update
```
### 6. Meson setup (to create ninja build file):
```shell
(meson_venv) abbas@abbas-teo:~/work/MasterSTM32$ meson setup --cross-file cross_file.txt build
```
```
Output:
The Meson build system
Version: 1.2.2
Source dir: /home/abbas/work/MasterSTM32
Build dir: /home/abbas/work/MasterSTM32/build
Build type: cross build
Project name: MasterSTM32
Project version: undefined
C compiler for the host machine: arm-none-eabi-gcc (gcc 12.3.1 "arm-none-eabi-gcc (Arm GNU Toolchain 12.3.Rel1 (Build arm-12.35)) 12.3.1 20230626")
C linker for the host machine: arm-none-eabi-gcc ld.bfd 12.3
C compiler for the build machine: ccache cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0")
C linker for the build machine: cc ld.bfd 2.38
Build machine cpu family: x86_64
Build machine cpu: x86_64
Host machine cpu family: arm
Host machine cpu: cortex-m4
Target machine cpu family: arm
Target machine cpu: cortex-m4
Program st-flash found: YES (/usr/bin/st-flash)
Message: st-flash is  found
Build targets in project: 3

MasterSTM32 undefined

  User defined options
    Cross files: cross_file.txt

Found ninja-1.10.1 at /usr/bin/ninja
(meson_venv) abbas@abbas-teo:~/work/MasterSTM32$ 
    
```
### 7. Build and flash project to STM32 board:
```shell
    cd build/
    ninja
```
```
Output:
(meson_venv) abbas@abbas-teo:~/work/MasterSTM32/build$ ninja 
[4/5] Linking target examples/led_blink/led_blink.elf
/home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/softfp/libc_nano.a(libc_a-closer.o): in function `_close_r':
closer.c:(.text._close_r+0xc): warning: _close is not implemented and will always fail
/home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/softfp/libc_nano.a(libc_a-lseekr.o): in function `_lseek_r':
lseekr.c:(.text._lseek_r+0x10): warning: _lseek is not implemented and will always fail
/home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/softfp/libc_nano.a(libc_a-readr.o): in function `_read_r':
readr.c:(.text._read_r+0x10): warning: _read is not implemented and will always fail
/home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: /home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/lib/thumb/v7e-m+fp/softfp/libc_nano.a(libc_a-writer.o): in function `_write_r':
writer.c:(.text._write_r+0x10): warning: _write is not implemented and will always fail
/home/abbas/Downloads/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: warning: examples/led_blink/led_blink.elf has a LOAD segment with RWX permissions
[5/5] Generating examples/led_blink/led_blink.bin with a custom command
```
```shell
    ninja flash
```
```
Output:
(meson_venv) abbas@abbas-teo:~/work/MasterSTM32/build$ ninja flash
[0/1] Running external command flash (wrapped by meson to set env)
st-flash 1.7.0
2023-10-16T02:42:41 INFO common.c: F42x/F43x: 256 KiB SRAM, 2048 KiB flash in at least 16 KiB pages.
file /home/abbas/work/MasterSTM32/build/examples/led_blink/led_blink.bin md5 checksum: 7efce998a56f4a38e5511d45792f765, stlink checksum: 0x000110dc
2023-10-16T02:42:41 INFO common.c: Attempting to write 1200 (0x4b0) bytes to stm32 address: 134217728 (0x8000000)
EraseFlash - Sector:0x0 Size:0x4000 2023-10-16T02:42:42 INFO common.c: Flash page at addr: 0x08000000 erased
2023-10-16T02:42:42 INFO common.c: Finished erasing 1 pages of 16384 (0x4000) bytes
2023-10-16T02:42:42 INFO common.c: Starting Flash write for F2/F4/F7/L4
2023-10-16T02:42:42 INFO flash_loader.c: Successfully loaded flash loader in sram
2023-10-16T02:42:42 INFO flash_loader.c: Clear DFSR
2023-10-16T02:42:42 INFO common.c: enabling 32-bit flash writes
2023-10-16T02:42:42 INFO common.c: Starting verification of write complete
2023-10-16T02:42:42 INFO common.c: Flash written and verified! jolly good!
(meson_venv) abbas@abbas-teo:~/work/MasterSTM32/build$ 
```
