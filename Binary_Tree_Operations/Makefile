# Compiler
CCPP = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -I ../SharedHeaders/ -I ./LocalHeaders/

# Directories
SRC_DIR = ./Sources
OBJ_DIR = ./Objects
OUTPUT_DIR = ../bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (in the obj directory)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(OUTPUT_DIR)/binary_tree

# Default target
all: $(OBJ_DIR) $(OUTPUT_DIR) $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@$(CCPP) -o $@ $^ -L $(OUTPUT_DIR)/ -lNode

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

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
