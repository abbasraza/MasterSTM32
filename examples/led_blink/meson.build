# Define the source files and include directories
includes = [] # list of include directories

sources = [ # list of source files
  'led_blink.c',
]

# Define the compiler and linker arguments
compiler_args = [] # list of compiler arguments

linker_args = [] # list of linker arguments

# Build the project for led_blink
elf_file = executable('led_blink.elf', # name of the executable
  [common_sources, sources], # list of source files
  c_args: [common_compiler_args, compiler_args], # list of compiler arguments
  link_args: [common_linker_args, linker_args], # list of linker arguments
  include_directories: common_includes, # list of include directories
)

# Define a custom target to convert ELF to BIN
bin_file = custom_target(
  'led_blink.bin',  # Name of the target
  command: ['objcopy', '-O', 'binary', '@INPUT@', '@OUTPUT@'], # command to convert ELF to BIN
  input: elf_file, # input file
  output:'led_blink.bin', # output file
  build_always: true,  # Ensure the command is always run
  depends: elf_file # list of dependencies
)

# Find the st-flash program and define a target to flash the binary file to the STM32 device
stm32flash = find_program('st-flash', required: false) # find the st-flash program

if stm32flash.found() # check if st-flash is found
    message('st-flash is  found') # print message if st-flash is found
    run_target(
        'flash',
        command: [
            stm32flash,
            'write',
            bin_file.full_path(),
            '0x8000000',
        ],
        depends: bin_file # list of dependencies
    )
else
    error('st-flash is not found. Make sure it is installed and available in your PATH.') # print error message if st-flash is not found
endif
