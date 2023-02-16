#include <iostream>
#include <cmath>

int main() {
  int n, a;
  std::cin >> n >> a;

  double sum = sqrt(static_cast<double>(n) * static_cast<double>(a));
  for (int i = n - 1; i >= 1; i--) {
    sum = std::sqrt(static_cast<double>(i) * static_cast<double>(a) + sum);
  }

  std::cout << sum << std::endl;
  return 0;
}

