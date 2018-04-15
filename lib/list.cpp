#include <iostream>
#include "list.h"


// List node
//
struct list_node {
  int *slice;
  list_node *next;
};


// List constructor
//
list::list() {
  head = NULL;
  tail = NULL;
  this->length = 0;
}


// Push element to the list
//   slice - an array allocated
//           with new int[]
//
void list::push(int *slice) {
  list_node* temp = new list_node;
  temp->slice = slice;
  temp->next = NULL;

  if (!head) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = tail->next;
  }

  this->length++;
}


// Delete last element from the list
//
void list::pop() {
  if (!head) return;

  list_node *temp = head;

  while (temp->next->next != tail) temp = temp->next;

  delete temp->next->slice;
  delete temp->next;

  tail = temp;
  tail->next = NULL;

  this->length--;
}


// Clear list
//
void list::clear() {
  list_node *temp;
  temp = head;

  while (head) {
    temp = head;
    head = head->next;
    delete temp->slice;
    delete temp;
  }

  this->length = 0;
}


// Get slice by its number in list
//   slice_number - number of slice
//                  in the list
//
int *list::get(int slice_number) const {
  list_node *temp = head;

  for (int i = 0; i < slice_number; ++i) {
    temp = temp->next;
  }

  return temp->slice;
}
