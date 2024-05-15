# MIT License
#
# Copyright (c) 2024 Uriel García Rivas
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# https://github.com/zoningorg/zoning/blob/main/LICENSE

# Compilation.
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -I./inc/

# All targets. This assumes there exists a .h, .c, and _test.c per target.
TARGETS = array \
	hash_map \
	hash_set \
	linked_list \
	sort_map \
	sort_set

# Object files.
OBJ_DIR = ./obj
OBJ = $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

# Binary files.
SRC_DIR = ./test/src
BIN_DIR = ./test/bin
BIN = $(patsubst %,$(BIN_DIR)/%_test,$(TARGETS))

# Top-level rule.
all: test

# General rule for every object file.
$(OBJ_DIR)/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# General rule for every test binary.
$(BIN_DIR)/%_test: $(SRC_DIR)/%_test.c $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) $^ -o $@

# Automatic rule to run all tests in BIN.
# Stop if one test fails.
test: $(BIN)
	for test_binary in $(BIN); do \
		./$$test_binary; \
		[[ $$? -ne 0 ]] && break; \
	done; \
	make clean

# Remove created files.
clean:
	rm -f $(OBJ) $(BIN)
