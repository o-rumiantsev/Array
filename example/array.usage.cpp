#include <iostream>
#include "../lib/array.h"

using namespace std;

int main() {
  Array<int> a (10);

  for (int i = 0; i < 100; ++i) a[i] = i;
  a.push(-1);
  int b = a.pop();

  Array<int> c = a.map([](int item) { return item % 2; });

  cout << a << " " << b << endl;
  cout << c << endl;

  cout << c.filter([](int item) { return item == 1; }).join("") << endl;
}
