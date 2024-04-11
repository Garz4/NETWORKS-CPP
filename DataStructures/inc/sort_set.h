/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel Rivas
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

#ifndef __ZNG_SORT_SET_H__
#define __ZNG_SORT_SET_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

typedef struct __zng_ss_node {
  int value;
  int left_depth;
  int right_depth;
  struct __zng_ss_node* left;
  struct __zng_ss_node* right;
} sort_set_node;

typedef struct __zng_ss {
  size_t size;
  sort_set_node* root;
} sort_set;

extern sort_set* new_sort_set(int value);

extern void add_to_sort_set(sort_set*const set, int value);

// Time: O(log(n))
// Space: O(1)
extern bool exist_in_sort_set(const sort_set*const set, int target);

extern void delete_sort_set(sort_set* list);

extern bool is_empty_sort_set(const sort_set*const set);

#endif // __ZNG_SORT_SET_H__
