#TODO: Are optimization and debug flags also needed in the linking step? 

CXX = g++

CXXFLAGS = -Wall -Iinclude

OPTIFLAGS = -O3
DEBUGFLAGS = -g

# Flags related to the google-test
CXXGTESTFLAGS = -DUNITTEST -isystem $(GTEST_DIR)/include -pthread
LDGTESTFLAGS = -L$(GTEST_DIR)/lib -lgtest -pthread

SOURCES = $(wildcard src/*.cpp)

OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
OBJECTS_TEST = $(patsubst %.cpp, %_test.o, $(SOURCES))
OBJECTS_DEBUG = $(patsubst %.cpp, %_debug.o, $(SOURCES))

BINARY = bin/fibonacci
BINARY_TEST = bin/fibonacci_test
BINARY_DEBUG = bin/fibonacci_debug

# Suffix rule to handle source-code files and compile them
%.o: %.cpp
	$(CXX) $(OPTIFLAGS) $(CXXFLAGS) -c $< -o $@

%_test.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXGTESTFLAGS) -c $< -o $@

%_debug.o: %.cpp
	$(CXX) $(DEBUGFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: all
all: build

.PHONY: build
build: $(BINARY)

.PHONY: tests
tests: $(BINARY_TEST)

.PHONY: DEBUGFLAGS
debug: $(BINARY_DEBUG)

# Rule to handly object files and link them
$(BINARY): $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@

$(BINARY_TEST): $(OBJECTS_TEST)
	$(CXX) $^ $(LDFLAGS) $(LDGTESTFLAGS) -o $@

$(BINARY_DEBUG): $(OBJECTS_DEBUG)
	$(CXX) $^ $(LDFLAGS) -o $@


.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(OBJECTS_TEST) $(OBJECTS_DEBUG) $(BINARY) $(BINARY_TEST) $(BINARY_DEBUG)