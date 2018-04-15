#include <iostream>
#include "list.h"

struct list_node {
  int *slice;
  list_node *next;
};


list::list() {
  head = NULL;
  tail = NULL;
  this->length = 0;
}

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

void list::clear() {
  list_node *temp;
  temp = head;

  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }

  this->length = 0;
}

int *list::get(int slice_number) {
  list_node *temp = head;

  for (int i = 0; i < slice_number; ++i) {
    temp = temp->next;
  }

  return temp->slice;
}
