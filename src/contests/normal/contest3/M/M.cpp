#include <iostream>
#include <list>

int main() {
  std::list<std::string> q;
  std::string surname, position;

  int32_t student_amount;
  std::cin >> student_amount;
  for (int32_t i = 0; i < student_amount; ++i) {
    std::cin >> surname >> position;
    if (position == "top") {
      q.push_front(surname);
    } else if (position == "bottom") {
      q.push_back(surname);
    }
  }

  std::cin >> student_amount;
  int32_t index;
  for (int32_t i = 0; i < student_amount; ++i) {
    std::cin >> index;
    auto it = std::next(q.begin(), index - 1);
    std::cout << *it << std::endl;
  }

  return 0;
}