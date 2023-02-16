#include <iostream>

int main() {
  int32_t n, k;
  std::cin >> n >> k;

  if (n == 1 && k == 1) {
    std::cout << "YES" << std::endl;
    return 0;
  } else {
    if ((n != 1 && k == 1) || (n == 1 && k != 1)) {
      std::cout << "NO" << std::endl;
      return 0;
    } else {
      std::cout << "YES" << std::endl;
      return 0;
    }
  }

  return 0;
}