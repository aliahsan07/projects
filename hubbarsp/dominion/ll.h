/*
 *  Name: Spencer Hubbard
 *  Date: 5/21/15
 *  CS 362
 *
 *  TODO: comment
 */

#ifndef _LL_H_
#define _LL_H_

// linked list node data structure
typedef struct node_st {
  void *data;
  struct node_st *next;
} Node;

// pre : crashes with failed assertion if out-of-memory
// post: allocate and enqueue new node at end of list
void Enqueue(Node **head, void *data);

// pre : crashes with failed assertion if old_head == NULL
// post: deallocates node at head of list and returns data and new list (in return parameter)
void *Dequeue(Node *old_head, Node **new_head);

// pre : crashes with failed assertion if out-of-memory
// post: allocate and push new node at head of list
Node *Push(Node *head, void *data);

// pre : crashes with failed assertion if old_head == NULL
// post: deallocates node at head of list and returns data and new list (in return parameter)
void *Pop(Node *old_head, Node **new_head);

#endif  // _LL_H_

