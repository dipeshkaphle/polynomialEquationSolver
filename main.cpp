#include "Equation.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Hello World!" << endl;

  Equation eq(2);
  eq.input();
  eq.print_equation();
  cout << endl;
  eq.print_equation();
  cout << endl;
  cout << endl;
  cout << endl;
  auto ans = eq.find_roots();
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
  // Equation eq2
  // eq2.input();
  // eq2.print_equation();
  // get_equation(eq);
  // std::vector<double> sol=find_roots(eq);
  // for(int i=0;i<sol.size();i++)
  //   {
  //     std::cout<<sol[i]<<std::endl;
  //   }
  return 0;
}
