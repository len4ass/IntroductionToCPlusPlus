#include <iostream>

int main() {
  int32_t v;
  int32_t count = 0;

  while (std::cin >> v) {
    if (v == 0) {
      break;
    }

    if (v % 2 == 0) {
      ++count;
    }
  }

  std::cout << count << std::endl;
  return 0;
}