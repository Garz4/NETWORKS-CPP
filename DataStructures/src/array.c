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

#include "../inc/array.h"
#include "../inc/memory.h"

inline array* allocate_array(int value) {
  array* response;

  ALLOCATE(array, response);
  ALLOCATE(int, response->data);
  response->size = 1;
  *(response->data) = value;

  return response;
}

inline array* allocate_empty_array() {
  array* response;

  ALLOCATE(array, response);
  response->size = 0;
  response->data = NULL;

  return response;
}

inline void deallocate_array(array* arr) {
  if (arr == NULL) {
    return;
  }

  if (arr->data != NULL) {
    DEALLOCATE(arr->data);
  }

  DEALLOCATE(arr);
}

bool exist_in_array(const array*const arr, int target) {
  if (is_empty_array(arr)) {
    return false;
  }

  for (size_t i = 0; i < arr->size; ++i) {
    if (arr->data[i] == target) {
      return true;
    }
  }

  return false;
}

inline bool is_empty_array(const array*const arr) {
  return arr == NULL || (arr->data == NULL && arr->size == 0);
}
