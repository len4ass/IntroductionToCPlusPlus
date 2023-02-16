#include <iostream>
#include <list>

int main() {
  std::list<int32_t> first;
  std::list<int32_t> second;

  int32_t card;
  for (int32_t i = 0; i < 5; ++i) {
    std::cin >> card;
    first.push_back(card);
  }

  for (int32_t i = 0; i < 5; ++i) {
    std::cin >> card;
    second.push_back(card);
  }

  int32_t count = 0;
  int32_t copy_first, copy_second;
  while (true) {
    if (count == 10e6) {
      std::cout << "botva" << std::endl;
      return 0;
    }

    if (first.empty()) {
      std::cout << "second " << count << std::endl;
      return 0;
    }

    if (second.empty()) {
      std::cout << "first " << count << std::endl;
      return 0;
    }

    copy_first = *(first.begin());
    copy_second = *(second.begin());

    if (copy_first == 0 && copy_second == 9) {
      first.pop_front();
      second.pop_front();

      first.push_back(copy_first);
      first.push_back(copy_second);
      ++count;
      continue;
    }

    if (copy_second == 0 && copy_first == 9) {
      first.pop_front();
      second.pop_front();

      second.push_back(copy_first);
      second.push_back(copy_second);

      ++count;
      continue;
    }

    if (copy_first > copy_second) {
      first.pop_front();
      second.pop_front();

      first.push_back(copy_first);
      first.push_back(copy_second);
      ++count;
      continue;
    }

    if (copy_second > copy_first) {
      first.pop_front();
      second.pop_front();

      second.push_back(copy_first);
      second.push_back(copy_second);
      ++count;
      continue;
    }

    ++count;
  }
}