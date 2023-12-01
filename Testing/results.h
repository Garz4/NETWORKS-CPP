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

#ifndef RESULTS_H_
#define RESULTS_H_

#include "../DataStructures/src/memory.h"
#include "../Terminal/outputstream.h"

#ifdef __cplusplus

#include <string>

static std::string __CURRENT_TEST_;
static const char* __CURRENT_TEST() { return __CURRENT_TEST_.c_str(); }

# define START_TEST(string) \
  __CURRENT_TEST_ = (string);

#else

static char* __CURRENT_TEST_;
static const char* __CURRENT_TEST() { return __CURRENT_TEST_; }

# define START_TEST(string) \
  DEALLOCATE(__CURRENT_TEST_); \
  __CURRENT_TEST_ = (string);

#endif // __cplusplus

#define FINISH_TEST() \
  STDOUT_GREEN("[%s]: Passed.\n", __CURRENT_TEST());

#define FINISH_TEST_FAILED() \
  STDERR_RED("[%s]: Failed.\n", __CURRENT_TEST()); \
  EXIT(1);

#define FAIL(string) \
  STDERR_RED("[%s]: %s\n", __CURRENT_TEST(), (string)); \
  FINISH_TEST_FAILED()

#endif // RESULTS_H_
