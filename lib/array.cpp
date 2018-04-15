#include "array.h"

Array::Array(int size) {
  this->range = size;
  this->Map.push(new int[size]);
  this->length = 0;
}

void Array::set(int index, int value) {
  if (index + 1 > this->length) this->length = index + 1;

  int slice_number = floor(index / range);
  int index_in_slice = index - slice_number;

  if (index + 1 > 2 * this->Map.length * range) {
    std::cout << "Index is too large" << std::endl;
    exit(1);
  }

  if (index + 1 > this->Map.length * range) {
    int *new_slice = new int[range];
    new_slice[index_in_slice] = value;
    this->Map.push(new_slice);
  } else {
    int *slice = Map.get(slice_number);
    slice[index_in_slice] = value;
  }
}

int Array::get(int index) {
  int slice_number = floor(index / range);
  int index_in_slice = index - slice_number;

  if (index + 1 > this->length) {
    std::cout << "Index is out of bounds" << std::endl;
    exit(1);
  }

  int *slice = Map.get(slice_number);
  return slice[index_in_slice];
}

void Array::push(int value) {
  int index = this->length;
  this->set(index, value);
}

int Array::pop() {
  int poped = this->get(this->length - 1);
  this->length--;

  if (this->Map.length * range - 1 == this->length) Map.pop();

  return poped;
}

Array Array::map(int (*lambda)(int)) {
  Array mapped (this->length);

  for (int i = 0; i < this->length; ++i) {
    int item = this->get(i);
    int value = lambda(item);
    mapped.push(value);
  }

  return mapped;
}

std::string Array::to_string() {
  std::string str ("[");

  if (!this->length) {
    str += "]";
    return str;
  }

  int i;
  for (i = 0; i < this->length - 1; ++i) {
    int item = this->get(i);
    str += std::to_string(item) + ", ";
  }

  str += std::to_string(this->get(i)) + "]";
  return str;
}
