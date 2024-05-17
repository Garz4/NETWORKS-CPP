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

#ifndef __ZNG_MEMORY_H__
#define __ZNG_MEMORY_H__

#include <stdio.h>
#include <stdlib.h>

#define ALLOCATE(type, pointer)                      \
do {                                                 \
  (pointer) = (type *) malloc(sizeof(type));         \
  if ((pointer) == NULL) {                           \
    fprintf(stderr, "ERROR: Out of memory. "         \
               "Could not allocate memory of type '" \
               #type                                 \
               "' for the variable '"                \
               #pointer                              \
               "' using malloc.\n");                 \
  }                                                  \
} while (0)

#define REALLOCATE(type, pointer, size)                                      \
do {                                                                         \
  type* __zng_temp_ptr = (type *) realloc((pointer), (size) * sizeof(type)); \
  if (__zng_temp_ptr == NULL) {                                              \
    fprintf(stderr, "ERROR: Out of memory. "                                 \
               "Could not allocate memory of type '"                         \
               #type                                                         \
               "' for the variable '"                                        \
               #pointer                                                      \
               "' that required a new size of '"                             \
               "%zu"                                                         \
               "' using malloc.\n", (size));                                 \
  } else {                                                                   \
    pointer = __zng_temp_ptr;                                                \
  }                                                                          \
} while (0)

#define DEALLOCATE(pointer) \
do {                        \
  free((pointer));          \
  (pointer) = NULL;         \
} while (0)

#endif // __ZNG_MEMORY_H__
