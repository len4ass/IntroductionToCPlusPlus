#include <vector>

std::vector<int> Range(const std::vector<int>& v, size_t start, size_t end, size_t step = 1) {
  std::vector<int> new_v(0);
  if (start >= v.size() || start >= end) {
    return new_v;
  }

  for (size_t i = start; i < end; i += step) {
    if (i >= end || i < start || i >= v.size()) {
      break;
    }
    new_v.push_back(v[i]);
  }
  return new_v;
}