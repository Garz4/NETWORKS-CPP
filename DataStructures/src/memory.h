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

#ifndef __ZNG_MEMORY_H__
#define __ZNG_MEMORY_H__

#include <stdlib.h>

#include "../../Terminal/outputstream.h"

#define ALLOCATE(type, pointer) \
  pointer = (type *) malloc(sizeof(type)); \
  if ((pointer) == NULL) { \
    STDERR_RED("ERROR: Out of memory.\n"); \
    EXIT(1); \
  }

#define DEALLOCATE(pointer) \
  free((pointer)); \
  pointer = NULL;

#endif // __ZNG_MEMORY_H__
