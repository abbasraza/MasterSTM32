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
    ninja flash
    ```
