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

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -I./inc/
INC = ./inc/array.h ./inc/hash_map.h ./inc/hash_set.h ./inc/linked_list.h \
	./inc/sort_map.h ./inc/sort_set.h
OBJ = $(patsubst ./inc/%.h,./obj/%.o,$(INC))
TEST_DIR = ./test/bin
TEST_SRCS = $(wildcard ./test/src/*.c)
TESTS = $(patsubst ./test/src/%.c,$(TEST_DIR)/%,$(TEST_SRCS))

all: test

test: $(TESTS)
	for TEST in $(TESTS); do \
		./$$TEST; \
		[[ $$? -ne 0 ]] && break; \
	done; \
	make clean

$(TEST_DIR)/%: ./test/src/%.c $(OBJ)
	mkdir -p $(TEST_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(filter %.o,$^)

./obj/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TEST_DIR)/* $(OBJ)

#  $(wildcard *.o)
