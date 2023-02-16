#include <iostream>
#include <list>

void MakeTrain() {
  std::string type;
  int32_t n;
  size_t k;

  std::list<int32_t> l;
  while (std::cin >> type >> n) {
    if (type == "+left") {
      l.push_front(n);
      continue;
    }

    if (type == "+right") {
      l.push_back(n);
    }

    if (type == "-left") {
      k = n;
      if (k > l.size()) {
        l.clear();
        continue;
      }

      for (int32_t i = 0; i < n; ++i) {
        l.pop_front();
      }
    }

    if (type == "-right") {
      k = n;
      if (k > l.size()) {
        l.clear();
        continue;
      }

      for (int32_t i = 0; i < n; ++i) {
        l.pop_back();
      }
    }
  }

  for (const auto& v : l) {
    std::cout << v << " ";
  }

  std::cout << std::endl;
}