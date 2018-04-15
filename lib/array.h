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
public:
  Array(int);
  int length;

  void set(int, int);
  int get(int) const;
  void push(int);
  int pop();
  Array map(int (*)(int));
  std::string join(const char*) const;
  std::string to_string() const;

  friend std::ostream &operator<<(std::ostream &, const Array&);
};

#endif
