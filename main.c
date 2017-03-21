#include <stdio.h>
#include <stdlib.h>
#include "inc/llist.h"

void test_shift_unshift();
void test_push_pop();
void test_push_pop_one_elt();

int main() {
  test_push_pop();
  test_shift_unshift();
  test_push_pop_one_elt();

  return 0;
}

void test_push_pop_one_elt() {
  printf("!!!TESTING PUSH AND POP WITH ONE ELT!!!\n");
  LinkedList * test_list = LinkedList_init_node(7);
  LinkedList_print(test_list);
  LinkedList * node = LinkedList_pop(test_list);
  printf("after:\n");
  LinkedList_print(test_list);
  printf("[%d]\n", node->val);
}

void test_push_pop() {
  LinkedList * test_list = LinkedList_init_node(0);
  printf("!!!TESTING PUSH AND POP!!!\n");
  for(int i = 1; i < 4; i++) {
    LinkedList_push(test_list, i);
  }
  LinkedList_print(test_list);
  printf("after:\n");
  LinkedList * node = LinkedList_pop(test_list);
  LinkedList * node2 = LinkedList_pop(test_list);
  LinkedList * node3 = LinkedList_pop(test_list);
  LinkedList * node4 = LinkedList_pop(test_list);
  LinkedList_print(test_list);
  printf("[%d]\n", node->val);
  printf("[%d]\n", node2->val);
  printf("[%d]\n", node3->val);
  printf("[%d]\n", node4->val);
}

void test_shift_unshift() {
  LinkedList * test_list = LinkedList_init_node(0);
  printf("!!!TESTING SHIFT AND UNSHIFT!!!\n");
  for(int i = 1; i < 4; i++) {
    LinkedList_unshift(&test_list, i);
  }
  LinkedList_print(test_list);

  printf("after:\n");
  LinkedList * node = LinkedList_shift(&test_list);
  printf("[%d]\n", node->val);
  LinkedList * node2 = LinkedList_shift(&test_list);
  printf("[%d]\n", node2->val);
  LinkedList * node3 = LinkedList_shift(&test_list);
  printf("[%d]\n", node3->val);
  LinkedList * node4 = LinkedList_shift(&test_list);
  printf("[%d]\n", node4->val);
  LinkedList_print(test_list);
}
