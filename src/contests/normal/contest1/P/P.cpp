#include <iostream>
#include <vector>

int main() {
  std::string way;
  int num;

  std::vector<std::string> ways;
  std::vector<int> nums;
  while (std::cin >> way && std::cin >> num) {
    ways.push_back(way);
    nums.push_back(num);
  }

  int l = 0;
  int r = 0;
  for (unsigned long i = 0; i < ways.size(); i++) {
    auto current_way = ways.at(i);
    auto current_num = nums.at(i);

    if (current_way == "North") {
      r += current_num;
    } else if (current_way == "East") {
      l += current_num;
    } else if (current_way == "South") {
      r -= current_num;
    } else if (current_way == "West") {
      l -= current_num;
    }
  }

  std::cout << l << " " << r << std::endl;
  return 0;
}