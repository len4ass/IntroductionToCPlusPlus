#include <iostream>
#include <map>
#include <vector>

int main() {
  int32_t n, k;
  std::cin >> n >> k;
  std::string s;

  size_t new_k = k;
  std::map<std::string, int32_t> m;
  for (int32_t j = 0; j < n; ++j) {
    std::cin >> s;
    if (new_k > s.size()) {
      continue;
    }

    if (s.size() == new_k) {
      auto& ref = m[s];
      ++ref;
      continue;
    }

    std::string sb;
    for (size_t i = 0; i < s.size(); ++i) {
      if (i + new_k > s.size()) {
        break;
      }

      sb = s.substr(i, k);
      auto& rf = m[sb];
      ++rf;
    }
  }

  std::vector<std::pair<std::string, int32_t>> v;
  for (const auto& item : m) {
    v.emplace_back(item.first, item.second);
  }

  std::sort(v.begin(), v.end(),
            [](const std::pair<std::string, int32_t>& lhs, const std::pair<std::string, int32_t>& rhs) {
              if (lhs.second == rhs.second) {
                return lhs.first < rhs.first;
              }

              return lhs.second > rhs.second;
            });

  for (const auto& item : v) {
    std::cout << item.first << " - " << item.second << std::endl;
  }
  return 0;
}