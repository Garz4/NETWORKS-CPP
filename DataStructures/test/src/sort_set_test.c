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

#include <stdio.h>

#include "../../../Testing/comparators.h"
#include "../../inc/sort_set.h"

int main(void) {
  START_TEST("sort_set_test");

  const size_t len = 15;
  const int last_element = len - 1;
  const int first_element = 0;
  sort_set* set = allocate_sort_set(1);

  for (int i = first_element + 1; i <= last_element; ++i) {
    //add_to_sort_set(set, i);
  }

  deallocate_sort_set(set);

  FINISH_TEST();

  return 0;
}
