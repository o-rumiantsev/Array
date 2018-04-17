#include <iostream>
#ifndef list_h
#define list_h


template<typename T>
struct node {
  T *slice;
  node<T> *next;
};

template<typename T>
class list {
private:
  node<T> *head, *tail;
public:


  int length;

  // List constructor
  //
  list() {
    head = NULL;
    tail = NULL;
    length = 0;
  };


  // Push element to the list
  //   slice - an array allocated
  //           with new T[]
  //
  void push(T *slice) {
    node<T> *temp = new node<T>;
    temp->slice = slice;
    temp->next = NULL;

    if (!head) {
      head = temp;
      tail = temp;
    } else {
      tail->next = temp;
      tail = tail->next;
    }

    length++;
  };


  // Delete last element from the list
  //
  void pop() {
    if (!head) return;

    node<T> *temp = head;

    while (temp->next->next != tail) temp = temp->next;

    delete temp->next->slice;
    delete temp->next;

    tail = temp;
    tail->next = NULL;

    length--;
  };


  // Clear list
  //
  void clear() {
    node<T> *temp = new node<T>;
    temp = head;

    while (head) {
      temp = head;
      head = head->next;
      delete temp->slice;
      delete temp;
    }

    length = 0;
  };


  // Get slice by its number in list
  //   slice_number - number of slice
  //                  in the list
  //
  T *get(int slice_number) const {
    node<T> *temp = head;

    for (int i = 0; i < slice_number; ++i) {
      temp = temp->next;
    }

    return temp->slice;
  };
};

#endif
