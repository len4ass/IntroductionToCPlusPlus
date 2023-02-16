#include <iostream>
#include <vector>

template <typename T>
class MathVector {
private:
  std::vector<T> data;

public:
  explicit MathVector(size_t n) {
    data = std::vector<T>(n);
  }

  template <typename Iter>
  MathVector(Iter first, Iter last) {
    for (; first != last; ++first) {
      data.push_back(*first);
    }
  }

  size_t Dimension() const {
    return data.size();
  }

  T& operator[](size_t i) {
    return data[i];
  }

  const T& operator[](size_t i) const {
    return data[i];
  }
};

template <typename T>
std::ostream& operator <<(std::ostream& out, const MathVector<T>& v) {
  out << '(';
  for (size_t i = 0; i < v.Dimension(); ++i) {
    if (i > 0) {
      out << ", ";
    }
    out << v[i];
  }
  out << ')';

  return out;
}

template <typename T>
MathVector<T>& operator*=(MathVector<T>& v, const T& scalar) {
  for (size_t i = 0; i < v.Dimension(); ++i) {
    v[i] *= scalar;
  }
  return v;
}

template <typename T>
MathVector<T> operator*(const MathVector<T>& v, const T& scalar) {
  MathVector<T> tmp(v.Dimension());
  for (size_t i = 0; i < v.Dimension(); ++i) {
    tmp[i] = v[i] * scalar;
  }
  return tmp;
}

template <typename T>
MathVector<T> operator*(const T& scalar, const MathVector<T>& v) {
  return v * scalar;
}

template <typename T>
MathVector<T> operator+(const MathVector<T>& lhs, const MathVector<T>& rhs) {
  MathVector<T> v(lhs.Dimension());
  for (size_t i = 0; i < lhs.Dimension(); ++i) {
    v[i] = lhs[i] + rhs[i];
  }
  return v;
}
template <typename T>
MathVector<T>& operator+=(MathVector<T>& lhs, const MathVector<T>& rhs) {
  lhs = lhs + rhs;
  return lhs;
}