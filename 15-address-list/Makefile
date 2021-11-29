CC         = gcc
CC_FLAGS   = -std=c99 -Wall -I.

SRC_DIR    = src
BUILD_DIR  = build
OBJ_DIR    = $(BUILD_DIR)/bin
BIN_DIR    = $(BUILD_DIR)/bin
FINAL_NAME = address-list
MAIN_NAME  = main

SOURCES    := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*/*/*.c)
INCLUDES   := $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/*/*.h) $(wildcard $(SRC_DIR)/*/*/*.h)
OBJECTS    := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RMDIR      = rm -rf
MKDIR      = mkdir -p
COPY       = cp

all: build

init:
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(BIN_DIR)

.PHONY: clean
clean:
	@$(RMDIR) $(BUILD_DIR)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(MKDIR) $@
	@rm -d $@

	@$(CC) $(CC_FLAGS) -c $< -o $@

build: clean init $(OBJECTS)
	@$(CC) -o $(BIN_DIR)/$(MAIN_NAME) $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o $(OBJ_DIR)/*/*/*.o
	@$(COPY) $(BIN_DIR)/$(MAIN_NAME) $(BUILD_DIR)/$(FINAL_NAME)
