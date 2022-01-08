# MIT License
#
# Copyright (c) 2021 Uriel Rivas
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# https://github.com/Garz4/zoning/blob/master/LICENSE

all: test
	./linked_list_test ; make clean

test: hash_map_test hash_set_test linked_list_test sort_map_test sort_set_test
	(./hash_map_test && ./hash_set_test && ./linked_list_test && ./sort_map_test && ./sort_set_test) ; make clean

linked_list_test: test/linked_list_test.c
	gcc test/linked_list_test.c -o linked_list_test

hash_map_test: test/hash_map_test.c
	gcc test/hash_map_test.c -o hash_map_test

hash_set_test: test/hash_set_test.c
	gcc test/hash_set_test.c -o hash_set_test

sort_map_test: test/sort_map_test.c
	gcc test/sort_map_test.c -o sort_map_test

sort_set_test: test/sort_set_test.c
	gcc test/sort_set_test.c -o sort_set_test

clean:
	rm linked_list_test hash_map_test hash_set_test sort_map_test sort_set_test

#  $(wildcard *.o)
