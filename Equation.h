#ifndef EQUATION_H
#define EQUATION_H
#include <algorithm>
#include <cmath>
#include <concepts>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

// template <typename T>
// concept Number = std::is_integral<T>::value ||
// std::is_floating_point<T>::value;

class Equation {
  using vec = std::vector<double>;

private:
  unsigned deg = std::numeric_limits<unsigned>::max();
  std::vector<double> coefficients;

  void divide(double divider); //{
  // this->coefficients = std::move(divide_by(divider));
  // }

public:
  Equation() = default;
  explicit Equation(unsigned degree)
      : deg(degree), coefficients{vec(degree + 1, 0)} {};
  explicit Equation(unsigned degree, const vec &coeffVector) : deg(degree) {
    coefficients.resize(this->deg + 1);
    if (coeffVector.size() > (degree)) {
      std::copy(coeffVector.begin(), coeffVector.begin() + degree + 1,
                coefficients.begin());
    } else {
      unsigned i = 0;
      for (auto &x : coeffVector)
        coefficients[i++] = x;
    }
  };
  void input();

  void print_equation();

  vec divide_by(double divider);

  double plug(double val);

  double derivative(double val);

  double find_root();

  std::vector<double> find_roots();
};
#endif // EQUATIONTOOLS_H
