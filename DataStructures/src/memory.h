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

#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdio.h>
#include <stdlib.h>

#include "../../Terminal/outputstream.h"

#define ALLOCATE(type, pointer) \
  pointer = (type *) malloc(sizeof(type)); \
  if (pointer == NULL) { \
    STDERR_RED("ERROR: Out of memory.\n"); \
    EXIT(1); \
  }

#define DELETE(pointer) free(pointer);

#endif // MEMORY_H_
