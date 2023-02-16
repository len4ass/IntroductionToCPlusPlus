#include <iostream>
#include <map>
#include <vector>
#include <set>

int main() {
  std::map<int32_t, std::set<std::string>> m;
  int32_t amount;
  std::cin >> amount;

  std::string word;
  int32_t page_number;
  for (int32_t i = 0; i < amount; ++i) {
    std::cin >> word >> page_number;
    if (m.find(page_number) == m.end()) {
      std::set<std::string> s;
      s.insert(word);
      m.insert(std::pair<int32_t, std::set<std::string>>(page_number, s));
      continue;
    }

    auto &set = m[page_number];
    set.insert(word);
  }

  for (const auto &item : m) {
    std::cout << item.first << " ";

    auto &set = item.second;
    auto it = set.begin();
    for (it = set.begin(); it != set.end(); ++it) {
      if (std::distance(it, set.end()) == 1) {
        std::cout << *it << std::endl;
        continue;
      }

      std::cout << *it << " ";
    }
  }

  return 0;
}