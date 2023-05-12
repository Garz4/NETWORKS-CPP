/*
 * MIT License
 *
 * Copyright (c) 2022 Uriel Rivas
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

typedef struct ss_node sort_set_node;
struct ss_node {
  int value;
  int left_depth;
  int right_depth;
  sort_set_node* left;
  sort_set_node* right;
};

typedef struct ss sort_set;
struct ss {
  size_t size;
  sort_set_node* root;
};

inline
sort_set*
new_sort_set(int value) {
  sort_set* response;

  ALLOCATE(sort_set, response);
  ALLOCATE(sort_set_node, response->root);
  response->size = 1;
  response->root->value = value;
  response->root->left_depth = 0;
  response->root->right_depth = 0;
  response->root->left = NULL;
  response->root->right = NULL;

  return response;
}

inline
void
add_to_sort_set(sort_set* set, int value) {}

// Time: O(log(n))
// Space: O(1)
bool
exist_in_sort_set(const sort_set* set, int target) {
  if (set == NULL || set->size == 0) {
    return false;
  }

  sort_set_node* node = set->root;

  while (node != NULL) {
    if (node->value == target) {
      return true;
    } else if (node->value < target) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  return false;
}

#endif // __ZNG_SORT_SET_H__
