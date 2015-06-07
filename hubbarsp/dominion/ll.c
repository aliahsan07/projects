/*
 *  Name: Spencer Hubbard
 *  Date: 5/21/15
 *  CS 362
 *
 *  TODO: comment
 */

#include <stddef.h>  // for NULL, size_t
#include <stdbool.h> // for bool
#include <stdlib.h>  // for malloc(), free()

#include "CS362.h"
#include "ll.h"

void Enqueue(Node **head, void *data) {
  Node *new_node;

  // allocate new node; crash if out-of-memory
  new_node = (Node *)Malloc(sizeof(Node));

  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    Node *tmp;

    tmp = *head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }

    tmp->next = new_node;
  }
}

void *Dequeue(Node *old_head, Node **new_head) {
  void *data;

  // crash if old_head == NULL
  Verify362(old_head != NULL);

  // record data and set return parameter
  data = old_head->data;
  *new_head = old_head->next;

  // deallocate memory (use defensive programming)
  old_head->data = NULL;
  old_head->next = NULL;
  Free(old_head);

  return data;
}

Node *Push(Node *head, void *data) {
  Node *new_node;

  // allocate new node; crash if out-of-memory
  new_node = (Node *)Malloc(sizeof(Node));

  new_node->data = data;
  new_node->next = head;

  return new_node;
}

void *Pop(Node *old_head, Node **new_head) {
  return Dequeue(old_head, new_head);
}
