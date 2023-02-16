#include <iostream>
#include <map>

int main() {
  std::map<int32_t, bool> m;
  int32_t v;
  while (std::cin >> v) {
    if (m.find(v) == m.end()) {
      m.insert(std::pair<int32_t, bool>(v, true));
      std::cout << "NO" << std::endl;
      continue;
    }

    std::cout << "YES" << std::endl;
  }

  return 0;
}