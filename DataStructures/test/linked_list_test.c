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
#include "../src/linked_list.h"

int main(int argc, char** argv) {
  START_TEST("linked_list_test");

  const size_t len = 5;
  const int first_element = 0, last_element = 4;
  linked_list* list = new_linked_list(first_element);

  for (int i = first_element + 1; i <= last_element; ++i) {
    add_to_linked_list(list, i);
  }

  EXPECT_TRUE(exist_in_linked_list(list, 3));
  EXPECT_FALSE(exist_in_linked_list(list, 8));
  EXPECT_EQUAL(list->size, len);

  // TODO(Garz4): Create another list and actually verify it was fully reversed.
  reverse_linked_list(list);

  EXPECT_EQUAL(list->head->val, last_element);
  EXPECT_EQUAL(list->tail->val, first_element);

  delete_linked_list(list);

  FINISH_TEST();

  return 0;
}
