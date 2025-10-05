# ====================================================
# Makefile for ROLL_NO-OS-A02
# Feature: Initial Build (ls-v1.0.0)
# Instructor: Dr. Muhammad Arif Butt
# ====================================================

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
SRC = $(SRC_DIR)/lsv1.0.0.c
OBJ = $(OBJ_DIR)/lsv1.0.0.o
TARGET = $(BIN_DIR)/ls

# Default rule
all: setup $(TARGET)

# Create required directories if they don't exist
setup:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(SRC_DIR) $(BIN_DIR) $(OBJ_DIR) $(SRC_DIR) $(BIN_DIR) man

# Rule to build the target
$(TARGET): $(OBJ)
	@echo "🔧 Linking object files..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo "✅ Build successful! Executable created at $(TARGET)"

# Rule to build object files
$(OBJ): $(SRC)
	@echo "🧩 Compiling source file..."
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Run the program
run: all
	@echo "🚀 Running program..."
	@./$(TARGET)

# Clean build files
clean:
	@echo "🧹 Cleaning object and binary files..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "✅ Clean complete."

# Phony targets
.PHONY: all setup clean run
