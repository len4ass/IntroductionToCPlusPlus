#include <iostream>

int main() {
  int a, b;
  std::cin >> a;
  std::cin >> b;

  int res = (a * b) % 109;
  if (res >= 0) {
    std::cout << res << std::endl;
  } else {
    std::cout << 109 + res << std::endl;
  }

  return 0;
}