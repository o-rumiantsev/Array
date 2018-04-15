#include <iostream>
#include "../lib/array.h"

using namespace std;

int main() {
  Array a (10);

  for (int i = 0; i < 1000; ++i) a[i] = i;

  cout << a << endl;
}
