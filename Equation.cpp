#include "Equation.h"

using vec = std::vector<double>;
void Equation::input() {
  if (this->deg == std::numeric_limits<unsigned>::max()) {
    std::cout << "Degree of the equation?:  ";
    std::cin >> this->deg;
  }
  std::cout << "Enter the coefficient in the order x^0,x^1 ,x^2 and.. (till "
            << this->deg << "): ";
  this->coefficients = vec(this->deg + 1, 0);
  for (auto &x : this->coefficients)
    std::cin >> x;
}

void Equation::print_equation() {
  int power = 0;
  auto &arr = this->coefficients;
  for (auto it = arr.begin(); it != arr.end(); it++) {
    std::cout << *(it) << "x^" << power << (it == (arr.end() - 1) ? "" : " + ");
    power++;
  }
}

void Equation::divide(double divider) {
  this->coefficients = std::move(this->divide_by(divider));
}

vec Equation::divide_by(double divider) {
  vec coeffs(this->coefficients);
  vec solution;
  auto current = coeffs.back();
  coeffs.pop_back();
  auto add = 0.0F;
  while (!coeffs.empty()) {
    solution.push_back(current + divider * add);
    add = solution.back();
    current = coeffs.back();
    coeffs.pop_back();
  }
  this->deg = this->deg - 1;
  std::reverse(solution.begin(), solution.end());
  return solution;
}

double Equation::plug(double val) {
  double sum = 0;
  for (int i = 0; i <= this->deg; i++) {
    sum += (pow(val, i) * this->coefficients[i]);
  }
  return sum;
}

double Equation::derivative(double val) {
  return ((this->plug(val + 0.000000001) - this->plug(val)) / 0.000000001);
}

double Equation::find_root() {
  float x = 1.00;
  double testVal = this->plug(x);
  while (true) {
    if (testVal < 0.000001 && testVal > -0.000001)
      break;
    double der = this->derivative(x);
    double x2 = (testVal / der);
    x -= x2;
    testVal = this->plug(x);
  }

  return (this->plug(round(x)) == 0) ? round(x) : x;
}

std::vector<double> Equation::find_roots() {
  std::vector<double> solution;
  auto temp = *this;
  while (temp.deg != 0) {
    solution.push_back(temp.find_root());
    temp.divide(solution.back());
  }
  return solution;
}
