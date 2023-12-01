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
CFLAGS = -Wall -Werror -Wpedantic

all: test
test: hash_map_test hash_set_test linked_list_test sort_map_test sort_set_test
	( ./hash_map_test && ./hash_set_test && ./linked_list_test \
		&& ./sort_map_test && ./sort_set_test ) ; make clean

linked_list_test: test/linked_list_test.c linked_list.o
	$(CC) $(CFLAGS) test/linked_list_test.c -o linked_list_test src/linked_list.o

linked_list.o: src/linked_list.c src/linked_list.h
	$(CC) $(CFLAGS) -c src/linked_list.c -o src/linked_list.o

hash_map_test: test/hash_map_test.c
	$(CC) $(CFLAGS) test/hash_map_test.c -o hash_map_test

hash_set_test: test/hash_set_test.c
	$(CC) $(CFLAGS) test/hash_set_test.c -o hash_set_test

sort_map_test: test/sort_map_test.c
	$(CC) $(CFLAGS) test/sort_map_test.c -o sort_map_test

sort_set_test: test/sort_set_test.c
	$(CC) $(CFLAGS) test/sort_set_test.c -o sort_set_test

clean:
	rm linked_list_test hash_map_test hash_set_test sort_map_test \
		sort_set_test src/linked_list.o

#  $(wildcard *.o)
