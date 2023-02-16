#include <string>

std::string CommonSuffix(const std::string& a, const std::string& b) {
  std::string n = "";

  for (int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j) {
    if (a[i] == b[j]) {
      n = a[i] + n;
    } else {
      break;
    }
  }

  return n;
}