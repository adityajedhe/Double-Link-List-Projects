# Makefile for compiling a C++ project into a shared library.
# Detects the operating system to set appropriate library suffix.
# Compiles source files from ./Sources directory into object files in ./Objects directory.
# Links object files to create a shared library in ../bin directory.
# Provides targets for building, cleaning, and creating necessary directories.

# Detect the operating system
OS := $(shell uname)

# Compiler
CCPP = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -I ../SharedHeaders/ -fPIC

# Directories
SRC_DIR = ./Sources
OBJ_DIR = ./Objects
OUTPUT_DIR = ../bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (in the obj directory)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Library settings
ifeq ($(OS),Linux)
    LIB_NAME = libNode
    LIB_SUFFIX := .so
else
    LIB_NAME = Node
    LIB_SUFFIX := .dll
endif

# Output Library
TARGET = $(OUTPUT_DIR)/$(LIB_NAME)$(LIB_SUFFIX)

# Default target
all: $(OBJ_DIR) $(OUTPUT_DIR) $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
    @$(CCPP) -shared -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @$(CCPP) $(CFLAGS) -c $< -o $@

# Create output directory if it isn't exist
$(OUTPUT_DIR):
    @mkdir -p $(OUTPUT_DIR)

$(OBJ_DIR):
    @mkdir -p $(OBJ_DIR)

# Clean up build files
clean:
    @rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean