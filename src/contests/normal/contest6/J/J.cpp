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
    if (Degree() == rhs.Degree()) {
      int32_t d = Degree() + 1;
      for (size_t i = 0; i < static_cast<size_t>(d); ++i) {
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

  T operator()(const T& v) const {
    T sum = T();
    T current_v = T(1);
    for (size_t i = 0; i < c.size(); ++i) {
      if (i == 0) {
        sum += c[i];
      } else {
        current_v *= v;
        sum += c[i] * current_v;
      }
    }
    return sum;
  }

  Polynomial operator&(const Polynomial& rhs) const {
    Polynomial a(c[c.size() - 1]);
    for (size_t i = c.size() - 2; i != std::numeric_limits<size_t>::max(); --i) {
      a *= rhs;
      a.c[0] += c[i];
    }

    return a;
  }

  Polynomial operator*(const Polynomial& rhs) const {
    std::vector<T> cf(c.size() + rhs.c.size() - 1);
    for (size_t i = 0; i < c.size(); ++i) {
      for (size_t j = 0; j < rhs.c.size(); ++j) {
        cf[i + j] += c[i] * rhs.c[j];
      }
    }

    return {cf};
  }

  Polynomial& operator*=(const Polynomial& rhs) {
    std::vector<T> cf(c.size() + rhs.c.size() - 1);
    for (size_t i = 0; i < c.size(); ++i) {
      for (size_t j = 0; j < rhs.c.size(); ++j) {
        cf[i + j] += c[i] * rhs.c[j];
      }
    }

    c.clear();
    c = cf;
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

  friend std::ostream& operator<<(std::ostream& output, const Polynomial& rhs) {
    T zero = T(0);
    T one = T(1);
    T minus_one = T(-1);
    int32_t degree = rhs.Degree();
    if (degree == -1) {
      output << 0;
      return output;
    }

    for (size_t i = static_cast<size_t>(degree); i != std::numeric_limits<size_t>::max(); --i) {
      if (rhs.c[i] == zero) {
        output << "";
      } else if (rhs.c[i] == one) {
        if (i == static_cast<size_t>(degree)) {
          if (i == 0) {
            output << rhs.c[i];
          } else if (i == 1) {
            output << "x";
          } else {
            output << "x^" << i;
          }
        } else {
          if (i == 0) {
            output << "+" << rhs.c[i];
          } else if (i == 1) {
            output << "+x";
          } else {
            output << "+x^" << i;
          }
        }
      } else if (rhs.c[i] == minus_one) {
        if (i == static_cast<size_t>(degree)) {
          if (i == 0) {
            output << rhs.c[i];
          } else if (i == 1) {
            output << "-x";
          } else {
            output << "-x^" << i;
          }
        } else {
          if (i == 0) {
            output << rhs.c[i];
          } else if (i == 1) {
            output << "-x";
          } else {
            output << "-x^" << i;
          }
        }
      } else {
        if (rhs.c[i] > zero) {
          if (i == static_cast<size_t>(degree)) {
            if (i == 0) {
              output << rhs.c[i];
            } else if (i == 1) {
              output << rhs.c[i] << "*x";
            } else {
              output << rhs.c[i] << "*x^" << i;
            }
          } else {
            if (i == 0) {
              output << "+" << rhs.c[i];
            } else if (i == 1) {
              output << "+" << rhs.c[i] << "*x";
            } else {
              output << "+" << rhs.c[i] << "*x^" << i;
            }
          }
        } else {
          if (i == 0) {
            output << rhs.c[i];
          } else if (i == 1) {
            output << rhs.c[i] << "*x";
          } else {
            output << rhs.c[i] << "*x^" << i;
          }
        }
      }
    }
    return output;
  }
};