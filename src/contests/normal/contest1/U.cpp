#include <iostream>

int main() {
  int amount, modulus;
  std::cin >> amount >> modulus;

  for (int i = 0; i <= amount; i++) {
    for (int j = 0; j <= amount; j++) {
      if (i == 0 && j == 0) {
        std::cout << "\t";
        continue;
      }

      if (i == 0 && j != 0) {
        if (j == amount) {
          std::cout << j << "\n";
        } else {
          std::cout << j << "\t";
        }

        continue;
      }

      if (i != 0 && j == 0) {
        std::cout << i << "\t";
        continue;
      }

      if (j == amount) {
        std::cout << (i * j) % modulus << "\n";
      } else {
        std::cout << (i * j) % modulus << "\t";
      }
    }
  }
}