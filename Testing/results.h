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

#ifndef __ZNG_RESULTS_H__
#define __ZNG_RESULTS_H__

#include "../Terminal/outputstream.h"

#ifdef __cplusplus

#include <string>

static std::string __CURRENT_TEST_;
static const char* __CURRENT_TEST() { return __CURRENT_TEST_.c_str(); }

#else

static char* __CURRENT_TEST_;
static const char* __CURRENT_TEST() { return __CURRENT_TEST_; }

#endif // __cplusplus

# define START_TEST(str)   \
do {                       \
  __CURRENT_TEST_ = (str); \
} while (0)

#define FINISH_TEST()                                \
do {                                                 \
  STDOUT_GREEN("[%s]: Passed.\n", __CURRENT_TEST()); \
} while (0)

#define FINISH_TEST_FAILED()                       \
do {                                               \
  STDERR_RED("[%s]: Failed.\n", __CURRENT_TEST()); \
} while (0)

#define FAIL(string)                                    \
do {                                                    \
  STDERR_RED("[%s]: %s\n", __CURRENT_TEST(), (string)); \
  FINISH_TEST_FAILED();                                 \
} while (0)

#endif // __ZNG_RESULTS_H__
