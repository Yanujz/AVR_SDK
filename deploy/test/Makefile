######################################
# target
######################################
TARGET 	= main
ELF_NAME = $(TARGET).elf
BIN_NAME = $(TARGET).bin
HEX_NAME = $(TARGET).hex


######################################
# compilation settings
######################################
# MCU cfg dir
MCU_CFG_MK  = mcu_config



# Set external libraries path
EXT_LIBS_DIR = ext_libs


# OS specific part
ifeq ($(OS),Windows_NT)
	CUR_DIR = ${shell cygpath -m $$(pwd)}
else
	CUR_DIR = $(shell pwd)
	EXT_LIBS_DIR := $(shell realpath $(EXT_LIBS_DIR))
endif

# Remove space after separator
PSEP = $(strip $(SEP))

# Decide whether the commands will be shwon or not
VERBOSE = FALSE

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =  
else
    HIDE = @
endif



#######################################
# INCLUDE
#######################################
ifneq ($(firstword $(MAKECMDGOALS)), clean)
ifeq ($(firstword $(MAKECMDGOALS)), )
$(error "CHOOSE A BOARD")
exit -1
endif

BOARD_CFG = $(MCU_CFG_MK)/$(firstword $(MAKECMDGOALS)).mk
ifeq ($(wildcard $(BOARD_CFG)),)
$(error "BOARD NOT SUPPORTED. PLEASE ADD CONFIG FILE INTO $(MCU_CFG_MK) DIR")
exit -1
endif
include $(BOARD_CFG)
endif



#######################################
# paths
#######################################
# Build path
SRC_DIR 	= src
BUILD_DIR 	= build
ASM_DIR 	= $(BUILD_DIR)/asm
FIRMW_DIR 	= $(BUILD_DIR)/firmware
OBJ_DIR 	= $(BUILD_DIR)/obj
ELF_DIR 	= $(BUILD_DIR)/elf
MAP_DIR 	= $(BUILD_DIR)/map
PREPROC_DIR = $(BUILD_DIR)/prepoc
INT_LIBS_DIR 	 = int_libs
SRC_DIR 		 = src


ifneq ($(firstword $(MAKECMDGOALS)), clean)
	BUILD_DIR := $(BUILD_DIR)/$(firstword $(MAKECMDGOALS))
endif

#######################################
# binaries
#######################################
PREFIX = avr-

ifdef GCC_PATH
CXX = $(GCC_PATH)/$(PREFIX)g++
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CXX  = $(PREFIX)g++
CC 	= $(PREFIX)gcc
AS 	= $(PREFIX)gcc -x assembler-with-cpp
CP 	= $(PREFIX)objcopy
SZ 	= $(PREFIX)size
endif

HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S


######################################
# source
######################################
# ASM sources
A_SRCS := $(shell find $(EXT_LIBS_DIR) $(INT_LIBS_DIR) $(SRC_DIR) -type f -regex ".*\.s") 
A_OBJS = $((A_SRCS:.S=.o)
A_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(A_OBJS)))
vpath %.s $(sort $(dir $(A_SRCS)))


#
C_SRCS := $(shell find  $(EXT_LIBS_DIR) $(INT_LIBS_DIR) $(SRC_DIR) -type f -regex ".*\.c") 
C_OBJS = $(CXX_SRCS:.cpp=.o)
C_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(C_OBJS)))
vpath %.c $(sort $(dir $(C_SRCS)))

#
CXX_SRCS := $(shell find $(EXT_LIBS_DIR) $(INT_LIBS_DIR) $(SRC_DIR) -type f -regex ".*\.cpp") 
CXX_OBJS = $(CXX_SRCS:.cpp=.o)
CXX_OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(CXX_OBJS)))
vpath %.cpp $(sort $(dir $(CXX_SRCS)))


#######################################
# INCLUDE DIR
#######################################
AVR_LIB_DIR = $(addprefix -I ,/usr/lib/avr/include)
INCLUDE_DIR = $(AVR_LIB_DIR) \
	$(addprefix -I ,$(shell find $(SRC_DIR) -name  '*.h' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(SRC_DIR) -name  '*.hpp' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(INT_LIBS_DIR) -name  '*.h' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(INT_LIBS_DIR) -name  '*.hpp' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(EXT_LIBS_DIR) -name  '*.h' -exec dirname {} \; | sort| uniq)) \
	$(addprefix -I ,$(shell find $(EXT_LIBS_DIR) -name  '*.hpp' -exec dirname {} \; | sort| uniq)) 


OPT =


#######################################
# COMM FLAGS
#######################################
# Custom flags for [COMM_FLAGS]
USER_COMM_FLAGS ?=
COMM_FLAGS += $(INCLUDE_DIR) -mmcu=$(MMCU) $(OPT) -fdata-sections -ffunction-sections -D__COMPILE__

# Warning 
COMM_FLAGS += -Wall



######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Os


ifeq ($(DEBUG), 1)
	COMM_FLAGS += -g #-gdwarf-2
else
	COMM_FLAGS += $(OPT)
endif

#######################################
# ASFLAGS
#######################################
USER_ASM_FLAGS ?=
ASM_FLAGS += $(COMM_FLAGS) $(AS_DEFS) $(USER_ASM_FLAGS)


#######################################
# CFLAGS
#######################################
# Custom flags for [CC_FLAGS]
USER_C_FLAGS ?=
C_FLAGS += $(COMM_FLAGS) $(C_DEFS) $(USER_C_FLAGS) -std=gnu99


#######################################
# CXXFLAGS
#######################################
# Custom flags for [CXX_FLAGS]
USER_CXX_FLAGS ?=
CXX_FLAGS += $(COMM_FLAGS) $(CXX_DEFS) $(USER_CXX_FLAGS) -std=c++14 -Wno-old-style-cast


#######################################
# LDFLAGS
#######################################
# Custom flags for [LD_FLAGS]
USER_LD_FLAGS ?= 
LD_FLAGS += -mmcu=$(MMCU) $(USER_LD_FLAGS) -Wl,-Map=$(MAP_DIR)/$(TARGET).map
ifeq ($(DEBUG), 1)

else
LD_FLAGS += -Wl,--gc-sections -Wl,--strip-all
endif

#######################################
# build the application
#######################################
all: createdir $(ELF_NAME) #$(HEX_NAME) $(BIN_NAME)

OBJS += $(addprefix $(OBJ_DIR)/, $(notdir $(ASM_OBJS)))
OBJS += $(addprefix $(OBJ_DIR)/, $(notdir $(C_OBJS)))
OBJS += $(addprefix $(OBJ_DIR)/, $(notdir $(CXX_OBJS)))


$(HEX_NAME): $(ELF_DIR)/$(ELF_NAME)
	@echo "[COMPILING HEX]: $(notdir $@)"
	$(HIDE)$(HEX) $< $(FIRMW_DIR)/$@
	
$(BIN_NAME): $(ELF_DIR)/$(ELF_NAME)
	@echo "[COMPILING BIN]: $(notdir $@)"
	$(HIDE)$(BIN) $< $(FIRMW_DIR)/$@	

$(ELF_NAME): $(ASM_OBJS) $(C_OBJS) $(CXX_OBJS)
	@echo "[COMPILING ELF]: $(notdir $@)"
	$(CXX) -o $(ELF_DIR)/$@ $(OBJ_DIR)/*.o $(LD_FLAGS) 
	$(HIDE)$(SZ) $(ELF_DIR)/$@
	@echo "[LINKING]: Done."

	
$(OBJ_DIR)/%.o: %.s 
	@echo "[COMPILING ASM]: $(notdir $<)"
	$(HIDE)$(AS) $(ASFLAGS) -c  $< -o $(OBJ_DIR)/$(notdir $@)
	
$(OBJ_DIR)/%.o: %.c
	@echo "[COMPILING C]: $(notdir $<)"
	$(HIDE)$(CC) $(C_FLAGS) -c $<  -o $@
	$(HIDE)$(CC) $(C_FLAGS) -E -o $(PREPROC_DIR)/$(notdir $(basename $@)).prepoc $<
	$(HIDE)$(CC) $(C_FLAGS) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<

$(OBJ_DIR)/%.o: %.cpp
	@echo "[COMPILING CXX]: $(notdir $<)"
	$(HIDE)$(CXX) $(CXX_FLAGS) -c  $< -o $@
	$(HIDE)$(CXX) $(CXX_FLAGS) -E -o $(PREPROC_DIR)/$(notdir $(basename $@)).prepoc $<
	$(HIDE)$(CXX) $(CXX_FLAGS) -S -o $(ASM_DIR)/$(notdir $(basename $@)).s $<


#######################################
# create dir
#######################################
createdir:
	@echo "[CREATING DIRECTORIES]"
	$(HIDE)mkdir -p $(FIRMW_DIR) 
	$(HIDE)mkdir -p $(ASM_DIR)
	$(HIDE)mkdir -p $(OBJ_DIR) 
	$(HIDE)mkdir -p $(ELF_DIR)
	$(HIDE)mkdir -p $(MAP_DIR)
	$(HIDE)mkdir -p $(PREPROC_DIR)
	@echo "[DONE]"


#######################################
# clean up
#######################################
clean:
	@echo "[CLEANING]"
	$(HIDE)rm -rf $(BUILD_DIR)
	@echo "[DONE]"
	

