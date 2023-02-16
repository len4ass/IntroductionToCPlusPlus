#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;

  double sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      sum += static_cast<double>(1) / i;
    } else {
      sum -= static_cast<double>(1) / i;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}