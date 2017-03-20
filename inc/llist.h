typedef struct node {
  int val;
  struct node * next;

} LinkedList;

LinkedList * LinkedList_init_node(int);
LinkedList * LinkedList_push(LinkedList *, int);
LinkedList * LinkedList_pop(LinkedList *);
LinkedList * LinkedList_shift(LinkedList **, int);
LinkedList * LinkedList_unshift(LinkedList **);
void LinkedList_print(LinkedList *);
