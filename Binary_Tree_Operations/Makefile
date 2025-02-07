# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -I ./Headers/

# Target executable
TARGET = binary_tree

# Directories
SRC_DIR = ./Sources
OBJ_DIR = ./Objects

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (in the obj directory)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
