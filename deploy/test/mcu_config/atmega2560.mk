# ATMEGA2560
# Compile for atmega2560.
#atmega2560: MPROG := m2560
##
#atmega2560: MMCU := atmega2560
#atmega2560: F_CPU := 16000000
#atmega2560: CXX_FLAGS += -D__MCU_ATMEGA2560__
#atmega2560: CC_FLAGS += -D__MCU_ATMEGA2560__
#atmega2560: FLASH_SIZE := 262144
#atmega2560: RAM_SIZE := 8192
#atmega2560: EEPROM_SIZE := 4096
#atmega2560: createdir $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) main.elf app size
#
## Upload to an atmega2560 target. (FLASH_PORT = /dev/ttyACM0, FLASH_BAUDRATE = 115200)
#atmega2560_upload: PROGRAMMER := stk500v2 
##
#atmega2560_upload: MPROG := m2560
#atmega2560_upload: MMCU := atmega2560
#atmega2560_upload: F_CPU := 16000000
#atmega2560_upload: FLASH_PORT := /dev/ttyACM0
#atmega2560_upload: FLASH_BAUDRATE := 115200
#atmega2560_upload: upload
## Build libraries for atmega2560.
#atmega2560_buildlib:
#	@make -C $(LIBS_DIR) atmega2560
MMCU 		= atmega2560
F_CPU 		= 16000000
AS_DEFS 	= -D__MCU_ATMEGA2560__ -DF_CPU=$(F_CPU)
C_DEFS 		= -D__MCU_ATMEGA2560__ -DF_CPU=$(F_CPU)
CXX_DEFS 	= -D__MCU_ATMEGA2560__ -DF_CPU=$(F_CPU)


atmega2560: all