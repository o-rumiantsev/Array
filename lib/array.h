#include "list.h"
#include <iostream>
#include <string>
#include <cmath>

#ifndef array_h
#define array_h


template<typename T>
class Array;

template<typename T>
std::ostream &operator<<(std::ostream &, const Array<T> &);


template <typename T>
class Array {
private:
  list<T> Map;
  int range;


  // Set value for element with known index
  // (This will be replaced with operator[])
  //   index - an abstract index of element
  //           in array
  //   value - value to be set for this element
  //
  void set(int index, T value) {
    if (index + 1 > length) length = index + 1;

    int slice_number = floor(index / range);
    int index_in_slice = index - slice_number * range;

    if (index + 1 > Map.length * range) {
      T *new_slice = new T[range];
      new_slice[index_in_slice] = value;
      Map.push(new_slice);
    } else {
      T *slice = Map.get(slice_number);
      slice[index_in_slice] = value;
    }
  };


  // Get an element value by its index
  //   index - an abstract index of element
  //           in array
  //
  T get(int index) const {
    int slice_number = floor(index / range);
    int index_in_slice = index - slice_number * range;

    if (index + 1 > length) {
      std::cout << "Index is out of bounds" << std::endl;
      exit(1);
    }

    T *slice = Map.get(slice_number);
    return slice[index_in_slice];
  };

  
public:
  int length;

  // Array constructor
  //   size - size of one slice
  //          of array
  //
  Array(int size) {
    T *init_slice = new T[size];
    range = size;
    Map.push(init_slice);
    length = 0;
  };


  // Push element to array
  //   value - value to be placed
  //           in the end of array
  //
  void push(T value) {
    int index = length;
    set(index, value);
  };


  // Get last element and delete
  // it from array
  //
  T pop() {
    T popped = get(length - 1);
    length--;

    if (Map.length * range - 1 == length) Map.pop();

    return popped;
  };


  // Project array into new one
  // through the function
  //   fn - function to be applied
  //        to each element
  //
  Array<T> map(T (*fn)(T)) {
    Array<T> mapped (length);

    for (int i = 0; i < length; ++i) {
      T item = get(i);
      T value = fn(item);
      mapped.push(value);
    }

    return mapped;
  };


  // Project array into new one
  // filtering by the function
  //   fn - function which returns
  //        true or false
  //
  Array<T> filter(bool (*fn)(T)) {
    Array<T> filtered (length);

    for (int i = 0; i < length; ++i) {
      T item = get(i);
      T value = fn(item);
      if (value) filtered.push(item);
    }

    return filtered;
  };


  // Create string from elements of array
  // separated by specified separator
  //
  std::string join(const char *separator) const {
    std::string str;

    if (!length) return str;

    int i;
    for (i = 0; i < length - 1; ++i) {
      T item = get(i);
      std::string sep (separator);
      str += std::to_string(item) + sep;
    }

    str += std::to_string(get(i));
    return str;
  };


  // Represent array as a string
  //
  std::string to_string() const {
    std::string str ("[");

    if (!length) {
      str += "]";
      return str;
    }

    str += join(", ") + "]";
    return str;
  };


  struct Proxy {
    Array<T> &arr;
    int index;
    Proxy(Array &arr, int index) : arr(arr), index(index) {}

    operator T() { return arr.get(index); }
    void operator=(T value) { arr.set(index, value); }
  };

  Proxy operator[](int index) {
    return Proxy(*this, index);
  }

  friend std::ostream &operator<< <T> (std::ostream &, const Array<T> &);
};


// Operator for cout
//
template<typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &arr) {
  os << arr.to_string();
  return os;
}


#endif
