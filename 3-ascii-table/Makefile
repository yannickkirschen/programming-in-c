CC         = gcc
CC_FLAGS   = -std=c99 -Wall -I.

SRC_DIR    = src
BUILD_DIR  = build
OBJ_DIR    = $(BUILD_DIR)/bin
BIN_DIR    = $(BUILD_DIR)/bin
FINAL_NAME = ascii-table

SOURCES    := $(wildcard $(SRC_DIR)/*.c)
INCLUDES   := $(wildcard $(SRC_DIR)/*.h)
OBJECTS    := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
rm         = rm -rf
mkdir      = mkdir -p

all: build

init:
	@$(mkdir) $(OBJ_DIR)
	@$(mkdir) $(BIN_DIR)

.PHONY: clean
clean:
	@$(rm) -rf $(BUILD_DIR)
	@echo "Cleanup complete!"

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

build: clean init $(OBJECTS)
	@$(CC) -o $(BIN_DIR)/$(FINAL_NAME) $(OBJ_DIR)/*.o
	@echo "Compiled $(BIN_DIR)/$(FINAL_NAME) successfully!"
