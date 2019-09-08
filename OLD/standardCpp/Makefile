BUILD_DIR 	= build
STATICLIB_DIR = static_lib
# Select FCPU (default: 16000000)
FCPU ?= 16000000
# Select microntroller (default: atmega2560)
MICROCONTROLLER ?= atmega2560
# Select SDK Path (default: lib_atmega2560.a)
LIBNAME ?= libysdk$(MICROCONTROLLER)_stl.a

#
CXX_SRCS := $(shell find ./ -type f -regex ".*\.cpp")
CXX_OBJS  = $(CXX_SRCS:.cpp=.o)
INCLUDE_DIR := -I .

#
CXX_FLAGS = -lstdc++ -std=c++14
#
CXX = avr-g++
#
all: createdir $(CXX_OBJS) lib

#
lib:
	@echo "Creating library"
	@avr-ar rcs $(STATICLIB_DIR)/$(LIBNAME) $(BUILD_DIR)/*.o
	@echo "Removing $(BUILD_DIR)/*.o"
	@rm -rf $(BUILD_DIR)
#
%.o: %.cpp
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS) $(INCLUDE_DIR) -Os -DF_CPU=$(FCPU) -mmcu=$(MICROCONTROLLER)  -c $<  -o $(BUILD_DIR)/$(notdir $@)


#
createdir: $(BUILD_DIR) $(STATICLIB_DIR)

$(BUILD_DIR):
	@mkdir -p $@
$(STATICLIB_DIR):
	@mkdir -p $@

# Remove all build files
clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(STATICLIB_DIR)

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
