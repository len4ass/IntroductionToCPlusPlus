#include <iostream>
#include <cmath>

int main() {
  int i;
  double a, b;
  std::cin >> i;
  std::cin >> a >> b;

  switch (i) {
  case 0:
    std::cout << a + b << std::endl;
    break;
  case 1:
    std::cout << a - b << std::endl;
    break;
  case 2:
    std::cout << a * b << std::endl;
    break;
  case 3:
    std::cout << a / b << std::endl;
    break;
  case 4:
    std::cout << std::pow(a, b) << std::endl;
    break;
  case 5:
    std::cout << std::pow(b, 1 / a) << std::endl;
    break;
  default:
    std::cout << -1 << std::endl;
    break;
  }

  return 0;
}

