# This is the Meson build file for the MasterSTM32 project.

# Define the project name and language
project('MasterSTM32', 'c')

# current_build_dir = meson.current_build_dir()
# current_source_dir = meson.current_source_dir()
# message('root script --> Build directory: ' + current_build_dir)
# message('root script --> Source directory: ' + current_source_dir)

# Common source files and include directories
# These are the source files and include directories that are common to all subdirectories.

# startup & system source files (Provided by STMicroelectronics)
# PATH are relative to the example subdirectories
common_sources = [
    '../../cmsis_device_f4/Source/Templates/gcc/startup_stm32f429xx.s',
    '../../cmsis_device_f4/Source/Templates/system_stm32f4xx.c',
]

# PATH are relative to the example subdirectories
common_includes = [
    '../../cmsis_device_f4/Include',
    # Path to CMSIS directory (Provided by ARM)
    '../../CMSIS_5/CMSIS/Core/Include',
]

# Specify the linker script file
# Linker script file automatically generated by STM32CubeIDE
root_dir = meson.current_source_dir()
linker_script = join_paths(root_dir, 'linker_scripts/STM32F429ZITX_FLASH.ld')

# Following doesn't work because linker script is not found this way.  why?
#linker_script = '../../linker_scripts/STM32F429ZITX_FLASH.ld'

# Following works and linker script is found this way. why?
#linker_script = '../linker_scripts/STM32F429ZITX_FLASH.ld'

# Compiler flags
# These are the compiler flags that are common to all subdirectories.
# This variable contains a list of common compiler arguments used for building the project.
# Each argument is explained below:

common_compiler_args = [
    '-DSTM32F429xx',   # Define the STM32F429xx macro to enable device-specific code.
    '-mcpu=cortex-m4', # Set the target CPU architecture to Cortex-M4.
    '-mthumb',         # Generate code for the Thumb instruction set.
    '-O0',             # Disable optimization to ease debugging.
    '-std=gnu11',      # Use the GNU C11 standard.
    '-Wall',           # Enable all warnings.
    '-Wextra',         # Enable extra warnings not covered by -Wall.
    '-pedantic',       # Enable strict ISO C compliance.
    '--specs=nano.specs', # Use the nano.specs linker script to reduce code size.
    '-mfloat-abi=softfp', # Use software floating-point emulation.
    '-mfpu=fpv4-sp-d16'   # Enable the Floating Point Unit (FPU) with single precision support.
]

# Linker flags
# These are the linker flags that are common to all subdirectories.
# common linker arguments
common_linker_args = [
    '-mfloat-abi=softfp',  # Use software floating-point emulation.
    '-mfpu=fpv4-sp-d16',   # Enable the Floating Point Unit (FPU) with single precision support.
    '-mcpu=cortex-m4',     # specify the target CPU
    '-mthumb',             # generate code for the Thumb instruction set
    '--specs=nosys.specs', # use a custom syscalls implementation
    '--specs=nano.specs',  # use a minimal implementation of the C library
    '-Wl,--gc-sections',   # enable garbage collection of unused sections
    '-T' + linker_script,  # specify the linker script to use
]

# Include subdirectories for building
# This includes the subdirectory for building the 'led_blink' example.
subdir('examples/led_blink')
