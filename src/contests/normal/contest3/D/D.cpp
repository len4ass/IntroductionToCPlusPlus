#include <iostream>
#include <vector>
#include <set>
#include <map>

int main() {
  int32_t word_count = 0;
  std::string word;
  std::map<char, int32_t> m;

  while (std::cin >> word) {
    if (word_count == 1000) {
      break;
    }

    std::set<char> chars;
    for (auto c : word) {
      chars.insert(c);
    }

    for (auto k : chars) {
      if (m.find(k) == m.end()) {
        m.insert(std::make_pair(k, 1));
        continue;
      }

      m[k] = m[k] + 1;
    }

    ++word_count;
  }

  for (const auto v : m) {
    if (v.second == word_count) {
      std::cout << v.first;
    }
  }
  return 0;
}