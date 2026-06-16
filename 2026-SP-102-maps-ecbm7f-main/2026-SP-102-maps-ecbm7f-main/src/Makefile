RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
RESET  := \033[0m

CXX            := g++
CXXFLAGS       := -std=c++17 -O0 -g -Wall -Wextra -Wpedantic -pedantic-errors -Iinclude
HEADERS        := $(wildcard include/*)

# Directories
BUILD_DIR := ../build
MAIN_DIR  := example_mains
CODE_DIR := map_implementations

# Executable names
BST_MAIN   := $(BUILD_DIR)/bst_main
AVL_MAIN  := $(BUILD_DIR)/avl_main
HASH_MAIN := $(BUILD_DIR)/hash_main
GENERIC_MAIN := $(BUILD_DIR)/generic_main

all: $(BST_MAIN) $(AVL_MAIN) $(HASH_MAIN) $(GENERIC_MAIN)

# Individual Test Targets
$(BST_MAIN): $(MAIN_DIR)/bst_map.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(AVL_MAIN): $(MAIN_DIR)/avl_map.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(HASH_MAIN): $(MAIN_DIR)/hash_map.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(GENERIC_MAIN): $(MAIN_DIR)/generic_map.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@


clean:
	rm -f $(BST_MAIN) $(AVL_MAIN) $(HASH_MAIN) $(GENERIC_MAIN)

.PHONY: all clean
