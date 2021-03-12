#include "Equation.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Hello World!" << endl;

  Equation eq(3);
  eq.input();
  eq.print_equation();
  cout << endl;
  cout << endl;
  cout << endl;
  auto ans = eq.find_roots();
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
