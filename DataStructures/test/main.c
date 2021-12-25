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

#include "../src/hash_map.h"
#include "../src/hash_set.h"
#include "../src/linked_list.h"
#include "../src/sort_map.h"
#include "../src/sort_set.h"

int main(int argc, char** argv) {
  size_t len = 5;
  linked_list* list = new_linked_list(0);
  for (int i = 1; i < len; ++i) {
    add_to_linked_list(list, i);
  }
  print_linked_list(list);
  printf("Su size es: %ld\n", list->size);
  if (exist_in_linked_list(list, 3)) {
    printf("3 existe en la lista.\n");
  }
  if (!exist_in_linked_list(list, 8)) {
    printf("8 no existe en la lista.\n");
  }
  delete_linked_list(list);
  return 0;
}
