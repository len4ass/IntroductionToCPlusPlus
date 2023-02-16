#include <vector>
#include <string_view>
#include <iostream>

bool NextToken(std::string_view &sv, const char &delimiter, std::string_view &token) {
  for (size_t i = 0; i < sv.size(); ++i) {
    char c = sv[i];
    if (c == delimiter) {
      token = sv.substr(0, i);
      sv = sv.substr(i + 1);
      return true;
    }

    if (i == sv.size() - 1) {
      token = token = sv.substr(0, i + 1);
      sv = sv.substr(i + 1);
      return true;
    }
  }

  return false;
}