#include <iostream>
#include <vector>

template <typename T>
class Polynomial {
  std::vector<T> c;

public:
  using iterator = typename std::vector<T>::const_iterator;

  Polynomial() {
    c.push_back(T());
  }

  Polynomial(const std::vector<T>& new_c) {
    c = std::vector<T>(new_c.size());
    for (size_t i = 0; i < new_c.size(); ++i) {
      c[i] = new_c[i];
    }
  }

  Polynomial(T v) {
    c.push_back(v);
  }

  template<typename Iter>
  Polynomial(Iter first, Iter last) {
    while (first != last) {
      c.push_back(*first);
      ++first;
    }
  }

  bool operator==(const Polynomial& rhs) const {
    if (c.size() == rhs.c.size()) {
      for (size_t i = 0; i < c.size(); ++i) {
        if (c[i] != rhs.c[i]) {
          return false;
        }
      }

      return true;
    }

    return false;
  }

  bool operator!=(const Polynomial& rhs) const {
    return !operator==(rhs);
  }

  Polynomial operator+(const Polynomial& rhs) const {
    Polynomial n(c);
    if (c.size() < rhs.c.size()) {
      n.c.resize(rhs.c.size());
    }

    for (size_t i = 0; i < rhs.c.size(); ++i) {
      n.c[i] += rhs.c[i];
    }

    return n;
  }

  Polynomial& operator+=(const Polynomial& rhs) {
    if (c.size() < rhs.c.size()) {
      c.resize(rhs.c.size());
    }

    for (size_t i = 0; i < rhs.c.size(); ++i) {
      c[i] += rhs.c[i];
    }

    return *this;
  }

  Polynomial operator-(const Polynomial& rhs) const {
    Polynomial n(c);
    if (c.size() < rhs.c.size()) {
      n.c.resize(rhs.c.size());
    }

    for (size_t i = 0; i < rhs.c.size(); ++i) {
      n.c[i] -= rhs.c[i];
    }

    return n;
  }

  Polynomial& operator-=(const Polynomial& rhs)  {
    if (c.size() < rhs.c.size()) {
      c.resize(rhs.c.size());
    }

    for (size_t i = 0; i < rhs.c.size(); ++i) {
      c[i] -= rhs.c[i];
    }

    return *this;
  }

  T operator[](size_t id) const {
    if (id >= c.size()) {
      return T();
    }

    return c[id];
  }

  int32_t Degree() const {
    int32_t degree = -1;
    for (size_t i = c.size() - 1; i != std::numeric_limits<size_t>::max(); --i) {
      if (c[i] != T()) {
        degree = i;
        break;
      }
    }

    return degree;
  }

  iterator begin() const {
    return c.begin();
  }

  iterator end() const {
    for (size_t i = c.size() - 1; i != std::numeric_limits<size_t>::max(); --i) {
      if (c[i] != T()) {
        return c.begin() + i + 1;
      }
    }

    return c.begin();
  }
};