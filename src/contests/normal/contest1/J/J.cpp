#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  double a, b;
  std::cin >> a >> b;

  double sqr = a * a + b * b;
  double hyp = std::sqrt(sqr);

  std::cout << std::setprecision(6) << std::fixed << hyp << std::endl;
  return 0;
}

