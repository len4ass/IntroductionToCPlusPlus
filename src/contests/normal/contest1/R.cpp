#include <iostream>
#include <vector>

long long sum(std::vector<long long> &vec) {
  long long s = 0;
  for (const auto num : vec) {
    s += num;
  }

  return s;
}

long long max(std::vector<long long> &vec) {
  long long max = std::numeric_limits<long long>::min();
  for (const auto num : vec) {
    if (num > max) {
      max = num;
    }
  }

  return max;
}

long long min(std::vector<long long> &vec) {
  long long min = std::numeric_limits<long long>::max();
  for (const auto num : vec) {
    if (num < min) {
      min = num;
    }
  }

  return min;
}

void confuse_array(std::vector<long long> &vec) {
  long long s = sum(vec);
  for (long long & i : vec) {
    long num = i;
    i = s - num;
  }
}

int main() {
  int amount, confuse;
  std::cin >> amount;
  std::cin >> confuse;

  std::vector<long long> num_vec;
  for (int i = 0; i < amount; i++) {
    long long num;
    std::cin >> num;
    num_vec.push_back(num);
  }

  for (int i = 0; i < confuse; i++) {
    confuse_array(num_vec);
  }

  long long max_v = max(num_vec);
  long long min_v = min(num_vec);
  std::cout << max_v - min_v << std::endl;
}