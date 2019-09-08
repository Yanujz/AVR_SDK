PROGRAMMER 		= stk500v2 
MPROG 			= m2560
FCPU 			= 16000000
MICROCONTROLLER = atmega2560

SRC_DIR 	= src
BUILD_DIR 	= build
ASM_DIR 	= $(BUILD_DIR)/asm
FIRMW_DIR 	= firmware
SDK_PATH 	= ~/Documents/GitHub/AVR_SDK
LIBS_DIR	= $(SDK_PATH)/libs
STATIC_LIB  = $(LIBS_DIR)/static_lib
LIB_NAME = ysdk_$(MICROCONTROLLER)



CXX = avr-g++
CC  = avr-gcc

CXX_SRCS := $(shell find $(SRC_DIR)/ -type f -regex ".*\.cpp") 
CXX_OBJS  = $(CXX_SRCS:.cpp=.o)


ASM_SRCS  = $(shell find $(LIBS_DIR)/ -type f -regex ".*\.s") \
			$(shell find $(SRC_DIR)/ -type f -regex ".*\.s")
ASM_OBJS  = $(ASM_SRCS:.s=.o)

INCLUDE_DIR := -I include -I /usr/lib/avr/include -I $(SDK_PATH)/standardCpp -I /home/zetes/Documents/GitHub/AVR_SDK/libs \
	$(addprefix -I ,$(shell find $(LIBS_DIR)/ -name  '*.h' -exec dirname {} \;)) \
	$(addprefix -I ,$(shell find $(SRC_DIR)/ -name  '*.h' -exec dirname {} \;)) \
	$(addprefix -I ,$(shell find $(LIBS_DIR)/ -name  '*.inc' -exec dirname {} \;))



CXX_FLAGS = -lstdc++ -std=c++14 $(INCLUDE_DIR)
LD_FLAGS  =  -Wl,-u,vfscanf,-lscanf_flt,-u,vfprintf,-lprintf_flt,-L$(shell realpath $(STATIC_LIB)) -l$(LIB_NAME) -L/home/zetes/Documents/GitHub/AVR_SDK/standardCpp/static_lib -lstl

# Select programmer (default: stk500v2)
PROGRAMMER ?= atmelice_isp 
# Select mprog (default: m2560)
MPROG ?= m2560
# Select microntroller (default: atmega2560)
MICROCONTROLLER ?= atmega2560


# Flash port (default: /dev/ttyUSB0)
FLASH_PORT ?= /dev/ttyUSB0
# Flash Baudrate (default: 115200)
FLASH_BAUDRATE ?= 115200
# Com Port (default: /dev/ttyUSB0)
COM_PORT ?= /dev/ttyUSB0
# Com Baudrate (default: 1000000)
COM_BAUDRATE ?= 1000000


ifeq ($(PROGRAMMER),jtag3isp)
	COM_PORT = 
endif

# High fuse (default: 0xd8)
HFUSE ?= 0xd8
# Low fuse (default: 0xff)
LFUSE ?= 0xff
# Ext fuse (default: 0xfd)
EFUSE ?= 0xfd
# Lock bits (default: 0xcf)
LOCKBITS ?= 0xcf
# Filename (default: dump.bin)
FILENAME ?= dump.bin
# Source Filename
SRC ?= 
# Destination Filename
DST ?= 
# Bytes
BYTES ?= 0
# OTA SETUP
IP = 192.168.1.167
USERNAME = pi




#
all:createdir $(CXX_OBJS) main.elf app

# Remote upload
ota:
	scp $(FIRMW_DIR)/main.hex $(USERNAME)@$(IP):~/firmwareDownload/$(FIRMW_DIR)/
	ssh $(USERNAME)@$(IP) "cd ~/firmwareDownload && make upload"
# Local upload
upload: createdir app
	@killall hexdump putty 2>/dev/null || true
	@avrdude -q -V -p $(MPROG) -D -c $(PROGRAMMER) -b $(FLASH_BAUDRATE) -P $(FLASH_PORT) -U flash:w:$(FIRMW_DIR)/main.hex:i
#
app: main.elf
	@avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)/main.elf $(FIRMW_DIR)/main.hex
#
main.elf: $(CXX_OBJS)
	@$(CXX) -mmcu=$(MICROCONTROLLER) -o $(BUILD_DIR)/$@ $(BUILD_DIR)/*.o $(LD_FLAGS)

# Show Memory Usage
size:
	@echo ''
	@avr-size --format=avr  -C --mcu=$(MICROCONTROLLER) $(BUILD_DIR)/main.elf

%.o: %.cpp
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS) -nostdlib $(INCLUDE_DIR) -Os -mmcu=$(MICROCONTROLLER)  -c $<  -o $(BUILD_DIR)/$(notdir $@)
	@$(CXX) $(CXX_FLAGS) -nostdlib -Os -mmcu=$(MICROCONTROLLER) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<

%.o: %.s
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS) -Os -mmcu=$(MICROCONTROLLER)  -c $<  -o $(BUILD_DIR)/$(notdir $@)

# Read Fuses
readfuse:
	@mkdir -p fuses lock
	@avrdude -p $(MICROCONTROLLER) -c $(PROGRAMMER) -U lfuse:r:fuses/low_fuse:h -U hfuse:r:fuses/high_fuse:h -U efuse:r:fuses/ext_fuse:h -U lock:r:lock/lock_bits:h >> /dev/null 2>&1
	@bash -c "echo -e \"High : $(shell cat fuses/high_fuse)\""
	@bash -c "echo -e \"Low  : $(shell cat fuses/low_fuse)\""
	@bash -c "echo -e \"Ext  : $(shell cat fuses/ext_fuse)\""
	@bash -c "echo -e \"Lock : $(shell cat lock/lock_bits)\""
# Write Fuses
writefuse:
	@avrdude -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT)  -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
# Read lock bits
readlock:
	@mkdir -p lock
	@avrdude -p $(MICROCONTROLLER)  -c $(PROGRAMMER) $(COM_PORT) -U lock:r:lock/lock_bits:h >> /dev/null 2>&1
	@bash -c "echo -e \"Lock bits : $(shell cat lock/lock_bits)\""
# Write lock bits
writelock:
	avrdude -e -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT) -U lock:w:$(LOCKBITS):m
# Read flash memory
read_flash:
	@avrdude -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT) -U flash:r:$(FILENAME):r
# Write flash memory
write_flash:
	@avrdude -D -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT) -U flash:w:$(FILENAME)
# Erase flash
erase_flash:
	avrdude -e -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT)
# Read eeprom memory
read_eeprom:
	@avrdude -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT) -U eeprom:r:$(FILENAME):r
# Write eeprom memory
write_eeprom:
	@avrdude -p $(MICROCONTROLLER) -c $(PROGRAMMER) $(COM_PORT) -U eeprom:w:$(FILENAME)
# Convert hex to bin format
convert_hex2bin:
	@avr-objcopy -I ihex $(SRC) -O binary $(DST)
# Convert bin to hex format
convert_bin2hex:
	@avr-objcopy -I binary  $(SRC) -O ihex $(DST)
# Disassemble hex file
disassemble:
	@avr-objdump -mavr -D $(SRC) > $(DST)
# Terminal mode avrdude
interactive:
	@avrdude -p $(MICROCONTROLLER) -c $(PROGRAMMER) -t
# Merge firmware and bootloader file
mergeHexFiles:
	@srec_cat -I prog/main.hex -I firmware/main.hex  -o combined.hex -I
# Pad file with 0xFF
padFile:
	@dd if=/dev/zero bs=1 count=$(BYTES) | tr '\000' '\377' >> $(FILENAME) 

# 
createdir: $(BUILD_DIR) $(FIRMW_DIR) 

$(BUILD_DIR):
	@mkdir -p $@
	@mkdir -p $(ASM_DIR)
$(FIRMW_DIR):
	@mkdir -p $@

# Open putty with selected port
monitor:
	@killall hexdump putty 2>/dev/null || true
	@putty -serial $(COM_PORT) -sercfg $(COM_BAUDRATE)&
	@sleep 0.2

# Open terminal in raw mode
rawMonitor:
	@killall hexdump putty 2>/dev/null || true
	rawSerialMonitor $(COM_PORT) $(COM_BAUDRATE)

# Remove all build files
clean:
	@rm -rf $(BUILD_DIR) $(FIRMW_DIR)

# Install dependencies
install_dependencies:
	bash -c "sudo apt install libftdi1 libusb-0.1-4 binutils-avr gcc-avr avr-libc avrdude putty"
# Show this help prompt.
help:
	@ echo
	@ echo '  Usage:'
	@ echo ''
	@ echo '    make <target> [flags...]'
	@ echo ''
	@ echo '  Targets:'
	@ echo ''
	@ awk '/^#/{ comment = substr($$0,3) } comment && /^[a-zA-Z][a-zA-Z0-9_-]+ ?:/{ print "   ", $$1, comment }' $(MAKEFILE_LIST) | column -t -s ':' | sort
	@ echo ''
	@ echo '  Flags:'
	@ echo ''
	@ awk '/^#/{ comment = substr($$0,3) } comment && /^[a-zA-Z][a-zA-Z0-9_-]+ ?\?=/{ print "   ", $$1, $$2, comment }' $(MAKEFILE_LIST) | column -t -s '?=' | sort
	@ echo ''
	@ echo '  Example:'
	@ echo ''
	@ echo '    make upload FLASH_PORT=/dev/ttyACM0 FLASH_BAUDRATE=115200'
	@ echo '    make monitor COM_PORT=/dev/ttyACM0 COM_BAUDRATE=1000000'
	@ echo ''
