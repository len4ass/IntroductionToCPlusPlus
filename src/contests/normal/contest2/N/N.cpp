#include <iostream>
#include <string>
#include <string_view>

bool CheckPalindrome(const std::string_view &str) {
  if (str.empty()) {
    return true;
  }

  for (size_t i = 0; i < str.size() / 2; ++i) {
    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }

  return true;
}

int32_t CountPalindromes(const std::string &str) {
  std::string_view my_str_ptr = str;
  int32_t count = 0;
  size_t pos_start = 0;
  size_t len = 0;

  for (size_t i = 0; i < str.size(); ++i) {
    len++;
    if (str[i] == ' ') {
      if (len == 1) {
        pos_start = i + 1;
        len = 0;
        continue;
      }

      if (CheckPalindrome(my_str_ptr.substr(pos_start, len - 1))) {
        count++;
      }

      pos_start = i + 1;
      len = 0;
      continue;
    }

    if (i == str.size() - 1) {
      if (CheckPalindrome(my_str_ptr.substr(pos_start, len))) {
        count++;
        len = 0;
      }
    }
  }

  return count;
}