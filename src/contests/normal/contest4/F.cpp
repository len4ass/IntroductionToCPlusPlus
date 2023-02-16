#include <algorithm>
#include <vector>

void delete_zeroes(std::vector<int>& numbers) {
  auto iter = std::remove_if(numbers.begin(), numbers.end(), [](int32_t x) {
    return x == 0;
  });

  numbers.erase(iter, numbers.end());
}