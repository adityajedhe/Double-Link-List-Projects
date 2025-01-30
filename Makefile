# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = tower_of_hanoi

# Source files
SRCS = ./Source/main.cpp ./Source/DiskNode.cpp ./Source/DiskStack.cpp

# Object files
OBJS = $(SRCS:.cpp -I ./Headers/=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I ./Headers/ -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
