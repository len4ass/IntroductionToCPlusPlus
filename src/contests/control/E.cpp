#include <iostream>

std::string ToBin(int64_t v) {
  std::string s = "";
  if (v == 0) {
    return "0";
  }

  while (v > 0) {
    s = std::to_string(v % 2) + s;
    v /= 2;
  }

  return s;
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::string new_str = "";
  std::string conv = "";
  int64_t nums;

  for (size_t i = 0; i < s.size(); ++i) {
    char ch = s[i];
    if (ch >= 48 && ch <= 57) {
      conv += ch;

      if (i == s.size() - 1) {
        nums = std::stoll(conv);
        new_str += ToBin(nums);
        conv = "";
      }
    } else {
      if (!conv.empty()) {
        nums = std::stoll(conv);
        new_str += ToBin(nums);
        conv = "";
      }

      new_str += ch;
    }
  }

  std::cout << new_str << std::endl;
  return 0;
}