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

#ifndef __ZNG_COMPARATORS_H__
#define __ZNG_COMPARATORS_H__

#include "../Terminal/outputstream.h"
#include "results.h"

#define EXPECT_EQUAL(lhs, rhs)  \
do {                            \
  if ((lhs) != (rhs)) {         \
    FAIL("Arguments '"          \
         #lhs                   \
         "' and '"              \
         #rhs                   \
         "' should be equal."); \
  }                             \
} while (0)

#define EXPECT_TRUE(expression)                               \
do {                                                          \
  if (!(expression)) {                                        \
    FAIL("The following boolean expression should be true: '" \
         #expression                                          \
         "'.");                                               \
  }                                                           \
} while (0)

#define EXPECT_FALSE(expression)                               \
do {                                                           \
  if ((expression)) {                                          \
    FAIL("The following boolean expression should be false: '" \
         #expression                                           \
         "'.");                                                \
  }                                                            \
} while (0)

#endif // __ZNG_COMPARATORS_H__
