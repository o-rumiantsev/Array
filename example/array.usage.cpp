#include <iostream>
#include "../lib/array.h"

using namespace std;

int main() {
  Array a (10);

  a.set(0, 1);
  a.set(1, 2);
  a.set(2, 3);
  a.set(3, 4);
  a.set(4, 5);
  a.set(9, 10);
  a.set(10, 11);

  a.push(12);
  cout << a.join(", ") << endl;

  Array b = a.map([](int item) { return item * 2; });

  cout << a.join(", ") << endl;
  cout << b.join(", ") << endl;

  cout << a << endl;
}
