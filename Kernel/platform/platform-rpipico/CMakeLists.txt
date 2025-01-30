cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(fuzix C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(PICO_COPY_TO_RAM 1)
#set(PICO_CLIB picolibc)

add_compile_definitions(
		PICO_HEAP_SIZE=0x100
		PICO_NO_BINARY_INFO=1
		PICO_TIME_DEFAULT_ALARM_POOL_DISABLED
		PICO_RUNTIME_SKIP_INIT_MUTEX=1
		PICO_PANIC_FUNCTION=0
		PICO_USE_MALLOC_MUTEX=0
		PICO_MALLOC_PANIC=0
#		PICO_RUNTIME_SKIP_INIT_PER_CORE_INSTALL_STACK_GUARD=1
#		PICO_RUNTIME_NO_INIT_PER_CORE_INSTALL_STACK_GUARD=1
		)

pico_sdk_init()

include_directories(
	.
	../..
	../../dev
	../../include
	../../cpu-armm0
)

add_executable(fuzix
	devices.c
	devflash.c
	devsdspi.c
	devtty.c
	elf.c 
	main.c
	misc.c
	rawflash.c
	rawuart.c
	swapper.c
	tricks.S
	core1.c
	devgpio.c
	usbdescriptors.c
	../../dev/blkdev.c
	../../dev/mbr.c
	../../dev/devsd_discard.c
	../../dev/devsd.c
	../../lib/dhara/error.c
	../../lib/dhara/journal.c
	../../lib/dhara/map.c
	../../lib/hexdump.c
	../../blk512.c
	../../devio.c
	../../devsys.c
	../../filesys.c
	../../inode.c
	../../kdata.c
	../../cpu-armm0/lowlevel-armm0.c
	../../mm/malloc.c
	../../mm.c
	../../mm/memalloc_none.c
	../../process.c
	../../start.c
	../../swap.c
	../../syscall_execelf32.c
	../../syscall_exec.c
	../../syscall_fs.c
	../../syscall_fs2.c
	../../syscall_fs3.c
	../../syscall_other.c
	../../syscall_proc.c
	../../timer.c
	../../tty.c
	../../usermem.c
	../../version.c
	../../dev/net/net_native.c
	../../syscall_net.c
	../../network.c
)

target_link_libraries(fuzix
	pico_runtime
	pico_multicore
	hardware_flash
	hardware_timer
	hardware_uart
	hardware_irq
	hardware_spi
	tinyusb_device
)

pico_set_float_implementation(fuzix none)
pico_set_double_implementation(fuzix none)
pico_set_printf_implementation(fuzix none)
pico_add_extra_outputs(fuzix)

