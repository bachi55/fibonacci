CXX = g++

# Flags related to the google-test
GTESTFLAGS = -isystem $(GTEST_DIR)/include -pthread

CXXFLAGS = -Wall -Wextra 
CXXFLAGS += $(GTESTFLAGS) -Iinclude 

LDFLAGS = -L$(GTEST_DIR)/lib -lgtest

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
BINARY = bin/fibonacci

# Suffix rule to handle source-code files and compile them
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all
all: build

.PHONY: build
build: $(BINARY)

# Rule to handly object files and link them
$(BINARY): $(OBJECTS)
	@echo $(CXX) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(BINARY)