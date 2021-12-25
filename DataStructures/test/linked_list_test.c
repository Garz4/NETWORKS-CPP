#include <stdio.h>

#include "../../Testing/comparators.h"
#include "../src/linked_list.h"


int main(int argc, char** argv) {
  size_t len = 5;
  linked_list* list = new_linked_list(0);
  for (int i = 1; i < len; ++i) {
    add_to_linked_list(list, i);
  }
  EXPECT_EQUAL(exist_in_linked_list(list, 3), true);
  EXPECT_EQUAL(exist_in_linked_list(list, 8), false);
  delete_linked_list(list);
  return 0;
}
