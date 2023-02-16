#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter) {
  std::vector<std::string> vector(0);
  if (str == "") {
    return vector;
  }

  std::string current_sub = "";
  for (const auto c : str) {
    if (c == delimiter) {
      vector.push_back(current_sub);
      current_sub = "";
    } else {
      current_sub += c;
    }
  }
  vector.push_back(current_sub);
  return vector;
}