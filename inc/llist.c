#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

LinkedList * LinkedList_init_node(int val) {
  LinkedList * node = NULL;
  node = malloc(sizeof(LinkedList));
  node->val = val;
  node->next = NULL;
  return node;
}

void LinkedList_print(LinkedList * head) {
  LinkedList * current = head;

  if (current == NULL) return;
  printf("%d\n", current->val);
  return LinkedList_print(current->next);
}

LinkedList * LinkedList_push(LinkedList * head, int val) {
  LinkedList * current = head;

  if(current->next == NULL) {
    current->next = LinkedList_init_node(val);
  } else {
    LinkedList_push(current->next, val);
  }

  return current;
}

LinkedList * LinkedList_pop(LinkedList * head) {
  LinkedList * item;

  if(head->next == NULL) {
    item = LinkedList_init_node(head->val);
    free(head);
    return item;
  }

  if(head->next->next == NULL) {
    item = LinkedList_init_node(head->next->val);
    free(head->next);
    head->next = NULL;
    return item;
  }

  return LinkedList_pop(head->next);
}

LinkedList * LinkedList_shift(LinkedList ** head, int val) {
  LinkedList * new_head = LinkedList_init_node(val);
  new_head->next = *head;
  *head = new_head;
  return *head;
}

LinkedList * LinkedList_unshift(LinkedList ** head) {
  LinkedList * current = * head;
  LinkedList * next_node = current->next;

  free(*head);
  *head = next_node;

  return current;
}
