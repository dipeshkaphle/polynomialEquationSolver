#include <iostream>
#include<equationTools.h>

using namespace std;

int main()
{
  cout << "Hello World!" << endl;

  equation<double> eq;
  get_equation(eq);
  std::vector<double> sol=find_roots(eq);
  for(int i=0;i<sol.size();i++)
    {
      std::cout<<sol[i]<<std::endl;
    }
  return 0;
}
