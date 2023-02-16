#include <iostream>

int main() {
  int amount;
  std::cin >> amount;

  for (int i = 0; i <= amount; i++) {
    for (int j = 0; j <= amount; j++) {
      if (i == 0 && j == 0) {
        std::cout << "\t";
        continue;
      }

      if (j == amount) {
        std::cout << i + j << "\n";
      } else {
        std::cout << i + j << "\t";
      }
    }
  }
}