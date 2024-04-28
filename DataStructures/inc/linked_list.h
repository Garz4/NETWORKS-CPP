/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel García Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zoning/blob/main/LICENSE
 */

#ifndef __ZNG_LINKED_LIST_H__
#define __ZNG_LINKED_LIST_H__

#include <stdbool.h>
#include <stdlib.h>

typedef struct __zng_ll_node {
  int value;
  struct __zng_ll_node* next;
} linked_list_node;

typedef struct __zng_ll {
  size_t size;
  linked_list_node* head;
  linked_list_node* tail;
} linked_list;

// Every new linked list needs to be deleted using delete_linked_list(...).
extern linked_list* new_linked_list(int value);

// Example output to screen: "list = {1, 2, 3, 4, 5};"
extern void print_linked_list(const linked_list*const list);

// Linear time, stops when finding the first occurence.
extern bool exist_in_linked_list(const linked_list*const list, int value);

extern void add_to_linked_list(linked_list*const list, int value);

extern void delete_linked_list(linked_list* list);

// Erases first occurence of 'target' in the linked list.
// It frees its memory.
extern void erase_single_match_linked_list(linked_list* list, int target);

extern void erase_all_match_linked_list(linked_list* list, int target);

// Linear time.
extern void reverse_linked_list(linked_list*const list);

// By making a copy, deleting that copy is also necessary.
extern linked_list* copy_linked_list(const linked_list*const list);

extern bool are_equal_linked_list(
    const linked_list*const lhs, const linked_list*const rhs);

extern void sort_linked_list(linked_list*const list);

extern bool is_empty_linked_list(const linked_list*const list);

#endif // __ZNG_LINKED_LIST_H__
