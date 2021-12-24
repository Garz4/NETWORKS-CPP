#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

typedef struct ll_node linked_list_node;
struct ll_node {
  int val;
  linked_list_node* next;
};

typedef struct ll linked_list;
struct ll {
  size_t size;
  linked_list_node* head;
  linked_list_node* tail;
};

extern
linked_list*
new_linked_list(int val) {
  linked_list* response;
  ALLOCATE(response, linked_list);
  ALLOCATE(response->head, linked_list_node);
  response->size = 1;
  response->tail = response->head;
  return response;
}

extern
void
print_linked_list(const linked_list* list) {
  linked_list_node* head = list->head;
  printf("list = {");
  while (head != NULL) {
    printf("%d", head->val);
    head = head->next;
    if (head != NULL) printf(", ");
  }
  printf("};\n");
}

extern
bool
exist_in_linked_list(const linked_list* list, int val) {
  linked_list_node* head = list->head;
  while (head != NULL) {
    if (head->val == val) {
      return true;
    }
    head = head->next;
  }
  return false;
}

extern
void
add_head_linked_list(linked_list* list) {
  if (list == NULL) return;
  linked_list_node* head;
  ALLOCATE(head, linked_list_node);
  head->next = list->head;
  list->head = head;
  list->size++;
}

extern
void
add_tail_linked_list(linked_list* list, int val) {
  if (list == NULL) return;
  ALLOCATE(list->tail->next, linked_list_node);
  list->tail = list->tail->next;
  list->tail->val = val;
  list->size++;
}

extern
void
add_to_linked_list(linked_list* list, int val) {
  if (list == NULL) return;
  add_tail_linked_list(list, val);
}

extern
void
delete_linked_list_nodes(linked_list_node* node) {
  if (node == NULL) return;
  delete_linked_list_nodes(node->next);
  DELETE(node);
}

extern
void
delete_linked_list(linked_list* list) {
  if (list == NULL) return;
  delete_linked_list_nodes(list->head);
  DELETE(list);
}

#endif // LINKED_LIST_H_
