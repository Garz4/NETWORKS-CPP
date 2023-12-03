# MIT License
#
# Copyright (c) 2024 Uriel Rivas
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
CFLAGS = -Wall -Werror -Wpedantic -I./inc/
INC = ./inc/linked_list.h ./inc/sort_set.h
SRC = $(patsubst ./inc/%.h,./src/%.c,$(INC))
OBJ = $(patsubst ./inc/%.h,./obj/%.o,$(INC))

all: test
test: hash_map_test hash_set_test linked_list_test sort_map_test sort_set_test
	( ./hash_map_test && ./hash_set_test && ./linked_list_test \
		&& ./sort_map_test && ./sort_set_test ) ; make clean

./obj/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

linked_list_test: test/linked_list_test.c $(OBJ)
	$(CC) $(CFLAGS) $(INC) $< -o $@ $(OBJ)

hash_map_test: test/hash_map_test.c $(OBJ)
	$(CC) $(CFLAGS) $(INC) $< -o $@ $(OBJ)

hash_set_test: test/hash_set_test.c $(OBJ)
	$(CC) $(CFLAGS) $(INC) $< -o $@ $(OBJ)

sort_map_test: test/sort_map_test.c $(OBJ)
	$(CC) $(CFLAGS) $(INC) $< -o $@ $(OBJ)

sort_set_test: test/sort_set_test.c $(OBJ)
	$(CC) $(CFLAGS) $(INC) $< -o $@ $(OBJ)

clean:
	rm linked_list_test hash_map_test hash_set_test sort_map_test \
		sort_set_test $(OBJ)

#  $(wildcard *.o)
