#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  std::cin >> d;

  if (a + 2 == c && b + 1 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a - 2 == c && b + 1 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a + 2 == c && b - 1 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a - 2 == c && b - 1 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a + 1 == c && b + 2 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a - 1 == c && b + 2 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a + 1 == c && b - 2 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  if (a - 1 == c && b - 2 == d) {
    std::cout << "YES" << std::endl;
    return 0;
  }

  std::cout << "NO" << std::endl;
  return 0;
}

