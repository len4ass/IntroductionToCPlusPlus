#include <iostream>
#include <map>
#include <vector>

int main() {
  int32_t n, k, current_number;
  std::cin >> n >> k;
  std::vector<int32_t> numbers(n);
  std::map<int32_t, int32_t> m;

  for (int32_t i = 0; i < n; ++i) {
    std::cin >> current_number;
    numbers[i] = current_number;
  }

  for (int32_t i = 0; i < n; ++i) {
    if (i < k - 1) {
      ++m[numbers[i]];
      continue;
    }

    ++m[numbers[i]];
    if (i != k - 1) {
      --m[numbers[i - k]];

      if (m[numbers[i - k]] == 0) {
        m.erase(numbers[i - k]);
      }
    }

    std::cout << (*m.begin()).first << std::endl;
  }
}