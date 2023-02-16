#include <iostream>

int main() {
  int up_left, down_left;
  int up_right, down_right;
  std::cin >> up_left >> down_left >> up_right >> down_right;

  for (int i = up_left; i <= down_left; i++) {
    for (int j = up_right; j <= down_right; j++) {
      std::cout << i << " x " << j << " = " << i * j << "\n";


      if (j == down_right) {
        std::cout << "\n";
      }
    }
  }
}