#include <iostream>
#include <vector>

int main() {
  int day, month, year;
  std::cin >> day >> month >> year;

  bool is_bissectus = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

  std::vector<int> feb;
  feb.push_back(0);
  feb.push_back(31);
  feb.push_back(is_bissectus ? 29 : 28);
  feb.push_back(31);
  feb.push_back(30);
  feb.push_back(31);
  feb.push_back(30);
  feb.push_back(31);
  feb.push_back(31);
  feb.push_back(30);
  feb.push_back(31);
  feb.push_back(30);
  feb.push_back(31);

  if (day + 2 <= feb[month]) {
    std::cout << day + 2 << " " << month << " " << year << std::endl;
  } else {
    if (month < 12) {
      if (day + 1 == feb[month]) {
        std::cout << 1 << " " << month + 1 << " " << year << std::endl;
      } else if (day == feb[month]) {
        std::cout << 2 << " " << month + 1 << " " << year << std::endl;
      }
    } else {
      if (day + 1 == feb[month]) {
        std::cout << 1 << " " << 1 << " " << year + 1 << std::endl;
      } else if (day == feb[month]) {
        std::cout << 2 << " " << 1 << " " << year + 1 << std::endl;
      }
    }
  }

  return 0;
}

