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

#include "../inc/linked_list.h"
#include "../inc/memory.h"

inline linked_list* allocate_linked_list(int value) {
  linked_list* response;

  ALLOCATE(linked_list, response);
  ALLOCATE(linked_list_node, response->head);
  response->size = 1;
  response->head->value = value;
  response->head->next = NULL;
  response->tail = response->head;

  return response;
}

inline linked_list* allocate_empty_linked_list() {
  linked_list* response;

  ALLOCATE(linked_list, response);
  response->size = 0;
  response->head = NULL;
  response->tail = NULL;

  return response;
}

void deallocate_linked_list(linked_list* list) {
  if (list == NULL) {
    return;
  }

  linked_list_node* node;
  linked_list_node* next;

  for (node = list->head; node != NULL; node = next) {
    next = node->next;
    DEALLOCATE(node);
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  DEALLOCATE(list);
}

inline bool is_empty_linked_list(const linked_list*const list) {
  return list == NULL
      || (list->head == NULL
       && list->tail == NULL
       && list->size == 0);
}

void print_linked_list(const linked_list*const list) {
  if (is_empty_linked_list(list)) {
    printf("list = {}\n");
    return;
  }

  linked_list_node* head = list->head;
  printf("list = {");

  while (head != NULL) {
    printf("%d", head->value);
    head = head->next;

    if (head != NULL) {
      printf("}->{");
    }
  }

  printf("}\n");
}

bool exist_in_linked_list(const linked_list*const list, int value) {
  if (is_empty_linked_list(list)) {
    return false;
  }

  linked_list_node* head = list->head;

  while (head != NULL) {
    if (head->value == value) {
      return true;
    }

    head = head->next;
  }

  return false;
}

// TODO: Fix edge case when list is not NULL, but its head and tail are.
inline void add_to_linked_list(linked_list*const list, int value) {
  if (list == NULL) {
    return;
  }

  ALLOCATE(linked_list_node, list->tail->next);
  list->tail = list->tail->next;
  list->tail->value = value;
  list->tail->next = NULL;
  list->size++;
}

void delete_single_match_linked_list(linked_list* list, int target) {
  if (is_empty_linked_list(list)) {
    return;
  }
  linked_list_node* node = list->head;

  if (node->value == target) {
    if (list->size == 1) {
      deallocate_linked_list(list);
      return;
    }

    list->head = node->next;
    DEALLOCATE(node);
    list->size--;
    return;
  }

  while (node->next != NULL) {
    if (node->next->value == target) {
      if (node->next == list->tail) {
        list->tail = node;
      }

      linked_list_node* aux;
      aux = node->next;
      node->next = node->next->next;
      DEALLOCATE(aux);
      list->size--;
      return;
    }

    node = node->next;
  }
}

//void erase_all_match_linked_list(linked_list* list, int target) {}

void reverse_linked_list(linked_list*const list) {
  if (is_empty_linked_list(list)) {
    return;
  }

  linked_list_node* current = list->head;
  linked_list_node* previous = NULL;       
  linked_list_node* next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  current = list->head;
  list->head = list->tail;
  list->tail = current;
}

// TODO: Return an empty list when list is not NULL but its contents are.
linked_list* copy_linked_list(const linked_list*const list) {
  if (is_empty_linked_list(list)) {
    return NULL;
  }

  linked_list* copy = allocate_linked_list(list->head->value);
  linked_list_node* node = list->head->next;

  while (node != NULL) {
    add_to_linked_list(copy, node->value);
    node = node->next;
  }

  return copy;
}

bool are_equal_linked_list(
    const linked_list*const lhs, const linked_list*const rhs) {
  if (lhs == NULL && rhs == NULL) {
    return true;
  } else if (lhs == NULL || rhs == NULL || lhs->size != rhs->size) {
    return false;
  }

  linked_list_node* lhs_node = lhs->head;
  linked_list_node* rhs_node = rhs->head;

  while (lhs_node != NULL && rhs_node != NULL) {
    if (lhs_node->value != rhs_node->value) {
      return false;
    }

    lhs_node = lhs_node->next;
    rhs_node = rhs_node->next;
  }

  return lhs_node == NULL && rhs_node == NULL;
}

//void sort_linked_list(linked_list*const list) {}
