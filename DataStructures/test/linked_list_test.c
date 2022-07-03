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

#include "../../Testing/comparators.h"
#include "../src/linked_list.h"

int main(void) {
  START_TEST("linked_list_test");

  // Should not be >= INT_MAX.
  const size_t len = 5;
  const int last_element = len - 1;
  const int first_element = 0;
  linked_list* list = new_linked_list(first_element);

  for (int i = first_element + 1; i <= last_element; ++i) {
    add_to_linked_list(list, i);
  }

  EXPECT_TRUE(exist_in_linked_list(list, first_element + 2));
  EXPECT_FALSE(exist_in_linked_list(list, last_element + 1));
  EXPECT_EQUAL(list->size, len);

  linked_list* list_copy = copy_of_linked_list(list);

  EXPECT_TRUE(equal_linked_list(list, list));
  EXPECT_TRUE(equal_linked_list(list, list_copy));
  reverse_linked_list(list);
  EXPECT_FALSE(equal_linked_list(list, list_copy));
  reverse_linked_list(list_copy);
  EXPECT_TRUE(equal_linked_list(list, list_copy));
  EXPECT_TRUE(equal_linked_list(list_copy, list_copy));

  linked_list_node* node;
  int curr_element = last_element;

  for (node = list->head; node != NULL; node = node->next) {
    EXPECT_EQUAL(node->val, curr_element--);
  }

  EXPECT_EQUAL(first_element, curr_element + 1);
  delete_linked_list(list);
  delete_linked_list(list_copy);
if (list != NULL && list->size == 0) printf("WHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAT");
  FINISH_TEST();

  return 0;
}
