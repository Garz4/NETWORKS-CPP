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

#ifndef COMPARATORS_H_
#define COMPARATORS_H_

#include "../Terminal/outputstream.h"
#include "results.h"

#define EXPECT_EQUAL(lhs, rhs) \
  if ((lhs) != (rhs)) { \
    FAIL("Arguments should be equal.") \
  }

#define EXPECT_TRUE(boolean) \
  if (!(boolean)) { \
    FAIL("Argument should be true.") \
  }

#define EXPECT_FALSE(boolean) \
  if ((boolean)) { \
    FAIL("Argument should be false.") \
  }

#endif // COMPARATORS_H_
