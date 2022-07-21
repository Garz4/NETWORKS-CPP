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

extern
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

extern
void
add_to_sort_set(sort_set* set, int val) {}

#endif // SORT_SET_H_
