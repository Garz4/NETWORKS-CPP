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

#ifndef __ZNG_ARRAY_H__
#define __ZNG_ARRAY_H__

#include <stdbool.h>
#include <stddef.h>

typedef struct __zng_array {
  int* data;
  size_t size;
} array;

// Every new array needs to be deleted using deallocate_array(...).
extern array* allocate_array(int value);
extern array* allocate_empty_array();
extern void deallocate_array(array* arr);
// TODO:
extern void deallocate_elements_in_array(array* arr);

extern bool is_empty_array(const array*const arr);

extern void add_to_array(array*const arr, int value);
extern void add_to_empty_array(array*const arr, int value);

extern bool exist_in_array(const array*const arr, int target);

extern void delete_last_array(array* arr);

#endif // __ZNG_ARRAY_H__
