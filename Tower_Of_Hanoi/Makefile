# Compiler
CCPP = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -I ../Headers/ -I ./LocalHeaders/

# Directories
SRC_DIR = ./Sources
OBJ_DIR = ./Objects

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (in the obj directory)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(OBJ_DIR)/tower_of_hanoi

# Path to dll
DLL_PATH = ../$(OBJ_DIR)/Node.dll

# Default target
all: $(OBJ_DIR) $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@$(CCPP) -o $@ $^ -L ../Objects/ -lNode

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CCPP) $(CFLAGS) -c $< -o $@

# Create output directory if it isn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean up build files
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
