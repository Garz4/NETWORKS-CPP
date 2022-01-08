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

#include <stdio.h>

#include "../../Testing/comparators.h"
#include "../src/sort_set.h"

int main(void) {
  START_TEST("sort_set_test");

  const size_t len = 5;
  const int first_element = 0, last_element = 4;
  sort_set* set = new_sort_set(first_element);

  for (int i = first_element + 1; i <= last_element; ++i) {
    add_to_sort_set(set, i);
  }

  EXPECT_EQUAL(set->size, 1);
  EXPECT_TRUE(exist_in_sort_set(set, 0));
  EXPECT_FALSE(exist_in_sort_set(set, 6782));

  delete_sort_set(set);

  FINISH_TEST();

  return 0;
}
