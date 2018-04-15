#include "array.h"

// Array constructor
//   size - size of one slice
//          of array
//
Array::Array(int size) {
  int *init_slice = new int[size];
  this->range = size;
  this->Map.push(init_slice);
  this->length = 0;
}


// Set value for element with known index
// (This will be replaced with operator[])
//   index - an abstract index of element
//           in array
//   value - value to be set for this element
//
void Array::set(int index, int value) {
  if (index + 1 > this->length) this->length = index + 1;

  int slice_number = floor(index / range);
  int index_in_slice = index - slice_number * range;

  if (index + 1 > this->Map.length * range) {
    int *new_slice = new int[range];
    new_slice[index_in_slice] = value;
    this->Map.push(new_slice);
  } else {
    int *slice = Map.get(slice_number);
    slice[index_in_slice] = value;
  }
}


// Get an element value by its index
//   index - an abstract index of element
//           in array
//
int Array::get(int index) const {
  int slice_number = floor(index / range);
  int index_in_slice = index - slice_number;

  if (index + 1 > this->length) {
    std::cout << "Index is out of bounds" << std::endl;
    exit(1);
  }

  int *slice = Map.get(slice_number);
  return slice[index_in_slice];
}


// Push element to array
//   value - value to be placed
//           in the end of array
//
void Array::push(int value) {
  int index = this->length;
  this->set(index, value);
}


// Get last element and delete
// it from array
//
int Array::pop() {
  int poped = this->get(this->length - 1);
  this->length--;

  if (this->Map.length * range - 1 == this->length) Map.pop();

  return poped;
}


// Project array into new one
// through the function
//   fn - function to be applied
//        to each element
//
Array Array::map(int (*fn)(int)) {
  Array mapped (this->length);

  for (int i = 0; i < this->length; ++i) {
    int item = this->get(i);
    int value = fn(item);
    mapped.push(value);
  }

  return mapped;
}


// Project array into new one
// filtering by the function
//   fn - function which returns
//        true or false
//
Array Array::filter(bool (*fn)(int)) {
  Array filtered (this->length);

  for (int i = 0; i < this->length; ++i) {
    int item = this->get(i);
    int value = fn(item);
    if (value) filtered.push(item);
  }

  return filtered;
}

// Create string from elements of array
// separated by specified separator
//
std::string Array::join(const char *separator) const {
  std::string str;

  if (!this->length) return str;

  int i;
  for (i = 0; i < this->length - 1; ++i) {
    int item = this->get(i);
    std::string sep (separator);
    str += std::to_string(item) + sep;
  }

  str += std::to_string(this->get(i));
  return str;
}


// Represent array as a string
//
std::string Array::to_string() const {
  std::string str ("[");

  if (!this->length) {
    str += "]";
    return str;
  }

  str += this->join(", ") + "]";
  return str;
}


// Operator for cout
//
std::ostream &operator<<(std::ostream &os, Array const &arr) {
  os << arr.to_string();
  return os;
}
