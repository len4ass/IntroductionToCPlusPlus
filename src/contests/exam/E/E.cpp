#include <iostream>
#include <vector>

template<typename T>
class Table {
private:
  std::vector<std::vector<T>> vec;
public:
  Table(size_t i, size_t j) {
    vec.resize(i);
    for (auto& item : vec) {
      item.resize(j);
    }
  }

  const std::vector<T>& operator[](size_t i) const {
    return vec[i];
  }

  std::vector<T>& operator[](size_t i) {
    return vec[i];
  }

  void resize(size_t i, size_t j) {
    vec.resize(i);
    for (auto& item : vec) {
      item.resize(j);
    }
  }

  std::pair<size_t, size_t> size() const {
    return {vec.size(), vec.empty() ? 0 : vec[0].size()};
  }
};