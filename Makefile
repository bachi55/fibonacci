# Different between '=' and ':='
# 'var  =' ... evaluated recursively every time 'var' is called
# 'var :=' ... evaluated just ones when 'var' is defined

CXX 		:= g++
LD 		:= g++
MKDIR 		:= mkdir
RM		:= rm -rf
CXXFLAGS 	 = -Wall

OPTIFLAGS 	:= -O3
DEBUGFLAGS 	:= -g
ifeq ($(BUILD), debug)
	CXXFLAGS += $(DEBUGFLAGS)
else
	CXXFLAGS += $(OPTIFLAGS)
endif

CXXFLAGS += -Iinclude

# Flags related to the google-test
CXXGTESTFLAGS 	:= -isystem $(GTEST_DIR)/include -pthread
LDGTESTFLAGS 	:= -L$(GTEST_DIR)/lib -lgtest -pthread

SOURCES 	:= $(wildcard src/*.cpp)
OBJECTS 	:= $(patsubst %.cpp, %.o, $(SOURCES))

SOURCES_BUILD 	:= $(wildcard src/build/*.cpp)
OBJECTS_BUILD 	:= $(patsubst %.cpp, %.o, $(SOURCES_BUILD))

SOURCES_TEST 	:= $(wildcard src/unittest/*.cpp)
OBJECTS_TEST 	:= $(patsubst %.cpp, %.o, $(SOURCES_TEST))

OUT 		:= bin
BINARY_BUILD 	:= $(OUT)/fibonacci
BINARY_TEST 	:= $(OUT)/unittest

.PHONY: all
all : build

.PHONY: build
build : $(BINARY_BUILD)

.PHONY: tests
tests : CXXFLAGS += $(CXXGTESTFLAGS)
tests : LDFLAGS  += $(LDGTESTFLAGS)
tests : $(BINARY_TEST)
	@exec $(BINARY_TEST)

# | reffers to a 'order-only' prerequisite. It requiers make 3.80!
# Source: http://www.cmcrossroads.com/article/making-directories-gnu-make?page=0%2C1
$(BINARY_BUILD) : $(OBJECTS) $(OBJECTS_BUILD) | $(OUT)/
	$(LD) $^ $(LDFLAGS) -o $@

$(BINARY_TEST) : $(OBJECTS) $(OBJECTS_TEST) | $(OUT)/
	$(LD) $^ $(LDFLAGS) -o $@

$(OUT)/ :
	$(MKDIR) $@
	
.PHONY: clean
clean :
	$(RM) $(OUT) $(OBJECTS) $(OBJECTS_TEST) $(OBJECTS_TEST)