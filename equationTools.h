#ifndef EQUATIONTOOLS_H
#define EQUATIONTOOLS_H
#include<iostream>
#include<cmath>
#include<vector>




template<class T>
struct equation{
  int deg;
  std::vector<T> coeff;
};

template<class T>
void get_equation(equation<T> &eq)
{
  std::cout<<"Degree??\n";
  std::cin>>eq.deg;
  T c;
  for(int i=0;i<=eq.deg;i++)
    {
      std::cout<<"Input the coefficient of "<< i<<" power\n";
      std::cin>>c;
      eq.coeff.push_back(c);
    }


}


template <class T>
void divide(equation<T> &a,double divider)
{
  std::vector<double> copy=a.coeff;
  std::vector<double> solution;
  int current;
  current=copy.back();
  copy.pop_back();
  int add=0;

  while(!copy.empty()){

        solution.push_back(current+divider*add);
        add=solution.back();
        current=copy.back();
        copy.pop_back();

    }
  a.deg=a.deg-1;
  a.coeff.clear();
  while(!solution.empty())
    {
      a.coeff.push_back(solution.back());
      solution.pop_back();
    }


}


template <class T>
void print_equation(equation<T> &eq)
{
  std::cout<<"The equation is: \n";
  std::cout<<eq.coeff[0]+"+ ";
  for(int i=1;i<=eq.deg;i++)
    {
      std::cout<<eq.coeff[i]<<"x^"<<i<<" + ";
    }
  std::cout<<std::endl;

}


template<class T>
double plug(const equation<T> &eq,double val)
{
  double sum=0;
  for(int i=0;i<=eq.deg;i++)
    {
      sum+=(pow(val,i)*eq.coeff[i]);
    }
  return sum;
}



template<class T>
double derivative(const equation<T> &eq,double val)
{
 return  ((plug( eq ,val+0.000000001)-plug(eq,val))/0.000000001);
}



template<class T>
std::vector<double> find_roots(const equation<T>&eq)
{
  std::vector<double> solution;
  equation<T> temp=eq;
  while(temp.deg!=0)
    {
      solution.push_back(find_root(temp));
      divide(temp,solution[solution.size()-1]);
    }
  return solution;

}


template<class T>
double find_root(equation<T> &eq)
{
  float x=1.00;
  double testVal=plug(eq,x);
  while(true)
    {
      if(testVal<0.000001 && testVal>-0.000001)
        break;
      double der=derivative(eq,x);
      double x2=(testVal/der);
      x-=x2;
      testVal=plug(eq,x);
    }

  return (plug(eq,round(x))==0)?round(x):x;
}


#endif // EQUATIONTOOLS_H
