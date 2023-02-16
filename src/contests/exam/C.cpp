#include <cstddef>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T>
class Deque {
private:
  std::vector<T> head, tail;

public:
  bool Empty() const {
    return head.empty() && tail.empty();
  }

  size_t Size() const {
    return head.size() + tail.size();
  }

  void Clear() {
    head.clear();
    tail.clear();
  }

  const T& operator [](size_t i) const {
    return i >= head.size() ? tail[i - head.size()] : head[head.size() - i - 1];
  }

  T& operator [](size_t i) {
    return i >= head.size() ? tail[i - head.size()] : head[head.size() - i - 1];
  }

  const T& At(size_t i) const {
    if (i >= Size()) {
      throw std::out_of_range("invalid");
    }
    return (*this)[i];
  }

  T& At(size_t i) {
    if (i >= Size()) {
      throw std::out_of_range("invalid");
    }
    return (*this)[i];
  }

  const T& Front() const {
    return head.empty() ? tail.front() : head.back();
  }

  T& Front() {
    return head.empty() ? tail.front() : head.back();
  }

  const T& Back() const {
    return tail.empty() ? head.front() : tail.back();
  }

  T& Back() {
    return tail.empty() ? head.front() : tail.back();
  }

  void PushFront(const T& elem) {
    head.push_back(elem);
  }

  void PushBack(const T& elem) {
    tail.push_back(elem);
  }
};

