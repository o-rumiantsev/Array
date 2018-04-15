#include "list.h"
#include <iostream>
#include <string>
#include <cmath>

#ifndef array_h
#define array_h

class Array {
private:
  list Map;
  int range;
  void set(int, int);
  int get(int) const;
public:
  Array(int);
  int length;

  void push(int);
  int pop();
  Array map(int (*)(int));
  Array filter(bool (*)(int));
  std::string join(const char*) const;
  std::string to_string() const;

  friend std::ostream &operator<<(std::ostream &, const Array&);


  struct Proxy {
    Array& a;
    int index;
    Proxy(Array &a, int index) : a(a), index(index) {}

    operator int() { return a.get(index); }
    void operator=(int other) { a.set(index, other); }
  };

  Proxy operator[](int index) {
    return Proxy(*this, index);
  }
};

#endif
