#include <iostream>
#include "../lib/array.h"

using namespace std;

int main() {
  Array a (10);

  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);

  Array b = a.map([](int item) { return item * 3; });
  Array c = a.filter([](int item) { return item % 2 == 0; });

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
}
