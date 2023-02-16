#include <iostream>
#include <map>

int main() {
  std::map<std::string, std::pair<uint64_t, uint32_t>> m;
  std::string name;
  uint64_t amount, mark;

  std::cin >> amount;
  for (uint32_t i = 0; i < amount; ++i) {
    std::cin >> name >> mark;
    if (m.find(name) == m.end()) {
      m.insert(std::make_pair(name, std::make_pair(mark, 1)));
      std::cout << mark << std::endl;
      continue;
    }

    auto p = m[name];
    auto [sum, mark_amount] = p;
    auto new_sum = sum + mark;
    auto new_mark_amount = mark_amount + 1;
    m[name] = std::make_pair(new_sum, new_mark_amount);

    std::cout << new_sum / new_mark_amount << std::endl;
  }

  return 0;
}