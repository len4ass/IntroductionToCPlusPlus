#include <iostream>
#include <vector>

void Diff(int64_t& lhs, int64_t& rhs, int64_t& difference) {
  difference = std::abs(std::max(lhs, rhs) - std::min(lhs, rhs));
}

int main() {
  int32_t n, k;
  std::cin >> n >> k;

  int64_t current_value;
  std::vector<int64_t> vector_n(n);
  for (int32_t i = 0; i < n; ++i) {
    std::cin >> current_value;
    vector_n[i] = current_value;
  }

  int64_t left, right;
  int64_t distance_to_left, distance_to_right;
  for (int32_t i = 0; i < k; ++i) {
    std::cin >> current_value;
    auto v = std::lower_bound(vector_n.begin(), vector_n.end(), current_value);
    if (v == vector_n.begin()) {
      std::cout << *v << std::endl;
    } else if (v == vector_n.end()) {
      std::cout << *(--vector_n.end()) << std::endl;
    } else {
      right = *v;
      left = *(--v);

      Diff(current_value, left, distance_to_left);
      Diff(current_value, right, distance_to_right);

      if (distance_to_left == distance_to_right || distance_to_left < distance_to_right) {
        std::cout << left << std::endl;
      } else {
        std::cout << right << std::endl;
      }
    }
  }

  return 0;
}

