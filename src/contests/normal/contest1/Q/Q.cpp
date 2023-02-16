#include <iostream>

int main() {
  std::string line;
  std::getline(std::cin, line);

  int count = 0;
  for (const auto current_char : line) {
    if (current_char == ' ') {
      count++;
    }
  }

  if (count > 0 || line.size() > 0) {
    count++;
  }

  std::cout << count << std::endl;
  return 0;
}