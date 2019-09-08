SRC_DIR 	= src
BUILD_DIR 	= build
APP_DIR 	= app
PARAMS  ?=""

CXX       = g++


CXX_SRCS := $(shell find $(SRC_DIR)/ -type f -regex ".*\.cpp")
CXX_OBJS  = $(CXX_SRCS:.cpp=.o)


INCLUDE_DIR := 	$(addprefix -I ,$(shell find $(SRC_DIR)/ -name  *.h -exec dirname {} \;))



CXX_FLAGS = -lstdc++ -std=c++11 $(INCLUDE_DIR)  
LD_FLAGS  = -Wl,-u,vfscanf,-lscanf_flt,-u,vfprintf,-lprintf_flt


#
all: createdir $(CXX_OBJS) executable

executable: 
	@$(CXX) -o $(APP_DIR)/asmCycleCounter $(BUILD_DIR)/*.o
%.o: %.cpp
	@echo "Compiling file : $(notdir $<)"
	@$(CXX) $(CXX_FLAGS) -Os  -c $<  -o $(BUILD_DIR)/$(notdir $@)
	

run:
	@./$(APP_DIR)/app $(PARAMS)



# 
createdir: $(BUILD_DIR) $(APP_DIR) 

$(BUILD_DIR):
	@mkdir -p $@
$(APP_DIR):
	@mkdir -p $@


# Remove all build files
clean:
	@rm -rf $(BUILD_DIR) $(APP_DIR)




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
