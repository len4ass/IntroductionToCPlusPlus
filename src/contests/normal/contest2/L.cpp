#include <vector>
#include <string>
std::pair<size_t, size_t> FindVowels(std::string &text, size_t position) {
  size_t start = -1;
  size_t len = 0;
  std::vector<char> chars = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
  bool found = false;
  std::string current = "";
  for (size_t i = position; i < text.size(); ++i) {
    if (!found) {
      char f;
      for (const auto c : chars) {
        if (text[i] == c) {
          f = c;
          start = i;
          len = 1;
          found = true;
          break;
        }
      }
      if (found) {
        current += f;
      }
    } else {
      bool f = false;
      for (const auto c : chars) {
        if (text[i] == c) {
          current += c;
          len++;
          f = true;
          break;
        }
      }
      if (!f) {
        break;
      }
    }
  }
  return std::pair(start, len);
}