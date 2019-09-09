SDK_PATH = $(shell realpath ~/Documents/GitHub/AVR_SDK)
ifeq ($(SDK_PATH), ) 
    $(error SDK_PATH do not exists, please set corret SDK_PATH into makefile)
endif 

SRC_DIR 	= src
#Building stuff
BUILD_DIR 	= build
ASM_DIR 	= $(BUILD_DIR)/asm
FIRMW_DIR 	= $(BUILD_DIR)/firmware
OBJ_DIR 	= $(BUILD_DIR)/obj
ELF_DIR 	= $(BUILD_DIR)/elf
PREPROC_DIR = $(BUILD_DIR)/prepoc
LIBS_DIR	= $(SDK_PATH)/libs
TOOLS_DIR 	= $(SDK_PATH)/tools

# F_CPU
F_CPU = 
# PROGRAMMER 
PROGRAMMER =
# MPROG 
MPROG = 
# MICRO
MICRO =

# Flash port (default: /dev/ttyUSB0)
FLASH_PORT ?= /dev/ttyUSB0
# Flash Baudrate (default: 115200)
FLASH_BAUDRATE ?= 115200
# Com Port (default: /dev/ttyUSB0)
COM_PORT ?= /dev/ttyUSB0
# Com Baudrate (default: 1000000)
COM_BAUDRATE ?= 1000000

FLASH_SIZE ?= 0
RAM_SIZE ?= 0
EEPROM_SIZE ?= 0

#
CXX = avr-g++
CC  = avr-gcc-9.1.0

#
C_SRCS := $(shell find $(SRC_DIR)/ -type f -regex ".*\.c") 

C_OBJS  = $(C_SRCS:.c=.o)

#
CXX_SRCS := $(shell find $(SRC_DIR)/ -type f -regex ".*\.cpp") 
CXX_OBJS  = $(CXX_SRCS:.cpp=.o)

#
ASM_SRCS  = $(shell find $(SRC_DIR)/ -type f -regex ".*\.s")
ASM_OBJS  = $(ASM_SRCS:.s=.o)

#
INCLUDE_DIR := -I /usr/lib/avr/include \
	$(addprefix -I ,$(shell find $(SRC_DIR) -name  '*.h' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(SRC_DIR) -name  '*.hpp' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(LIBS_DIR) -name  '*.h' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(LIBS_DIR) -name  '*.hpp' -exec dirname {} \; | sort| uniq)) 

#
CXX_FLAGS = -nostdlib -std=c++11 -Wmain -Wextra -fdata-sections -ffunction-sections \
			-funsigned-char -Wno-expansion-to-defined -funsigned-bitfields -fpack-struct -fshort-enums -D__COMPILE__ -DF_CPU=$(F_CPU) -DBAUD=9600 -mmcu=$(MICRO) $(INCLUDE_DIR) 
#
CC_FLAGS  = -nostdlib -std=gnu99 -Wmain -Wextra -fdata-sections -ffunction-sections \
			-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -D__COMPILE__ -DF_CPU=$(F_CPU) -DBAUD=9600 -mmcu=$(MICRO) $(INCLUDE_DIR) 
#
LD_FLAGS  = -Wl,-L$(LIBS_DIR)/static_lib -lysdk_$(MICRO) -Wl,--gc-sections -Wl,--strip-all
#LD_FLAGS  = -Wl,-u,vfprintf,-lprintf_flt -L$(STL)/static_lib -L/home/zetes/Documents/GitHub/AVR_SDK/libs/static_lib -lysdk_atmega328p

# Default target. (default atmega2560)
all: atmega2560

#
upload: 
	@killall hexdump putty 2>/dev/null || true
	@avrdude -F -q -v -p $(MPROG) -D -c $(PROGRAMMER) -b $(FLASH_BAUDRATE) -P $(FLASH_PORT) \
			-U flash:w:$(FIRMW_DIR)/main.hex:i
#
app: main.elf
	@avr-objcopy -j .text -j .data -O ihex $(ELF_DIR)/main.elf $(FIRMW_DIR)/main.hex
#
main.elf: $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS)
	@$(CXX) -mmcu=$(MICRO) -o $(ELF_DIR)/$@ $(OBJ_DIR)/*.o  $(LD_FLAGS)

# Show Memory Usage
size:
	@echo ''
	@bash -c ". $(TOOLS_DIR)/yanujzSize/yanujzSize $(ELF_DIR)/main.elf $(MICRO) $(FLASH_SIZE) $(RAM_SIZE) $(EEPROM_SIZE)"
#@avr-size --format=avr  -C --mcu=$(MICRO) $(ELF_DIR)/main.elf


%.o: %.c
	@echo "Compiling file : $(notdir $<)"
	@$(CC) $(CC_FLAGS) -Os  -c $<  -o $(OBJ_DIR)/$(notdir $@)
	@$(CC) $(CC_FLAGS) -Os -mmcu=$(MICRO) -E -o $(PREPROC_DIR)/$(notdir $(basename $@)).prepoc $<
	@$(CC) $(CC_FLAGS) -Os -mmcu=$(MICRO) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<

%.o: %.cpp
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS) -Os -mmcu=$(MICRO)  -c $<  -o $(OBJ_DIR)/$(notdir $@)
	@$(CXX) $(CXX_FLAGS) -Os -mmcu=$(MICRO) -E -o $(PREPROC_DIR)/$(notdir $(basename $@)).prepoc $<
	@$(CXX) $(CXX_FLAGS) -Os -mmcu=$(MICRO) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<

%.o: %.s
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS) -Os -mmcu=$(MICRO)  -c $<  -o $(OBJ_DIR)/$(notdir $@)

# Open putty with selected port
monitor:
	@killall hexdump putty 2>/dev/null || true
	@putty -serial $(COM_PORT) -sercfg $(COM_BAUDRATE)&
	@sleep 0.2

# Open terminal in raw mode. (Must be installed)
rawMonitor:
	@killall hexdump putty 2>/dev/null || true
	rawSerialMonitor $(COM_PORT) $(COM_BAUDRATE)

# Update Qt Files	
updateQtFiles:
	@bash -c ". $(TOOLS_DIR)/updateQtFiles/updateQtFiles $(shell dirname $(shell readlink Makefile))"

# Update Qt Files	
updateQtFiles_deploy:
	@bash -c ". $(TOOLS_DIR)/updateQtFiles/updateQtFiles $(shell dirname $(shell readlink Makefile)) deploy"

# 
createdir: $(BUILD_DIR) 

$(BUILD_DIR):
	@mkdir -p $@
	@mkdir -p $(ASM_DIR)
	@mkdir -p $(FIRMW_DIR) 
	@mkdir -p $(OBJ_DIR) 
	@mkdir -p $(ELF_DIR)
	@mkdir -p $(PREPROC_DIR) 


# Remove all build files
clean:
	@rm -rf $(BUILD_DIR)


# ATMEGA2560
# Compile for atmega2560.
atmega2560: MPROG := m2560
#
atmega2560: MICRO := atmega2560
atmega2560: F_CPU := 16000000
atmega2560: CXX_FLAGS += -D__MCU_ATMEGA2560__
atmega2560: CC_FLAGS += -D__MCU_ATMEGA2560__
atmega2560: FLASH_SIZE := 262144
atmega2560: RAM_SIZE := 8192
atmega2560: EEPROM_SIZE := 4096
atmega2560: createdir $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) main.elf app size

# Upload to an atmega2560 target. (FLASH_PORT = /dev/ttyACM0, FLASH_BAUDRATE = 115200)
atmega2560_upload: PROGRAMMER := stk500v2 
#
atmega2560_upload: MPROG := m2560
atmega2560_upload: MICRO := atmega2560
atmega2560_upload: F_CPU := 16000000
atmega2560_upload: FLASH_PORT := /dev/ttyACM0
atmega2560_upload: FLASH_BAUDRATE := 115200
atmega2560_upload: upload
# Build libraries for atmega2560.
atmega2560_buildlib:
	@make -C $(LIBS_DIR) atmega2560

# ATMEGA328P 
# Compile for atmega328p.
atmega328p: MPROG := m328p
#
atmega328p: MICRO := atmega328p
atmega328p: F_CPU := 16000000
atmega328p: CXX_FLAGS += -D__MCU_ATMEGA328P__
atmega328p: CC_FLAGS += -D__MCU_ATMEGA328P__
atmega328p: FLASH_SIZE := 32768
atmega328p: RAM_SIZE := 2048
atmega328p: EEPROM_SIZE := 1024	
atmega328p: createdir $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) main.elf app size

# Upload to an atmega328p target. (FLASH_PORT = /dev/ttyUSB0, FLASH_BAUDRATE = 115200)
atmega328p_upload: PROGRAMMER := arduino 
#
atmega328p_upload: MPROG := m328p
atmega328p_upload: MICRO := atmega328p
atmega328p_upload: F_CPU := 16000000
atmega328p_upload: FLASH_PORT := /dev/ttyUSB0
atmega328p_upload: FLASH_BAUDRATE := 115200
atmega328p_upload: upload
# Build libraries for atmega328p.
atmega328p_buildlib:
	@make -C $(LIBS_DIR) atmega328p



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
	@ echo '    make atmega2560'
	@ echo '    make atmega2560_upload FLASH_PORT=/dev/ttyACM0 FLASH_BAUDRATE=115200'
	@ echo '    make monitor COM_PORT=/dev/ttyACM0 COM_BAUDRATE=1000000'
	@ echo ''
