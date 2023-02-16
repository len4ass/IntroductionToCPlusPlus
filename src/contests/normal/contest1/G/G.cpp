#include <iostream>

int main() {
  int a;
  std::cin >> a;

  int sum = a % 10;
  a /= 10;
  sum += a % 10;
  a /= 10;
  sum += a % 10;

  std::cout << sum << std::endl;
  return 0;
}

