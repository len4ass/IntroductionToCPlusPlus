#include <iostream>

int main() {
  int amount;
  std::cin >> amount;

  long long sum = 0;
  long long max = -1e9;
  long long min = 1e9;
  for (int i = 0; i < amount; i++) {
    long long num;
    std::cin >> num;

    sum += num;
    if (num > max) {
      max = num;
    }

    if (num < min) {
      min = num;
    }
  }

  std::cout << sum << " " << min << " " << max << std::endl;
}