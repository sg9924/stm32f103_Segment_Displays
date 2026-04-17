#CMD Commands
CC=arm-none-eabi-gcc
OBJ_DUMP=arm-none-eabi-objdump.exe
OBJ_COPY=arm-none-eabi-objcopy
NM=arm-none-eabi-nm.exe
GDB=arm-none-eabi-gdb.exe
FLASH=st-flash --reset write
PROBE=st-info --probe

#Toolchain Paths
OPENOCD_DIR=../../xpack-openocd-0.12.0-3/openocd

#Openocd
#Configuration File
#Interface
OPENOCD_INTF_CFG_FILE=$(OPENOCD_DIR)/scripts/interface/stlink-v2.cfg
#target
OPENOCD_TGT_CFG_FILE=$(OPENOCD_DIR)/scripts/target/stm32f1x.cfg

#MCU Params
MACH=cortex-m3 #device
FLASH_ADDR=0x08000000 #flash address where the code needs to be loaded

#Directories
DRIVERS_DIR=../../Drivers
UTILITIES_DIR=../../Utilities
DISPLAYS_DIR=../../BSP/Displays
INC_DIR=Inc
SRC_DIR=Src

#Files
MAIN=7seg_single_digit_test
ELF=final.elf
STARTUP=bp_startup
SYSCALLS=syscalls
LINK=bp_linker.ld
DRIVERS=stm32f103xx_gpio.o stm32f103xx_afio.o stm32f103xx_exti.o stm32f103xx_nvic.o stm32f103xx_usart.o stm32f103xx_rcc.o stm32f103xx_rtc.o stm32f103xx_spi.o stm32f103xx_adc.o stm32f103xx_i2c.o stm32f103xx_timer.o stm32f103xx_dma.o stm32f103xx_systick.o
OTHERS=stm32f103xx_init.o stm32f103xx_serial.o stm32f103xx_utilities.o stm32f103xx_fault_handlers.o stm32f103xx_flash.o stm32f103xx_bkp.o log.o
MIDDLEWARE= seg_display.o

#Flags
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -Wno-unused -O0 -I$(DRIVERS_DIR)/$(INC_DIR) -I$(UTILITIES_DIR)/$(INC_DIR) -I$(DISPLAYS_DIR)/$(INC_DIR)
DEBUG_FLAG= -g3
#Libraries must come after the objects that use them.
LDFLAGS= --specs=nano.specs -mcpu=$(MACH) -mthumb -T $(LINK) -Wl,-Map=../../Logs/final.map
LIBS = -lm


all: compile load
compile: clean final.elf clean-obj
stm32f103xx_gpio.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_gpio.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_afio.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_afio.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_exti.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_exti.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_nvic.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_nvic.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_usart.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_usart.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_rcc.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_rcc.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_rtc.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_rtc.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_spi.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_spi.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_adc.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_adc.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_i2c.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_i2c.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_timer.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_timer.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_dma.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_dma.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_init.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_init.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_serial.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_serial.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_systick.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_systick.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_utilities.o:$(UTILITIES_DIR)/$(SRC_DIR)/stm32f103xx_utilities.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_fault_handlers.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_fault_handlers.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_flash.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_flash.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
stm32f103xx_bkp.o:$(DRIVERS_DIR)/$(SRC_DIR)/stm32f103xx_bkp.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
log.o:$(UTILITIES_DIR)/$(SRC_DIR)/log.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
seg_display.o:seg_display.c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
$(MAIN).o:$(MAIN).c 
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
$(STARTUP).o:$(STARTUP).c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
$(SYSCALLS).o:$(SYSCALLS).c
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $^ -o $@
final.elf: $(MAIN).o $(DRIVERS) $(OTHERS) $(MIDDLEWARE) $(STARTUP).o $(SYSCALLS).o
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

final.bin:final.elf
	arm-none-eabi-objcopy -O binary $^ $@
load:final.bin
	$(FLASH) $^ $(FLASH_ADDR)

examine-sections:
	$(OBJ_DUMP) -h final.elf
examine-symbols:
	$(NM) final.elf
dump:final.elf
	$(OBJ_DUMP) -d $^ > ../../Logs/assembly_dump.txt
	$(OBJ_DUMP) -h $^ > ../../Logs/section_contents.txt
	$(OBJ_DUMP) -s $^ > ../../Logs/section_contents_detailed.txt
	$(NM) final.elf > ../../Logs/symbols.txt
probe:
	$(PROBE)

debug: openocd gdb
openocd:
	openocd -f $(OPENOCD_INTF_CFG_FILE) -f $(OPENOCD_TGT_CFG_FILE)
gdb:
	$(GDB) final.elf

.PHONY: clean clean-obj
clean:
	del /s *.o *.elf *.map *.log *.bin *.exe *.txt
clean-obj:
	del /s *.o