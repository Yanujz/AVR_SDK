BUILD_DIR 	= build
STATICLIB_DIR = static_lib
ASM_DIR 	= $(BUILD_DIR)/asm
OBJ_DIR 	= $(BUILD_DIR)/obj
DOXYGEN_DIR = $(SDK_PATH)/docs/doxygen
DOXYGEN_CFG = doxygen.conf
# Select F_CPU (default: 16000000)
F_CPU = 
# Select microntroller (default: atmega2560)
MICRO = 
# Select SDK Path (default: lib_atmega2560.a)
LIBNAME = 

#
ASM_SRCS  = $(shell find ./ -type f -regex ".*\.s")
ASM_OBJS  = $(ASM_SRCS:.s=.o)

#
CXX_SRCS := $(shell find ./ -type f -regex ".*\.cpp")
CXX_OBJS  = $(CXX_SRCS:.cpp=.o)

#
C_SRCS := $(shell find ./ -type f -regex ".*\.c")
C_OBJS  = $(C_SRCS:.c=.o)

INCLUDE_DIR := -I /usr/lib/avr/include \
	$(addprefix -I ,$(shell find ./ -name  '*.h' -exec dirname {} \;)) \
	$(addprefix -I ,$(shell find ./ -name  '*.hpp' -exec dirname {} \;))
#
CXX_FLAGS =  $(INCLUDE_DIR) -Os -D__COMPILE__ -DBAUD=9600 -DF_CPU=$(F_CPU) -std=c++17 -mmcu=$(MICRO) -nostartfiles -nostdlib -nodefaultlibs -Wmain -Wextra  -Wno-maybe-uninitialized \
			-fdata-sections -Wno-expansion-to-defined -ffunction-sections -funsigned-char -funsigned-bitfields  #-D__FLOAT_SUPPORT__
#
CC_FLAGS  =  $(INCLUDE_DIR) -Os -D__COMPILE__ -DBAUD=9600 -DF_CPU=$(F_CPU) -std=gnu99 -mmcu=$(MICRO) -nostartfiles -nostdlib -nodefaultlibs -Wmain -Wextra  -Wno-maybe-uninitialized \
			-fdata-sections -Wno-expansion-to-defined -ffunction-sections -funsigned-char -funsigned-bitfields 

#
CXX = avr-g++ 
CC  = avr-gcc 
AS  = avr-as
#
all: atmega2560

deploy: clean createdir $(ASM_OBJS) $(C_OBJS) $(CXX_OBJS) lib

#
lib: $(CXX_OBJS)
	@echo "Creating library"
	@avr-ar rcs $(STATICLIB_DIR)/$(LIBNAME) $(OBJ_DIR)/*.o
	@echo "Removing $(BUILD_DIR)/*.o"
	@rm -rf $(BUILD_DIR)/
	
%.o: %.c
	@echo "Compiling file : $(notdir $<)"
	@$(CC) $(CC_FLAGS)  -c $<  -o $(OBJ_DIR)/$(notdir $@)
	@$(CC) $(CC_FLAGS) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<

%.o: %.cpp
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS)  -c $<  -o $(OBJ_DIR)/$(notdir $@)
	@$(CXX) $(CXX_FLAGS) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<

%.o: %.s
	@echo "Compiling file : $(notdir $<)"
	@$(AS) -mmcu=$(MICRO)  -c $<  -o $(OBJ_DIR)/$(notdir $@)


#
createdir: $(BUILD_DIR) $(STATICLIB_DIR)

$(BUILD_DIR):
	@mkdir -p $@ $(ASM_DIR)
	@mkdir -p $@ $(OBJ_DIR)
$(STATICLIB_DIR):
	@mkdir -p $@

# Remove all build files
clean:
	@echo "Cleaning"
	@rm -rf $(BUILD_DIR)
	@rm -rf $(STATICLIB_DIR)

# Generate doxygen doc.
doxygen:
	@echo "Generating Documentation..."
	@bash -c "(cd $(DOXYGEN_DIR) && doxygen $(DOXYGEN_CFG) 2>/dev/null)"
	@echo "Done."

# ATMEGA2560
# Compile for atmega2560
atmega2560: MPROG := m2560
#
atmega2560: MICRO := atmega2560
atmega2560: F_CPU := 16000000
atmega2560: LIBNAME := libysdk_$(MICRO).a
atmega2560: CXX_FLAGS += -D__MCU_ATMEGA2560__
atmega2560: CC_FLAGS += -D__MCU_ATMEGA2560__
atmega2560: deploy

# ATMEGA328P
# Compile for atmega2560
atmega328p: MPROG := m328p
#
atmega328p: MICRO := atmega328p
atmega328p: F_CPU := 16000000
atmega328p: LIBNAME := libysdk_$(MICRO).a
atmega328p: CXX_FLAGS += -D__MCU_ATMEGA328P__
atmega328p: CC_FLAGS += -D__MCU_ATMEGA328P__	
atmega328p: deploy






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
	@ echo ''
	@ echo ''
