/*
 * MIT License
 *
 * Copyright (c) 2021 Uriel Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * https://github.com/Garz4/zoning/blob/master/LICENSE
 */

#ifndef SORT_SET_H_
#define SORT_SET_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

typedef struct ss_node sort_set_node;
struct ss_node {
  int val;
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

extern
sort_set*
new_sort_set(int val) {
  sort_set* response;
  ALLOCATE(response, sort_set);
  ALLOCATE(response->root, sort_set_node);
  response->size = 1;
  response->root->val = val;
  return response;
}

extern
void
add_to_sort_set(sort_set* set, int val) {}

extern
bool
exist_in_sort_set_nodes(const sort_set_node* node, int val) {
  if (node == NULL) {
    return false;
  }

  if (node->val == val) {
    return true;
  } else if (node->val > val) {
    return exist_in_sort_set_nodes(node->left, val);
  }

  return exist_in_sort_set_nodes(node->right, val);
}

extern
bool
exist_in_sort_set(const sort_set* set, int val) {
  return exist_in_sort_set_nodes(set->root, val);
}

extern
void
delete_sort_set(sort_set* set) {
    DELETE(set->root);
    DELETE(set);
}

#endif // SORT_SET_H_
