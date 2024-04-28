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

#include <stddef.h>

typedef struct __zng_array {
  int* data;
  size_t size;
} array;

// Every new array needs to be deleted using delete_array(...).
extern array* new_array(int value);

extern void add_to_array(array*const arr, int value);

extern void delete_array(array* arr);

#endif // __ZNG_ARRAY_H__
