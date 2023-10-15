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

1. Download pre-built ARM bare metal toolchain and untar it from [here](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads/12-2-rel1).
    - x86_64 Linux hosted cross toolchains --> AArch32 bare-metal target (arm-none-eabi) --> arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi.tar.xz
2. Add the toolchain to your PATH:
    ```
    PATH=$PATH:/path_where_downloaded_toolchain/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi/bin/
    ```
3. Setup Python virtual environment and install Meson:
    ```
    python3.10 -m venv meson_venv
    source ../meson_venv/bin/activate
    pip install meson
    ```
4. Clone the repository:
    ```
    git clone git@github.com:abbasraza/MasterSTM32.git
    cd MasterSTM32
    ```
5. ### Submodules

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

6. Meson setup (to create ninja build file):
    ```
    meson setup --cross-file cross_file.txt build
    ```
7. Build and run simple project:
    ```
    cd build/
    ninja
    ninja flash
    ```
